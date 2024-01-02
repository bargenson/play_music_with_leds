#ifndef CONFIG_H
#define CONFIG_H

const int baudRate = 9600;

const int pin_led = 0;
const int pin_button = 1;
const int pin_sound = 2;
const int pin_ledStrip = 3;
const int pin_buzzer = 4;

const long noiseDurationThreshold = 2000;
const long silenceDurationThreshold = 1500;
const int noisePercentageThreshold = 20;

const char wifi_ssid[] = "TARDIS_NETWORK";
const char wifi_password[] = "L@NouvLWP2020";
const int wifi_retryDelay = 1000;

#endif
