cmake_minimum_required(VERSION 3.13)
project(blockchain_poc)

set(CMAKE_CXX_STANDARD 14)

add_executable(blockchain_poc main.cpp block.cpp block.h blockchain.cpp blockchain.h)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")
find_package(CryptoPP REQUIRED)
target_link_libraries(blockchain_poc cryptopp)