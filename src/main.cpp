//#include <mpi.h>
#include "primitives/Block.h"
#include "primitives/STransaction.h"
#include "../uint256_t/uint256_t.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "util/str-u256.cpp"
int main(int argc, char** argv){
    vector<uint256_t> vec;
    for(int i = 0; i < 10000; i++) {
       vec.push_back(uint256_t(rand()));
    }
    SBlock b = SBlock(vec, uint256_t(rand()));
    b.hashData();
    for(int i = 0; i < 100; i++) {
        b.incrementNonce();
    }


    return 0;
}
