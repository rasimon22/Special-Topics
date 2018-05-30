#include <mpi.h>
#include "primitives/Block.h"
#include "primitives/STransaction.h"
#include "primitives/Node.h"
#include "../uint256_t/uint256_t.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "util/str-u256.cpp"
int main(int argc, char** argv){
    primitive::Node n = primitive::Node();
    for(int i = 0; i < 10; i++) {
        primitive::STransaction t = primitive::STransaction(rand(), rand(), rand(), rand());
        t.updateTxFee(rand());
        n.addTransaction(t);
    }
    std::cout << n.getTxPool().size() << std::endl;
    for(int i = 0; i < n.getTxPool().size(); i++) {
        std::cout << n.getTxPool()[i].getTxFee() << std::endl;
        std::cout << n.getTxPool()[i].hash_transaction() << std::endl;
    }

//    }
//    primitive::SBlock b = primitive::SBlock(vec, uint256_t(rand()));
//    b.hashData();
//    for(int i = 0; i < 100; i++) {
//        b.incrementNonce();
//    }


    return 0;
}
