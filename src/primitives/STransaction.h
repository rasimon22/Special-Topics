#ifndef SMU_PRIMITIVES_TRANSACTION_H
#define SMU_PRIMITIVES_TRANSACTION_H

#include "../../uint256_t/uint256_t.h"
#include <string>
#include <time.h>
#include "picosha2.h"
#include "../util/str-u256.h"
namespace primitive {
    class STransaction {
        uint256_t destAddr;
        uint256_t recpAddr;
        unsigned long nTime;
        float amount;
        unsigned int index;
    public:

        std::string to_string();

        STransaction();

        STransaction(uint256_t dest, uint256_t recp, float amt, unsigned int index);

        uint256_t hash_transaction();
    };
}


#endif //SMU_PRIMITIVES_TRANSACTION_H
