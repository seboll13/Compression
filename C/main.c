#include <time.h>
#include "run_length_encoding.h"

#define COMPRESSED_FILENAME "compressed.txt"

int main() {
    clock_t start = clock();
    rle_compression("0101000011111001010110000111");
    clock_t end = clock();
    printf("Program executed in ~ %.3f seconds\n", (float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}