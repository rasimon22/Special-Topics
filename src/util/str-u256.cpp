#include "str-u256.h"

uint256_t util::str_to_uint256(std::string input_str) {
    unsigned long long hash_comp[4];
    //assign 64 bit components of 256 bit hash (unsigned long long)
    hash_comp[3] = std::strtoull(input_str.substr(0, (int) (64 / 4)).c_str(), 0, 16);
    hash_comp[2] = std::strtoull(input_str.substr((int) (64 / 4) - 1, (int) (64 / 4)).c_str(), 0, 16);
    hash_comp[1] = std::strtoull(input_str.substr((int) (64 / 2) - 1, (int) (64 / 4)).c_str(), 0, 16);
    hash_comp[0] = std::strtoull(input_str.substr((int) (3 * 64 / 4) - 1, (int) (64 / 4)).c_str(), 0, 16);
    uint256_t out_hash;
    for (int i = 0; i < 4; i++) {
        out_hash += uint256_t(hash_comp[i]) << (64 * i);
    }
    return out_hash;
}

//uint256_t util::hash_container(std::vector<uint256_t, std::allocator<uint256_t> >& cont) {
//    std::string hex_string;
//    std::vector<unsigned char> hash(picosha2::k_digest_size);
//    picosha2::hash256(cont.begin(), cont.end(), hash.begin(), hash.end());
//    picosha2::bytes_to_hex_string(hash, hex_string);
//    return str_to_uint256(hex_string);
//} TODO::implement universal container hash utility
