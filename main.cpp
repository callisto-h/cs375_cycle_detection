#include "LL.h"
#include <iostream>
#include <string>

#define ONE_HUN_MIL 100000000
#define FIFTY_MIL 50000000
#define TEN_MIL 10000000
#define ONE_MIL 1000000

/**
 * @brief handles all the testing for the cycle
 * detection algorithms
 *
 * @param size size of the LL to create
 * @param algs which algs to run. accepts a string of
 * characters representing:
 * 'l' = linear
 * 'f' = floyd
 * 'b' = brent
 * 'n' = linear no map
 * can leave blank for all algs, but since linear
 * takes the longest we may omit it in some tests
 * @param cycle whether or not to include a cycle
 * @param cycle_location what location the cycle
 * should point to in the LL
 */
void do_tests(int size, std::string algs="lfbn",
            bool cycle=false, int cycle_location=0){

    std::cout <<"=========[Running test(s)]==========" << std::endl;
    std::cout << "[Size : " << size << "]";
    std::cout << "[Algs : " << algs << "]";
    std::cout << "[Cycle : " << cycle << "]";
    std::cout << "[Cycle Location : " << cycle_location << "]" << std::endl;


    LL *l = new LL();
    l->append_n_nodes_ascending(size);

    if(cycle){
        l->create_cycle(cycle_location);
    }

    if(algs.find("l") != std::string::npos){
        l->do_cycle_detection(1); // linear
    }
    if(algs.find("f") != std::string::npos){
        l->do_cycle_detection(2); // floyd
    }
    if(algs.find("b") != std::string::npos){
        l->do_cycle_detection(3); // brent
    }
    if (algs.find("n") != std::string::npos)
    {
        l->do_cycle_detection(4); // linear
    }
    std::cout << std::endl;

    delete l;
}


int main(int argc, char *argv[]){

    //Acyclic tests
    // do_tests(1);
    // do_tests(100);
    // do_tests(10000);
    // do_tests(ONE_MIL);
    // do_tests(TEN_MIL, "fbn");
    // do_tests(FIFTY_MIL, "fbn");
    // do_tests(ONE_HUN_MIL, "fbn");

    //Cyclic tests ONE_MIL
    do_tests(ONE_MIL, "lbfn", true, 0); // cycle to beginning
    do_tests(ONE_MIL, "lbfn", true, ONE_MIL - 1); // cycle to end
    do_tests(ONE_MIL, "lbfn", true, ONE_MIL / 2); // cycle to midway
    do_tests(ONE_MIL, "lbfn", true, (ONE_MIL / 2) + 1); // cycle to midway + 1

    // // Cyclic tests ONE_HUN_MIL (no linear)
    do_tests(ONE_HUN_MIL, "bfn", true, 0);                 // cycle to beginning
    do_tests(ONE_HUN_MIL, "bfn", true, ONE_HUN_MIL - 1);   // cycle to end
    do_tests(ONE_HUN_MIL, "bfn", true, ONE_HUN_MIL / 2);   // cycle to midway
    do_tests(ONE_HUN_MIL, "bfn", true, (ONE_HUN_MIL / 2) + 1); // cycle to midway + 1

    return 0;
}
