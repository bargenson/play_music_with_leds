#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

enum LogLevel {
  INFO,
  DEBUG
};

class Logger {
public:
  Logger(int baudRate);
  Logger(int baudRate, LogLevel logLevel);

  void println();
  void println(String message);
  void println(String message, LogLevel logLevel);
  void print(String message);
  void print(String message, LogLevel logLevel);

private:
  int baudRate;
  LogLevel logLevel;
};

#endif