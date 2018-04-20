#include "STransaction.h"

STransaction::STransaction(){
    this-> destAddr = uint256_t();
    this-> recpAddr = uint256_t();
    this->nTime = time(0);
    this->amount = 0;
    this-> index = 0;
}
STransaction::STransaction(uint256_t dest, uint256_t recp, float amt, unsigned int index){
    this->destAddr = dest;
    this->recpAddr = recp;
    this->amount = amt;
    this->nTime = time(0);
    this->index = index;
}

