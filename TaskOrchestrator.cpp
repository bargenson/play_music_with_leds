#include <Arduino.h>
#include <unordered_map>
#include "TaskOrchestrator.h"

TaskOrchestrator::TaskOrchestrator(std::unordered_map<int, TaskExecutor> scheduledTasks)
  : scheduledTasks(scheduledTasks) {
  for (auto& task : scheduledTasks) {
    lastExecutionTimes[task.first] = 0;
  }
}

void TaskOrchestrator::run() {
  unsigned long currentTime = millis();
  for (auto& task : scheduledTasks) {
    if (currentTime - lastExecutionTimes[task.first] >= task.first) {
      task.second();
      lastExecutionTimes[task.first] = currentTime;
    }
  }
}
