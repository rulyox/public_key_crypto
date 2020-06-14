#include <iostream>
#include "public_key_crypto.h"

int main() {

    // create_key
    std::cout << "Create two large prime numbers." << std::endl;
    int* prime = public_key_crypto::create_key();
    std::cout << prime[0] << " " << prime[1] << std::endl;

    // clean
    delete[] prime;

    return 0;

}
