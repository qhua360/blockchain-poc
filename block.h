//
// Created by qhua on 06/02/19.
//

#ifndef BLOCKCHAIN_POC_BLOCK_H
#define BLOCKCHAIN_POC_BLOCK_H

#include <string>

class Block {
    int index;
    std::string previousHash, timestamp, hash, data;

public:
    Block(int index, std::string timestamp, std::string data, std::string previousHash = "");
    ~Block()=default;
    std::string getPrevHash() const;
    void setPrevHash(std::string);
    std::string getHash() const;
    void setHash(std::string);
    std::string calculateHash() const;
    friend std::ostream &operator<<(std::ostream &out, const Block &b);
};


#endif //BLOCKCHAIN_POC_BLOCK_H
