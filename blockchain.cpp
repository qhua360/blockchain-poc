//
// Created by qhua on 07/02/19.
//

#include "blockchain.h"

#include <iostream>

Blockchain::Blockchain(std::string name): name{name} {
    this->chain.push_back(new Block(0, "01/01/2019", "Genesis block", "0"));
}

Blockchain::~Blockchain() {
    for(auto& Block: this->chain) {
        delete(Block);
    }
}

std::string Blockchain::getLatestBlockHash() const {
    return this->chain.back()->getHash();
}

void Blockchain::addBlock(Block *newBlock) {
    newBlock->setPrevHash(this->getLatestBlockHash());
    newBlock->setHash(newBlock->calculateHash());
    this->chain.push_back(newBlock);
}

bool Blockchain::isChainValid() const {
    Block *prev = nullptr;
    for(auto const& block: this->chain) {
        if (block != this->chain.front()) {
            if (block->getHash() != block->calculateHash()) return false;
            if (block->getPrevHash() != prev->getHash()) return false;
        }
        prev = block;
    }
    return true;
}

std::ostream &operator<<(std::ostream &out, const Blockchain &b) {
    out << "Chain: " << b.name << std::endl;
    for(auto Block: b.chain) {
        out << *Block;
    }
    out << (b.isChainValid() ? "Yay, chain is valid" : "Invalid chain");
    out << std::endl;
}
