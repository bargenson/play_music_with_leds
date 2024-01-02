#ifndef TASK_ORCHESTRATOR_H
#define TASK_ORCHESTRATOR_H

#include <Arduino.h>
#include <functional>
#include <unordered_map>

class TaskOrchestrator {
public:
  using TaskExecutor = std::function<void()>;

  TaskOrchestrator(std::unordered_map<int, TaskExecutor> scheduledTasks);

  void run();

private:
  std::unordered_map<int, TaskExecutor> scheduledTasks;
  std::unordered_map<int, unsigned long> lastExecutionTimes;
};

#endif
