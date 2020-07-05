#include <iostream>
#include "public_key_crypto.h"

int main() {

    // create_prime
    std::cout << "Create two large prime numbers." << std::endl;
    ull* prime = public_key_crypto::create_prime();
    std::cout << prime[0] << " " << prime[1] << std::endl << std::endl;

    // calculate N
    std::cout << "Calculate n." << std::endl;
    ull n = prime[0] * prime[1];
    std::cout << "n = " << n << std::endl << std::endl;

    // clean
    delete[] prime;

    return 0;

}
