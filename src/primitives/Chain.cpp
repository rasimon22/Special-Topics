//
// Created by Rick Simon on 5/27/18.
//
#include"Chain.h"

primitive::Chain::Chain() {
    this->genBlock = nullptr;
    this->lastBlock = nullptr;
    this->chainLength = 0;
}
primitive::Chain::Chain(primitive::SBlock in) {
   this->genBlock = new primitive::SBlock(in);
   this->lastBlock = genBlock;
   this->chainLength = 1;
}
primitive::Chain::Chain(primitive::Chain& rhs) {
    this->genBlock = new primitive::SBlock(*rhs.genBlock);
    primitive::SBlock *ptr = rhs.genBlock;
    for (int i = 0; i < rhs.chainLength; ++i) {
        primitive::SBlock *next = new primitive::SBlock(*ptr->getNext());
        this->genBlock->addNext(*next);
        this->lastBlock = next;
        next = nullptr;
        ++ptr;
        ++this->chainLength;
    }
}
primitive::Chain& primitive::Chain::operator=(primitive::Chain& rhs) {
   return primitive::Chain::Chain(rhs);
}
primitive::Chain::~Chain() {
    delete this->genBlock;
    this->genBlock = nullptr;
    this->lastBlock = nullptr;
}


