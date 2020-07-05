#include <random>
#include "public_key_crypto.h"

#define RANDOM_MIN 100000000
#define RANDOM_MAX 999999999

int create_random(int, int);
bool check_prime(int);
int gcd(int, int);
int jacobi_symbol(int, int);
ull modulo_exponential(ull, ull, ull);

ull* public_key_crypto::create_prime() {

    ull* prime = new ull[2];

    for(int i = 0; i < 2; i++) {

        while(true) {

            int random_number = create_random(RANDOM_MIN, RANDOM_MAX);

            // only odd numbers
            if(random_number % 2 == 0) continue;

            if(check_prime(random_number)) {
                prime[i] = random_number;
                break;
            }

        }

    }

    return prime;

}

int create_random(int min, int max) {

    std::random_device random;
    std::mt19937 mt(random()); // Mersenne Twister
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);

}

bool check_prime(int number) {

    // test Solovay–Strassen Primality Test 100 times
    for(int i = 0; i < 100; i++) {

        int relative_prime;

        // find a relatively prime number until GCD is 1
        while(true) {

            int random_number = create_random(3, number-1);

            if(gcd(number, random_number) == 1) {
                relative_prime = random_number;
                break;
            }

        }

        int jacobi = jacobi_symbol(relative_prime, number);
        ull modulo = modulo_exponential(relative_prime, (number - 1) / 2, number);

        // if same under modulo, it has chance of primality
        if(jacobi == modulo || jacobi == modulo - number) continue;
        else return false;

    }

    return true;

}

int gcd(int a, int b) {

    int temp;

    while(b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;

}

int jacobi_symbol(int a, int b) {

    if(a == 1) return 1;

    if(a % 2 == 0) {

        int mul = -1;
        int mul_exp = (b*b-1) / 8;
        if(mul_exp % 2 == 0) mul = 1;

        return jacobi_symbol(a/2, b) * mul;

    } else {

        int mul = -1;
        int mul_exp = (a-1) * (b-1) / 4;
        if(mul_exp % 2 == 0) mul = 1;

        return jacobi_symbol(b%a, a) * mul;

    }

}

ull modulo_exponential(ull base, ull exp, ull mod) {

    ull result = 1;

    while(exp > 0) {

        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;

    }

    return result % mod;

}
