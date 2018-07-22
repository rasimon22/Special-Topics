//
// Created by Rick Simon on 5/27/18.
//
#include"Chain.h"

primitive::Chain::Chain() {
    this->genBlock = nullptr;
    this->lastBlock = nullptr;
    this->chainLength = 0;
}
primitive::Chain::Chain(const primitive::SBlock& in) {
   this->genBlock = new primitive::SBlock(in);
   this->lastBlock = genBlock;
   this->chainLength = 1;
}
primitive::Chain::Chain(const primitive::Chain& rhs) {
    this->genBlock = new primitive::SBlock(*rhs.genBlock);
    primitive::SBlock *ptr = rhs.genBlock;
    for (int i = 0; i < rhs.chainLength; ++i) {
        primitive::SBlock *next = new primitive::SBlock(*ptr->getNext());
        this->genBlock->addNext(next);
        this->lastBlock = next;
        next = nullptr;
        ++ptr;
        ++this->chainLength;
    }
}
void primitive::Chain::operator=(primitive::Chain& rhs) {
   this->genBlock = rhs.genBlock;
   this->lastBlock = rhs.lastBlock;
   this->chainLength = rhs.chainLength;
}
primitive::Chain::~Chain() {
    delete this->genBlock;
    this->genBlock = nullptr;
    this->lastBlock = nullptr;
}

primitive::SBlock& primitive::Chain::operator[](size_t index) {
    primitive::SBlock *it = genBlock;
    for (int i = 0; i < this->chainLength; ++i) {
        it = it->getNext();
    }
    return *it;
}

size_t primitive::Chain::getChainLength()
{
    return this->chainLength;
}


