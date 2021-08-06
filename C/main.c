#include <time.h>
#include "run_length_encoding.h"

#define ORIGINAL_FILENAME "files/original.txt"
#define COMPRESSED_FILENAME "files/compressed.txt"

/**
 * return the size of the file passed as parameter
 * */
long int get_file_size(FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    long int s = ftell(fp);
    fclose(fp);
    return s;
}

int main() {
    // Get original file data onto memory
    FILE *original_file = fopen(ORIGINAL_FILENAME, "r");
    char *buff = malloc(BUF_SIZE * sizeof(char *));
    if (original_file == NULL) {
        printf("Error while opening original file.");
        exit(-1);
    }
    fscanf(original_file, "%s", buff);
    fclose(original_file);

    // Compress received data
    clock_t start = clock();
    char *compressed = rle_compression(buff);
    clock_t end = clock();
    // Write the result into the output file
    FILE *compressed_file = fopen(COMPRESSED_FILENAME, "w+");
    if (compressed_file == NULL) {
        printf("Error while opening compressed file.");
        exit(-1);
    }
    fprintf(compressed_file, "%s", compressed);
    fclose(compressed_file);
    
    free(buff); // free previously allocated memory slot
    printf("Program executed in ~ %.6f seconds\n", (float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}