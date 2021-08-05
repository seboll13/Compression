#include <time.h>
#include "run_length_encoding.h"

#define COMPRESSED_FILENAME "compressed.txt"

int main() {
    char* original = "000110110000000000001111111111111111100110011111";
    
    clock_t start = clock();
    char* compressed = rle_compression(original);
    printf("Original string   : %s\n", original);
    printf("Compressed string : %s\n", compressed);
    clock_t end = clock();
    
    printf("Program executed in ~ %.6f seconds\n", (float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}