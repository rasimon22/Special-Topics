#include "Block.h"

SBlock::SBlock(){
    this->hash = 0;
    this->prevHash = 0;
    this->nonce = 0;

}
SBlock::SBlock(std::vector<uint256_t>& data, uint256_t prevHash){
    this->hash = 0;
    this->tx = data;
    this->prevHash = prevHash;
    this->nonce = 0;

    
}
void SBlock::hashData(){

    std::vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(this->tx.begin(), this->tx.end(), hash.begin(), hash.end());
    std::string hex_string = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
    std::cout << hex_string << std::endl;
    this->hash = str_to_uint256(hex_string);
}

