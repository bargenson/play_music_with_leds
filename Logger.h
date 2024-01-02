#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

class Logger {
public:
  Logger(int baudRate);

  void println(String message);
  void println();
  void print(String message);

private:
  int baudRate;
};

#endif