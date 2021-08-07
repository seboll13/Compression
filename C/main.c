#include "libraries.h"
#include "file_handling.h"
#include "run_length_encoding.h"

int main() {
    char *buff = read_original();

    // Compress received data
    clock_t start = clock();
    char *compressed = rle_compression(buff);
    clock_t end = clock();
    printf("Compression executed in ~ %.3f seconds\n", (float)(end - start) / CLOCKS_PER_SEC);

    write_compressed(compressed);

    free(buff); // free previously allocated memory slot
    return 0;
}