#ifndef SMU_PRIMITIVES_BLOCK_H
#define SMU_PRIMITIVES_BLOCK_H
using namespace std;

#include <vector>
#include <string>
#include "picosha2.h"
#include <iostream>
#include "STransaction.h"
#include <sstream>
#include <cstdlib>
#include "../../uint256_t/uint256_t.h"
#include "../util/str-u256.h"
namespace primitive {
    class SBlock {
        uint256_t hash;
        uint256_t prevHash;
        int nonce;
        primitive::SBlock *nextBlock;
        friend void primitive::Chain::append();

    public:


        SBlock();

        SBlock(std::vector <uint256_t> &data, uint256_t prevHash);

        ~SBlock();

        void hashData();

        void incrementNonce();

        bool verifyTransactions();

        void addNext(primitive::SBlock*);

        primitive::SBlock* getNext();

    };
}

#endif //SMU_PRIMITIVES_BLOCK_H
