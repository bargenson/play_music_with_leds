#include "Logger.h"

Logger::Logger(int baudRate) {
  Logger(baudRate, INFO);
}

Logger::Logger(int baudRate, LogLevel logLevel) : baudRate(baudRate), logLevel(logLevel) {}

void Logger::println(String message) {
  Serial.println(message);
}

void Logger::println(String message, LogLevel logLevel) {
  if (this->logLevel >= logLevel) {
    println(message);
  }
}

void Logger::println() {
  println("");
}

void Logger::print(String message) {
  Serial.print(message);
}

void Logger::print(String message, LogLevel logLevel) {
  if (this->logLevel >= logLevel) {
    print(message);
  }
}
