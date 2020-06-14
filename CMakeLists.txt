cmake_minimum_required(VERSION 3.15)
project(public_key_crypto)

set(CMAKE_CXX_STANDARD 14)

add_executable(public_key_crypto main.cpp create_key.cpp)
