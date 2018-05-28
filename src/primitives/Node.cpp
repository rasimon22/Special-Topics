//
// Created by Rick Simon on 5/15/18.
//

#include "Node.h"

primitive::Node::Node() {
   this->txPool.resize(100);
   this->neighborList.resize(10);
   this->targetTime = 600000;
}

primitive::Node::Node(std::vector <size_t>& neighborList) {
  this->neighborList = neighborList;
  this->txPool.resize(100);
  this->targetTime = 600000;
}

primitive::Node::Node(std::vector <STransaction> &txPool) {
    this->txPool = txPool;
    this->neighborList.resize(10);
    this->targetTime = 600000;
}

primitive::Node::Node(std::vector <STransaction> &txPool, std::vector <size_t> &neighborList) {
    this->txPool = txPool;
    this->neighborList = neighborList;
    this->targetTime = 600000;
}

void primitive::Node::addNeighbor(size_t neighborPid) {
    this->neighborList.push_back(neighborPid);
}

void primitive::Node::setTargetTime(double targetTime) {
    this->targetTime = targetTime;
}

void primitive::Node::addTransaction(STransaction transaction) {
    this->txPool.push_back(transaction);
}

