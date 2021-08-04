#include <time.h>
#include "run_length_encoding.h"

#define COMPRESSED_FILENAME "compressed.txt"

int main() {
    char* original = "0101000011111001010110000111";
    
    clock_t start = clock();
    //char* compressed = rle_compression(original);
    //printf("Original string   : %s\n", original);
    //printf("Compressed string : %s\n", compressed);
    printf("Value: %s\n", dec_to_bin(423587));
    clock_t end = clock();
    
    printf("Program executed in ~ %.3f seconds\n", (float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}