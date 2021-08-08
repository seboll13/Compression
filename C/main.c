#include "libraries.h"
#include "run_length_encoding.h"

#define BUF_SIZE 16777215
#define ORIGINAL_FILENAME "files/original.txt"
#define COMPRESSED_FILENAME "files/compressed.txt"

int main() {
    // Get original file data onto memory
    FILE *original_file = fopen(ORIGINAL_FILENAME, "r+");
    if (original_file == NULL) {
        printf("Error while opening original file.");
        exit(EXIT_FAILURE);
    }
    // Open empty output file
    FILE *compressed_file = fopen(COMPRESSED_FILENAME, "w+");
    if (compressed_file == NULL) {
        printf("Error while opening compressed file.");
        exit(EXIT_FAILURE);
    }

    char *buff = malloc(BUF_SIZE * sizeof(char *));
    clock_t start = clock();
    // Line by line: read from original, compress and write
    while (fscanf(original_file, "%[^\n] ", buff) != EOF) {
        char *compressed = rle_compression(buff);
        strcat(compressed, "\n");
        fwrite(compressed, 1, (int)strlen(compressed), compressed_file);
    }
    clock_t end = clock();
    printf("Compression executed in ~ %.3f seconds\n", (float)(end - start) / CLOCKS_PER_SEC);

    fclose(original_file);
    fclose(compressed_file);
    free(buff); // free previously allocated memory slot
    return 0;
}