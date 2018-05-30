//
// Created by Rick Simon on 5/27/18.
//
#include <vector>
#include <string>
#include "picosha2.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Block.h"
#include "../../uint256_t/uint256_t.h"
#include "../util/str-u256.h"

#ifndef SPECIAL_TOPICS_CHAIN_H
#define SPECIAL_TOPICS_CHAIN_H
namespace primitive {
    class Chain {
        primitive::SBlock *genBlock;
        primitive::SBlock *lastBlock;
        size_t chainLength;
    public:
        Chain();
        Chain(primitive::SBlock);
        Chain(primitive::Chain&);
        ~Chain();
        Chain& operator= (Chain&);
        size_t getChainLength();

        void append();





    };
}

#endif //SPECIAL_TOPICS_CHAIN_H
