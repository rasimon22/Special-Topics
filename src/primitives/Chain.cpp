//
// Created by Rick Simon on 5/27/18.
//
#include"Chain.h"

primitive::Chain::Chain() {
    this->chainLength = 0;
    this->ledger.resize(10);
}

std::vector<SBlock> primitive::Chain::getLedger() {
    return this->ledger;
}

void primitive::Chain::addBlock(primitive::SBlock block) {
    this->ledger.push_back(block);
}

primitive::SBlock primitive::Chain::getRecentBlock() {
    return this->ledger.back();
}

primitive::SBlock primitive::Chain::getBlockAtIndex(size_t index) {
    return this->ledger[index];
}

