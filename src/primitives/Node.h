#ifndef SPECIAL_TOPICS_NODE_H
#define SPECIAL_TOPICS_NODE_H

#include "Block.h"
#include "STransaction.h"
#include "../util/str-u256.h"
#include <vector>
#include <iostream>
#include <mpi.h>
#include <algorithm>
namespace primitive{
    class Node {
    protected:
        vector <STransaction> txPool;
        vector <size_t> neighborList;
        double targetTime;
    public:
        Node ();
        Node (std::vector<STransaction>& txPool);
        Node (std::vector<size_t>& neighborList);
        Node (std::vector<STransaction>& txPool, std::vector<size_t>& neighborList);
        void setTargetTime(double targetTime);
        void addNeighbor(size_t neighborPid);
        void addTransaction(STransaction transaction);
        std::vector <STransaction>& getTxPool();

        void setup_for_mining();

    };
}
#endif //SPECIAL_TOPICS_NODE_H
