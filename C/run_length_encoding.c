#include "run_length_encoding.h"

char* dec_to_bin(int n) {
    int closest_power = (int) floor(log2(n));
    char* bin = malloc((closest_power + 1) * sizeof(char *));
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

char* rle_compression(char* text) {
    int counter = 1;
    char curr_bit = text[0];
    char* compressed = malloc(100 * sizeof(char *));
    for (int i = 0; i < (int)strlen(text); ++i) {
        char next_bit = text[i+1];
        char* bin = dec_to_bin(counter);
        if (next_bit == curr_bit)
            ++counter;
        else {
            strcat(compressed, bin);
            strncat(compressed, &curr_bit, 1);
            counter = 1;
        }
        curr_bit = next_bit;
    }
    return compressed;
}