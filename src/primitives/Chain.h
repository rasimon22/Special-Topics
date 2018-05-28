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
        std::vector<primitive::SBlock> ledger;
        size_t chainLength;
    public:
        Chain();
        void addBlock(primitive::SBlock);
        std::vector<primitive::SBlock> getLedger();
        void setLedger(std::vector<primitive::SBlock> ledger);
        primitive::SBlock getRecentBlock();
        primitive::SBlock getBlockAtIndex(size_t index);


    };
}

#endif //SPECIAL_TOPICS_CHAIN_H
