#include "STransaction.h"

primitive::STransaction::STransaction(){
    this-> destAddr = uint256_t();
    this-> recpAddr = uint256_t();
    this->nTime = time(0);
    this->amount = 0;
    this-> index = 0;
    this->txFee = 0;
}
primitive::STransaction::STransaction(uint256_t dest, uint256_t recp, float amt, unsigned int index) {
    this->destAddr = dest;
    this->recpAddr = recp;
    this->amount = amt;
    this->nTime = time(0);
    this->index = index;
}

std::string primitive::STransaction::to_string(){
    std::string ret = this->destAddr.str(16, 64);
    ret += this->recpAddr.str(16, 64);
    ret += std::to_string(this->nTime);
    ret += std::to_string(this->index);
    return ret;
}

uint256_t primitive::STransaction::hash_transaction() {
    std::string ret = this->destAddr.str(16, 64);
    ret += this->recpAddr.str(16,64);
    ret += std::to_string(this->nTime);
    ret += std::to_string(this->index);
    std::string hash_hex_string;
    picosha2::hash256_hex_string(ret, hash_hex_string);
    return util::str_to_uint256(hash_hex_string);
}

bool primitive::STransaction::operator < (const primitive::STransaction& rhs) {
    return this->txFee < rhs.txFee;
}

void primitive::STransaction::updateTxFee(double txFee) {
    this->txFee = txFee;
}

double primitive::STransaction::getTxFee() {
    return this->txFee;
}
