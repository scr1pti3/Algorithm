#include "Process.cxx"
#include "tool.cxx"
#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>

float Process::get_wait_time() const { return start_time - arrival_time; }

int main() {
  // Psuedo Processes
  Process P1{12.0f, 0.0f};
  Process P2{4.0f, 3.0f};
  Process P3{9.0f, 5.0f};
  Process P4{2.0f, 7.0f};

  std::vector<std::reference_wrapper<Process>> processes{P1, P2, P3, P4};
  std::vector<float> wait_times;

  // Sort the processes by arrival_time
  std::sort(processes.begin(), processes.end(), [&](Process a, Process b) {
    return a.get_arrival_time() < b.get_arrival_time();
  });

  float time_accumulator = 0;
  for (auto &&p_ref_wrap : processes) {
    // unwrap reference_wrapper
    Process &p = p_ref_wrap.get();

    // allocate start time offset
    p.start_time = time_accumulator;

    // Run process till finish
    while (p.get_execution_time() < p.get_burst_time()) {
      ++time_accumulator;
      p.execute();
    }

    wait_times.push_back(p.get_wait_time());
  }

  std::cout << get_average(wait_times) << std::endl;

  return 0;
}
