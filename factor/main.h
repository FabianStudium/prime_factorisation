//
//  factor.h
//  factor
//
//  Created by Fabian Gazzia on 13.09.23.
//

#ifndef main_h
#define main_h

#include <stdio.h>
#include <math.h>

int parse_input(const char *str);

void check_argument_count(const int argc);
void print_prime_factorisation(const int *primes, const int *frequencies, const int max_size);

#endif /* factor_h */
