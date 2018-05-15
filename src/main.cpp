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
    std::vector<int> vec;
    for(int i = 0; i < 100000; i++){
        vec.push_back(rand());
    }
    SBlock b = SBlock(vec, 0);
    vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(vec.begin(), vec.end(), hash.begin(), hash.end());
    std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(),hash.end());
    std::cout<< hex_str << std::endl;
    //hashing block data, printing output
    b.hashData();
    std::cout << b.hash << std::endl;
    std::cout << "Integer val for hash of block data" << std::endl;
    std::cout << str_to_uint256(hex_str) << std::endl;
    std::cout << (str_to_uint256(hex_str) == b.hash) << std::endl;



    return 0;
}
