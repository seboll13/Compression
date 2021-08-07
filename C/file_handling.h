#ifndef FILE_HANDLING_
#define FILE_HANDLING_

#define BUF_SIZE 16777215
#define ORIGINAL_FILENAME "files/original.txt"
#define COMPRESSED_FILENAME "files/compressed.txt"

#include "libraries.h"

long int get_file_size(FILE *fp);
char *read_original();
void write_compressed(char *compressed);

#endif