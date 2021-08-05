#include "run_length_encoding.h"

char *dec_to_bin(char *num) {
    char *eptr;
    long int n = strtol(num, &eptr, 10);
    int closest_power = (int) floor(log2(n));
    char *bin = malloc((closest_power + 1) * sizeof(char *));
    for (int i = closest_power; i > -1; --i) {
        if (pow(2, i) <= n) {
            bin[closest_power - i] = '1';
            n -= 1 << (int)floor(log2(n)); // equiv to 2^p
        }
        else
            bin[closest_power - i] = '0';
    }
    return bin;
}

char *rle_compression(char* text) {
    int counter = 1;
    char curr_bit = *text;
    char *compressed = malloc(100 * sizeof(char *));
    while (*text != '\0') {
        char next_bit = *text++;
        if (next_bit == '\0')
            strncat(compressed, &curr_bit, 1);
        else if (next_bit == curr_bit)
            ++counter;
        else {
            strncat(compressed, &curr_bit, 1);
            counter = 1;
        }
        curr_bit = next_bit;
    }
    return compressed;
}