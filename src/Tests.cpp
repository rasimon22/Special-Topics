//
// Created by Rick Simon on 6/1/18.
//
#include "catch-2.hpp"
#include "primitives/Block.h"
#include "../uint256_t/uint256_t.h"
#include "util/str-u256.h"
#include <vector>

TEST_CASE("Test Block", "[block]") {
    //test default constructed object was created correctly
    primitive::SBlock testBlock;
    REQUIRE(testBlock.getHash() == 0);
    REQUIRE(testBlock.getPrevHash() == 0);
    REQUIRE(testBlock.getNonce() == 0);
    REQUIRE(testBlock.getNext() == nullptr);
    SECTION("Overloaded Constructor"){
        std::vector<uint256_t> vec;
        for (int i = 0; i < 1000; i++) {
            vec.push_back((uint256_t) i);
        }
        primitive::SBlock overloadedBlock(vec, (uint256_t) 100);
        vec.push_back((uint256_t) 100);
        vec.push_back(overloadedBlock.getNonce());
        REQUIRE(overloadedBlock.getPrevHash() == 100);
        REQUIRE(overloadedBlock.getTx() == vec);
    }

}
