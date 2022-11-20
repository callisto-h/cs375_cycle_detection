#include "LL.h"
#include <chrono>
#include <iostream>
#include <string>

//function to start timer
std::chrono::time_point<std::chrono::system_clock> start_timer(){
    return std::chrono::system_clock::now();
}

//function to end timer
double end_timer(std::chrono::time_point<std::chrono::system_clock> start){
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count();
}

int main(int argc, char *argv[]){

    auto timer = start_timer(); // timer start

    std::cout << "Floyd's Algorithm: " << std::endl;

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

    std::cout << "Linear Cylce Detection Algorithm: " << std::endl;

    LL l5;
    l5.append_n_nodes_ascending(10);
    l5.create_cycle(2);
    l5.print_partial_list(5, 9);
    std::string l5_cycle = (l5.linear_cycle_detection() ? "True" : "False");
    std::cout << "L5 Cycle: " << l5_cycle << std::endl;

    LL l6;
    l6.append_n_nodes_ascending(100);
    l5.print_list();
    std::string l6_cycle = (l6.linear_cycle_detection() ? "True" : "False");
    std::cout << "L6 Cycle: " << l6_cycle << std::endl;

    std::cout << "Brent's Algorithm: " << std::endl;

    LL l7;
    l7.append_n_nodes_ascending(25);
    l7.create_cycle(5);
    l7.print_partial_list(5,24);
    std::string l7_cycle = (l7.brent_cylce_detection() ? "True" : "False");
    std::cout << "L7 Cycle: " << l7_cycle << std::endl;

    LL l8;
    l8.append_n_nodes_ascending(100);
    l8.print_partial_list(5,99);
    std::string l8_cycle = (l8.brent_cylce_detection() ? "True" : "False");
    std::cout << "L8 Cycle: " << l8_cycle << std::endl;

    LL l9;
    l9.append(0);
    l9.print_list();
    std::string l9_cycle = (l9.brent_cylce_detection() ? "True" : "False");
    std::cout << "L9 Cycle: " << l9_cycle << std::endl;

    LL l10;
    l10.print_list();
    std::string l10_cycle = (l10.brent_cylce_detection() ? "True" : "False");
    std::cout << "L10 Cycle: " << l10_cycle << std::endl;

    auto elapsed = end_timer(timer); // timer end

    std::cout << "Elapsed Time: " << elapsed << " seconds" << std::endl;

    return 0;
}