#include "Block.h"

SBlock::SBlock(){
    this->hash = 0;
    this->prevHash = 0;
    this->nonce = 0;

}
SBlock::SBlock(std::vector<int>& data, int prevHash){
    this->hash = 0;
    this->tx = data;
    this->prevHash = prevHash;
    this.hashData();

    
}
void SBlock::hashData(){

    std::vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(this->tx.begin(), this->tx.end(), hash.begin(), hash.end());
    std::string hex_string = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
    unsigned long long hash_comp[4];
    //assign 64 bit components of 256 bit hash (unsigned long long)
    hash_comp[3] = std::strtoull(hex_string.substr(0, (int)(64/4)).c_str(), 0, 16); 
    hash_comp[2] = std::strtoull(hex_string.substr((int)(64/4)-1, (int)(64/4)).c_str(), 0, 16);
    hash_comp[1] = std::strtoull(hex_string.substr((int)(64/2)-1, (int)(64/4)).c_str(), 0, 16);
    hash_comp[0] = std::strtoull(hex_string.substr((int)(64/4)-1, (int)(64/4)).c_str(), 0, 16);
    for(int i = 0; i < 4; i++){
        this->hash += uint256_t(hash_comp[i]) << (64*i);
    }
}

