#include "file_handling.h"

/**
 * return the size of the file passed as parameter
 * @param fp: desired file
 * */
long int get_file_size(FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    long int s = ftell(fp);
    fclose(fp);
    return s;
}

/**
 * Get original data file onto memory
 * */
char *read_original() {
    // Get original file data onto memory
    FILE *original_file = fopen(ORIGINAL_FILENAME, "r");
    char *buff = malloc(BUF_SIZE * sizeof(char *));
    if (original_file == NULL) {
        printf("Error while opening original file.");
        exit(-1);
    }
    fscanf(original_file, "%s", buff);
    fclose(original_file);
    return buff;
}

/**
 * Write the result into the output file
 * @param compressed: compressed file to write
 * */
void write_compressed(char *compressed) {
    // Write the result into the output file
    FILE *compressed_file = fopen(COMPRESSED_FILENAME, "w+");
    if (compressed_file == NULL) {
        printf("Error while opening compressed file.");
        exit(-1);
    }
    fwrite(compressed, 1, (int)strlen(compressed), compressed_file);
    fclose(compressed_file);
}