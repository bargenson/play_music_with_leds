#include <unordered_map>
#include <CircularBuffer.h>
#include <Adafruit_NeoPixel.h>
#include "Config.h"
#include "Logger.h"
#include "TaskOrchestrator.h"
#include "melodies.h"

TaskOrchestrator* orchestrator;
Logger logger(baudRate, LogLevel::DEBUG);

CircularBuffer<int, 100> lastNoiseDetections;
boolean active;
long firstNoiseThresholdReachedTime = -1;
long lastNoiseThresholdReachedTime = -1;
Adafruit_NeoPixel strip(150, pin_ledStrip, NEO_GRB + NEO_KHZ800);

void setup() {
  std::unordered_map<int, TaskOrchestrator::TaskExecutor> scheduledTasks;
  scheduledTasks[0] = listenNoise;
  scheduledTasks[200] = listenButton;
  scheduledTasks[60000] = logStats;
  orchestrator = new TaskOrchestrator(scheduledTasks);

  pinMode(pin_led, OUTPUT);
  pinMode(pin_button, INPUT_PULLUP);
  pinMode(pin_sound, INPUT);
  pinMode(pin_ledStrip, OUTPUT);

  strip.begin();

  deactivate();
}

void loop() {
  orchestrator->run();
}

void listenButton() {
  if (isButtonPressed()) {
    logger.println(F("Button pressed"), LogLevel::DEBUG);
    if (isActive()) {
      deactivate();
    } else {
      activate();
    }
  }
}

extern "C" char* sbrk(int incr);
int freeRam() {
  char top;
  return &top - reinterpret_cast<char*>(sbrk(0));
}

void logStats() {
  logger.println("========== Stats ==========");
  logger.println("SRAM left: " + String(freeRam()));
  logger.println("Active: " + String(isActive()));
  logger.println("First noise threshold reached time: " + String(firstNoiseThresholdReachedTime));
  logger.println("Last noise threshold reached time: " + String(lastNoiseThresholdReachedTime));
  logger.println("===========================");
}

boolean isButtonPressed() {
  return digitalRead(pin_button) == LOW;
}

boolean isActive() {
  return active;
}

void activate() {
  active = true;
  turnOnLed();
  firstNoiseThresholdReachedTime = -1;
}

void turnOnLed() {
  digitalWrite(pin_led, HIGH);
}

void turnOffLed() {
  digitalWrite(pin_led, LOW);
}

void deactivate() {
  active = false;
  turnOffLed();
  strip.clear();
  strip.show();
}

void listenNoise() {
  if (isActive()) {
    if (detectNoise()) {
      Melody melody = melodies[random(0, 3)];
      playMusic(melody);
    }
  }
}

void playMusic(Melody melody) {
  long nextPixelHue = rainbow(0);

  int numberOfNotes = melody.notes.size() / 2;

  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / melody.tempo;

  int divider = 0, noteDuration = 0;

  // iterate over the notes of the melody. 
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < numberOfNotes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody.notes[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(pin_buzzer, melody.notes[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(pin_buzzer);

    nextPixelHue = rainbow(melody.notes[thisNote]);
  }

  strip.clear();
  strip.show();
}

long rainbow() {
  return rainbow(0);
}

long rainbow(long firstPixelHue) {
  for (int i = 0; i < strip.numPixels(); i++) {
    int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
    strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
  }
  strip.show();

  return firstPixelHue + 256;
}

boolean detectNoise() {
  int lastRead = digitalRead(pin_sound);
  lastNoiseDetections.push(lastRead);
  if (lastNoiseDetections.isFull()) {
    unsigned long currentTime = millis();
    float sum = 0;
    for (int i = 0; i < lastNoiseDetections.size(); i++) {
      sum += lastNoiseDetections[i];
    }
    float noisePercentage = 100 - sum;
    logger.println("Percentage: " + String(noisePercentage), LogLevel::DEBUG);
    if (noisePercentage >= noisePercentageThreshold) {
      logger.println(F("Noise threshold reached"));
      lastNoiseThresholdReachedTime = currentTime;
      if (firstNoiseThresholdReachedTime == -1) {
        firstNoiseThresholdReachedTime = currentTime;
      } else {
        if (lastNoiseThresholdReachedTime - firstNoiseThresholdReachedTime > noiseDurationThreshold) {
          logger.println(F("Long noise detected"));
          firstNoiseThresholdReachedTime = -1;
          return true;
        }
      }
    } else {
      if (firstNoiseThresholdReachedTime != -1 && currentTime - lastNoiseThresholdReachedTime > silenceDurationThreshold) {
        logger.println(F("Silence detected"));
        firstNoiseThresholdReachedTime = -1;
      }
    }
  }
  return false;
}
