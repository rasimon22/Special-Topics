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
    vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(vec.begin(), vec.end(), hash.begin(), hash.end());
    std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(),hash.end());
    //hashing block data, printing output
    SBlock b = SBlock(vec, 0);
    b.hashData();
    std::cout << b.hash << std::endl;
    std::cout << "Integer val for hash of block data" << std::endl;
    std::cout << (str_to_uint256(hex_str) == b.hash/2) << std::endl;
    //testing transaction to_string()
    STransaction* trans = new STransaction(b.hash/3, b.hash/2, 200.000, 0);
    std::string output = std::string(trans->to_string());
    std::cout << output << std::endl;
    //outputting a standard hash
    picosha2::hash256(output.begin(),output.end(),hash.begin(), hash.end());
    std::cout << picosha2::bytes_to_hex_string(hash.begin(), hash.end()) << std::endl;

    delete trans;

    return 0;
}
