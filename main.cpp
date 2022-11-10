#include "LL.h"
#include <chrono>
#include <iostream>

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

    LL l2;
    l2.append_n_nodes_ascending(10000);
    l2.create_cycle(5000);
    l2.print_partial_list(5, 9995);

    LL l3;
    l3.append(0);
    l3.create_cycle();
    l3.print_list();

    auto elapsed = end_timer(timer); // timer end

    std::cout << "Time taken: " << elapsed.count() << " ms" << std::endl;

    return 0;
}