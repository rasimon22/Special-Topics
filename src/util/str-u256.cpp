#ifndef TYPECONV
#define TYPECONV
#include <string>
#include <vector>
#include "../primitives/picosha2.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "../../uint256_t/uint256_t.h"
using namespace std;

uint256_t str_to_uint256(std::string input_str) {
unsigned long long hash_comp[4];
    //assign 64 bit components of 256 bit hash (unsigned long long)
    hash_comp[3] = std::strtoull(input_str.substr(0, (int)(64/4)).c_str(), 0, 16); 
    hash_comp[2] = std::strtoull(input_str.substr((int)(64/4)-1, (int)(64/4)).c_str(), 0, 16);
    hash_comp[1] = std::strtoull(input_str.substr((int)(64/2)-1, (int)(64/4)).c_str(), 0, 16);
    hash_comp[0] = std::strtoull(input_str.substr((int)(3*64/4)-1, (int)(64/4)).c_str(), 0, 16);
    uint256_t out_hash;
    for(int i = 0; i < 4; i++) {
        out_hash += uint256_t(hash_comp[i]) << (64*i);
    }
    return out_hash;
}

#endif
