//
//  factor.c
//  factor
//
//  Created by Fabian Gazzia on 09.10.23.
//

#include "factor.h"

void calculate_prime_frequencies(const int *factors, int *primes, int *frequencies, int size) {
    primes[0] = factors[0];
    frequencies[0] = 1;
    
    for (int i = 1; i < size; i++) {
        int last_prime_loc = last_position_of(primes, size);
        int last_frequencies_loc = last_position_of(frequencies, size);
        
        if(factors[i] == 0) {
            break;
        }
        if(factors[i] == primes[last_prime_loc]) {
            frequencies[last_prime_loc] += 1;
        }
        else {
            primes[last_prime_loc + 1] = factors[i];
            frequencies[last_frequencies_loc + 1] = 1;
        }
    }
}

void calculate_prime_factors(int input_number, int *factors) {
    /*
    Handling of negative numbers:
    
    Negative numbers don't traditionally have prime factorizations. However, one can represent the factorization of a negative number by starting with a factor of -1, followed by the prime factorization of its positive counterpart.
    */
    int divisor = 2;
    int i = 0;
    
    while (input_number > 1) {
        if (input_number % divisor == 0) {
            
            input_number /= divisor;
            factors[i] = divisor;
            i++;
            
        } else {
            divisor++;
        }
    }
}

int last_position_of(const int *array, const int size) {
    int i = 0;
    
    for (; i < size; i++) {
        if(array[i] == 0){
            return i-1;
        }
    }
    
    exit(EXIT_FAILURE);
}
