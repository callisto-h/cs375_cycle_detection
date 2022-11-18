#include <chrono>
#include <iostream>
#include <string>

#include "LL.h"

// function to start timer
std::chrono::time_point<std::chrono::system_clock> start_timer() {
  return std::chrono::system_clock::now();
}

// function to end timer
double end_timer(std::chrono::time_point<std::chrono::system_clock> start) {
  std::chrono::time_point<std::chrono::system_clock> end =
      std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  return elapsed_seconds.count();
}

enum class CycleDetectionAlgorithm { Floyd, Brent, Linear };

// test function for any of the cycle detection algorithms
bool test_cycle_detection(LL &l, CycleDetectionAlgorithm algorithm) {
  // print name of LL
  std::cout << l.get_name() << std::endl;
  auto timer = start_timer();
  bool cycle = false;
  switch (algorithm) {
    case CycleDetectionAlgorithm::Floyd:
      cycle = l.floyd_cycle_detection();
    case CycleDetectionAlgorithm::Brent:
      cycle = l.brent_cycle_detection();
    case CycleDetectionAlgorithm::Linear:
      cycle = l.linear_cycle_detection();
  }

  double elapsed_time = end_timer(timer);
  std::cout << "Cycle: " << (cycle ? "True" : "False") << std::endl;
  std::cout << "Elapsed Time: " << elapsed_time << std::endl;
  return cycle;
}

int main(int argc, char *argv[]) {
  LL l1 = LL("l1");
  l1.append_n_nodes_ascending(10);
  test_cycle_detection(l1, CycleDetectionAlgorithm::Floyd);
  l1.print_list();
  std::cout << std::endl;

  LL l2 = LL("l2");
  l2.append_n_nodes_ascending(10000);
  l2.create_cycle();
  test_cycle_detection(l2, CycleDetectionAlgorithm::Floyd);
  l2.print_partial_list(5, 9995);
  std::cout << std::endl;

  LL l3 = LL("l3");
  l3.append_n_nodes_ascending(100);
  test_cycle_detection(l3, CycleDetectionAlgorithm::Brent);
  l3.print_list();
  std::cout << std::endl;

  LL l4 = LL("l4");
  l4.append_n_nodes_ascending(100);
  l4.create_cycle(75);
  test_cycle_detection(l4, CycleDetectionAlgorithm::Brent);
  l4.print_partial_list(5, 95);
  std::cout << std::endl;

  LL l5 = LL("l5");
  l5.append_n_nodes_ascending(10);
  l5.create_cycle(2);
  test_cycle_detection(l5, CycleDetectionAlgorithm::Linear);
  l5.print_partial_list(5, 9);
  std::cout << std::endl;

  LL l6 = LL("l6");
  l6.append_n_nodes_ascending(100);
  test_cycle_detection(l6, CycleDetectionAlgorithm::Linear);
  l6.print_list();
  std::cout << std::endl;

  return 0;
}