#ifndef SMU_PRIMITIVES_TRANSACTION_H
#define SMU_PRIMITIVES_TRANSACTION_H 
#include "../../uint256_t/uint256_t.h"
#include <string>
#include <time.h>

class STransaction{
    public:
        uint256_t destAddr;
        uint256_t recpAddr;
        unsigned long nTime;
        float amount;
        unsigned int index;
        std::string to_string();
        STransaction();
        STransaction(uint256_t dest, uint256_t recp, float amt, unsigned int index);
};


#endif //SMU_PRIMITIVES_TRANSACTION_H
