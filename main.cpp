#include "LL.h"
#include <chrono>
#include <iostream>
#include <string>

auto start_timer(){
    return std::chrono::high_resolution_clock::now();
}

auto end_timer(auto &timer){
    auto end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end_time - timer);
}





int main(int argc, char *argv[]){

    auto timer = start_timer(); // timer start

    LL l1;
    l1.append_n_nodes_ascending(10);
    l1.print_list();
    std::string l1_cycle = (l1.floyd_cycle_detection() ? "True" : "False");
    std::cout << "L1 Cycle: " << l1_cycle << std::endl;

    LL l2;
    l2.append_n_nodes_ascending(10000);
    l2.create_cycle();
    l2.print_partial_list(5, 9995);
    std::string l2_cycle = (l2.floyd_cycle_detection() ? "True" : "False");
    std::cout << "L2 Cycle: " << l2_cycle << std::endl;


    LL l3;
    l3.append(0);
    l3.create_cycle();
    l3.print_list();
    std::string l3_cycle = (l3.floyd_cycle_detection() ? "True" : "False");
    std::cout << "L3 Cycle: " << l3_cycle << std::endl;

    LL l4;
    l4.append_n_nodes_ascending(100);
    l4.create_cycle(75);
    l4.print_partial_list(5, 95);
    std::string l4_cycle = (l4.floyd_cycle_detection() ? "True" : "False");
    std::cout << "L4 Cycle: " << l4_cycle << std::endl;


    auto elapsed = end_timer(timer); // timer end

    std::cout << "Time taken: " << elapsed.count() << " ms" << std::endl;

    return 0;
}