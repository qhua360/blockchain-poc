//
// Created by qhua on 06/02/19.
//

#include "block.h"

#include <iostream>
#include "cryptopp/filters.h"
#include "cryptopp/hex.h"
#include "cryptopp/sha.h"

std::string SHA256(std::string data) {
    byte digest[CryptoPP::SHA256::DIGESTSIZE];

    CryptoPP::SHA256().CalculateDigest(digest,
                                       (const byte *)data.c_str(),
                                       data.length());

    CryptoPP::HexEncoder encoder;
    std::string output;

    encoder.Attach(new CryptoPP::StringSink(output));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    return output;
}

Block::Block(int index, std::string timestamp, std::string data, std::string previousHash):
index{index}, timestamp{timestamp}, data{data}, previousHash{previousHash}
{
    hash = calculateHash();
}

std::string Block::getPrevHash() const {
    return this->previousHash;
}

void Block::setPrevHash(std::string hash) {
    this->previousHash = hash;
}

std::string Block::getHash() const {
    return this->hash;
}

void Block::setHash(std::string newHash) {
    this->hash = newHash;
}

std::string Block::calculateHash() const {
    return SHA256(std::to_string(index) + previousHash + timestamp + data);
}

std::ostream &operator<<(std::ostream &out, const Block &b) {
    out << "Block: " << b.index << ", Data: " << b.data << std::endl;
}
