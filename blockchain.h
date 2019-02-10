//
// Created by qhua on 07/02/19.
//

#ifndef BLOCKCHAIN_POC_BLOCKCHAIN_H
#define BLOCKCHAIN_POC_BLOCKCHAIN_H


#include <vector>

#include "block.h"

class Blockchain {
    std::string name;
    std::vector<Block *> chain;

public:
    Blockchain(std::string);
    ~Blockchain();
    std::string getLatestBlockHash() const;
    void addBlock(Block *);
    bool isChainValid() const;
    friend std::ostream &operator<<(std::ostream &out, const Blockchain &b);
};


#endif //BLOCKCHAIN_POC_BLOCKCHAIN_H
