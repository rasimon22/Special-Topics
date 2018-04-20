#ifndef SMU_PRIMITIVES_TRANSACTION_H
#define SMU_PRIMITIVES_TRANSACTION_H 
#include "uint256_t/uint256_t.h"
#include <time.h>

class STransaction{
    public:
        uint256_t destAddr;
        uint256_t recpAddr;
        unsigned long nTime;
        float amount;
        unsigned int index;
        STransaction();
        STransaction(uint256 dest, uint256 recp, amt);
}


#endif //SMU_PRIMITIVES_TRANSACTION_H
