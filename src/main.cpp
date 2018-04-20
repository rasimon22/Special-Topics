//#include <mpi.h>
#include "primitives/Block.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

int main(int argc, char** argv){
    vector<int> vec;
    for(int i = 0; i < 100000; i++){
        vec.push_back(i);
    }
    SBlock b = SBlock(vec, 0);
    b.hashData();
    std::cout << b.hash << std::endl;

    return 0;
}
