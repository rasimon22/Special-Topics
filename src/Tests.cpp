//
// Created by Rick Simon on 6/1/18.
//
#include "catch-2.hpp"
#include "primitives/Block.h"
#include "../uint256_t/uint256_t.h"
#include "util/str-u256.h"
#include <vector>

TEST_CASE("Test Block", "[block]") {
    std::vector<uint256_t> dataVec;
    for(int i = 0; i < 1000; i++){
        dataVec.push_back((uint256_t) i);
    }
    primitive::SBlock genericBlock(dataVec, 1000);
    //test default constructed object was created correctly
    SECTION("Default Constructor") {
        primitive::SBlock testBlock;
        REQUIRE(testBlock.getHash() == 0);
        REQUIRE(testBlock.getPrevHash() == 0);
        REQUIRE(testBlock.getNonce() == 0);
        REQUIRE(testBlock.getNext() == nullptr);
    }

    SECTION("Overloaded Constructor") {
        std::vector <uint256_t> vec;
        for (int i = 0; i < 1000; i++) {
            vec.push_back((uint256_t) i);
        }
        primitive::SBlock overloadedBlock(vec, (uint256_t) 100);
        vec.push_back((uint256_t) 100);
        vec.push_back(overloadedBlock.getNonce());
        REQUIRE(overloadedBlock.getPrevHash() == 100);
        REQUIRE(overloadedBlock.getTx() == vec);
    }

    SECTION("Hash Block Data") {
        std::vector<uint256_t> vec;
        for (int i = 0; i < 1000; i++) {
            vec.push_back((uint256_t) i);
        }
        primitive::SBlock block1(vec, (uint256_t) 100);
        primitive::SBlock block2(vec, (uint256_t) 100);
        block1.hashData();
        block2.hashData();
        REQUIRE(block1.getHash() == block2.getHash());
    }

    SECTION("Increment Nonce") {
        genericBlock.hashData();
        uint256_t inHash(genericBlock.getHash());
        int inNonce(genericBlock.getNonce());
        genericBlock.incrementNonce();
        REQUIRE(genericBlock.getHash() != inHash);
        REQUIRE(genericBlock.getNonce() == inNonce + 1);
    }

    SECTION("Verify Tx") {
        //TODO:rewrite test when transaction types are used as data
        REQUIRE(!genericBlock.verifyTransactions());
    }


}
