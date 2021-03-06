#ifndef PROCESS_CXX
#define PROCESS_CXX
#include <string>
#include <string_view>

// Process structure
class Process {
  // The approximate execution time known by the CPU
  std::string name;
  float burst_time;
  float arrival_time;

  // Runtime execution time.
  //  Will be incremented at runtime.
  float execution_time{0.0f};

public:
  float start_time{0.0f};
  float stop_time{0.0f};

  Process(std::string_view p_name, float p_burst_time = 0.0f,
          float p_arrival_time = 0.0f)
      : name{p_name}, burst_time{p_burst_time}, arrival_time{p_arrival_time} {}

  // Getter
  std::string_view get_name() const { return name; }

  float get_burst_time() const { return burst_time; }

  float get_arrival_time() const { return arrival_time; }

  float get_execution_time() const { return execution_time; }

  float get_completion_time() const {
    return execution_time + arrival_time + get_wait_time();
  }

  float get_turnaround_time() const {
    return get_completion_time() - arrival_time;
  }

  // Implementation define
  float get_wait_time() const;

  // Execute next instruction like a iterator.
  void execute() { ++execution_time; }
};

#endif // PROCESS_CXX
