//
//  factor.h
//  factor
//
//  Created by Fabian Gazzia on 09.10.23.
//

#ifndef factor_h
#define factor_h

#include <stdio.h>
#include <stdlib.h> // for strtol, abs, and EXIT_ constantsg

void calculate_prime_factors(int input_number, int *factors);
void calculate_prime_frequencies(const int *factors, int *primes, int *frequencies, int size);
int last_position_of(const int *array, const int size);

#endif /* factor_h */
