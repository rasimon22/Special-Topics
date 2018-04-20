//#include <mpi.h>
#include "primitives/Block.h"
#include "primitives/STransaction.h"
#include "../uint256_t/uint256_t.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

int main(int argc, char** argv){
    vector<int> vec;
    for(int i = 0; i < 100000; i++){
        vec.push_back(rand());
    }
    SBlock b = SBlock(vec, 0);
    b.hashData();
    std::cout << b.hash << std::endl;
    STransaction* trans = new STransaction(b.hash/3, b.hash/2, 200.000, 0);
    std::string output = std::string(trans->to_string());
    std::cout << output << std::endl;
    std::vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(output.begin(),output.end(),hash.begin(), hash.end());
    std::cout << picosha2::bytes_to_hex_string(hash.begin(), hash.end()) << std::endl;
    delete trans;

    return 0;
}
