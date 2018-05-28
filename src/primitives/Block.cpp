#include "Block.h"
#include <typeinfo>
primitive::SBlock::SBlock() {
    this->hash = 0;
    this->prevHash = 0;
    this->nonce = 0;

}

primitive::SBlock::SBlock(std::vector <uint256_t> &data, uint256_t prevHash) {
    this->hash = 0;
    this->tx = data;
    this->prevHash = prevHash;
    this->nonce = 0;
    this->tx.push_back(prevHash);
    this->tx.push_back(uint256_t(nonce));
    //TODO:Refactor hashing to include prev and nonce without adding to tx
}

void primitive::SBlock::hashData() {
    std::vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(this->tx.begin(), this->tx.end(), hash.begin(), hash.end());
    std::string hex_string = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
    this->hash = util::str_to_uint256(hex_string);
//    this->hash = util::hash_container(this->tx); TODO:implement and refactor with universal container hash function
}

void primitive::SBlock::incrementNonce() {
    this->nonce++;
    this->tx.back() = this->nonce;
    this->hashData();
    std::cout << this->hash << std::endl;
}

bool primitive::SBlock::verifyTransactions() {
    for (int i = 0; i < this->tx.size(); i++) {
        return typeid(this->tx[i]) == typeid(primitive::STransaction);
    }
}
