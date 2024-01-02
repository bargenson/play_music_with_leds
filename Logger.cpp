#include "Logger.h"

Logger::Logger(int baudRate) : baudRate(baudRate) {}

void Logger::println(String message) {
  Serial.println(message);
}

void Logger::println() {
  println("");
}

void Logger::print(String message) {
  Serial.print(message);
}
