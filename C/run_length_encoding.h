#ifndef RUN_LENGTH_ENCODING_
#define RUN_LENGTH_ENCODING_

#define BUF_SIZE 16777215

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* dec_to_bin(int n);
char* rle_compression(char* text);

#endif