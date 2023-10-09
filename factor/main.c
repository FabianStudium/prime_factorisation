//
//  main.c
//  factor
//
//  Created by Fabian Gazzia on 13.09.23.
//

#include "main.h"
#include "factor.h"

int main(const int argc, const char * argv[]) {
    check_argument_count(argc);

    int input_number = parse_input(argv[1]);
    const int primes_max = log2(input_number);
    /*
    Why log_2(n) is the max number of possible prime numbers:
    
    For any positive integer n, the maximum number of times it can be divided by the smallest prime, which is 2, is log_2⁡(n). This represents the worst-case scenario where n is a power of 2 and gives the upper limit for the number of prime factors n can have.
    */
    
    int *factors = (int *)malloc(sizeof(int) * primes_max);
    if (!factors) {
        fprintf(stderr, "Memory allocation failed for 'factors'.\n");
        exit(EXIT_FAILURE);
    }
    
    calculate_prime_factors(input_number, factors);
    
    int *primes = (int *)malloc(sizeof(int) * primes_max);
    if (!primes) {
        fprintf(stderr, "Memory allocation failed for 'primes'.\n");
        exit(EXIT_FAILURE);
    }
    
    int *frequencies = (int *)malloc(sizeof(int) * primes_max);
    if (!frequencies) {
        fprintf(stderr, "Memory allocation failed for 'frequencies'.\n");
        exit(EXIT_FAILURE);
    }
    
    calculate_prime_frequencies(factors, primes, frequencies, primes_max);
    
    print_prime_factorisation(primes, frequencies, primes_max);

    free(factors);
    free(primes);
    free(frequencies);
    
    return EXIT_SUCCESS;
}

void print_prime_factorisation(const int *primes, const int *frequencies, const int max_size) {
    int size_primes = last_position_of(primes, max_size); // size_primes == size_frequencies
    
    for (int i = 0; i <= size_primes; i++) {
        if(i > 0) {
            printf(" * ");
        }
        
        if(frequencies[i] > 1){
            printf("%d^%d", primes[i], frequencies[i]);
        } else {
            printf("%d", primes[i]);
        }
        
    }
    printf("\n");
}

// Source: ChatGPT
int parse_input(const char *str) {
    char *endptr;
    /*
     The function strtol stands for "string to long". It attempts to convert a string to a long integer.
     The first argument (str) is the string you want to convert.
     The second argument (&endptr) is a pointer to a character pointer. strtol sets endptr to point to the first character in the string that it couldn't convert. If the entire string is a valid integer, endptr will point to the null terminator ('\0') of the string.
     The third argument (10) specifies the base of the conversion. In this case, we're using base 10, which means we're converting a decimal number.
     */
    int value = (int) strtol(str, &endptr, 10); // typecasting bc strtol generally returns type long
    
    if (*endptr != '\0') {
        fprintf(stderr, "Invalid input: %s is not a whole number.\n", str);
        exit(EXIT_FAILURE);
    }

    return value;
}

void check_argument_count(const int argc) {
    if(argc != 2) {
        fprintf(stderr, "Please provide one whole numbers.\n");
        exit(EXIT_FAILURE);
    }
}
