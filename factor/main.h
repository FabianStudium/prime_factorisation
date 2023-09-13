//
//  factor.h
//  factor
//
//  Created by Fabian Gazzia on 13.09.23.
//

#ifndef factor_h
#define factor_h

#include <stdio.h>
#include <stdlib.h> // for strtol, abs, and EXIT_ constants
#include <math.h>

int parse_input(const char *str);
int last_position_of(const int *array, const int size);

void check_argument_count(const int argc);
void calculate_prime_factors(int input_number, int *factors);
void print_prime_factorisation(const int *primes, const int *frequencies, const int max_size);
void calculate_prime_frequencies(const int *factors, int *primes, int *frequencies, int size);

#endif /* factor_h */
