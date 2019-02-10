#include <iostream>
#include "blockchain.h"
#include "block.h"

int main() {
    Blockchain coin = Blockchain("Coin");
    coin.addBlock(new Block(1, "20/07/2019", "4"));
    coin.addBlock(new Block(2, "20/07/2019", "8"));

    std::cout << coin;

    return 0;
}