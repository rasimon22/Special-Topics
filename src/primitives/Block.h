#ifndef SMU_PRIMITIVES_BLOCK_H
#define SMU_PRIMITIVES_BLOCK_H
using namespace std;
#include <vector>
#include <string>
#include "picosha2.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "../../uint256_t/uint256_t.h"
#include "../util/str-u256.cpp"
class SBlock {
    public:
        
        uint256_t hash;
        int prevHash;
        int nonce;
        
        std::vector<int> tx;
        SBlock();
        SBlock(std::vector<int>& data, int prevHash);
        void hashData();

};

#endif //SMU_PRIMITIVES_BLOCK_H
