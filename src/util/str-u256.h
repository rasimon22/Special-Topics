//
// Created by Rick Simon on 5/14/18.
//

#ifndef SPECIAL_TOPICS_STR_U256_H
#define SPECIAL_TOPICS_STR_U256_H

#include <string>
#include <vector>
#include "../primitives/picosha2.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "../../uint256_t/uint256_t.h"

namespace util {


    uint256_t str_to_uint256(std::string);

    uint256_t hash_container(std::vector<uint256_t, std::allocator<uint256_t> >&);
}
#endif //SPECIAL_TOPICS_STR_U256_H
