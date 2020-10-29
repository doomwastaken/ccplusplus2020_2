#ifndef UTILITY_H_
#define UTILITY_H_

#define BUF_SIZE  1024 * 1024 * 100

#define INT_MAX          1000

enum {
    NULLPTR             = -5,
    ARGS_ERROR          = -4,
    FILE_CONTENT_ERROR  = -3,
    FILE_OPEN_ERROR     = -2,
    MEMORY_ALLLOC_ERROR = -1,
    OK_EVENT            =  0,
};

const int* generate_array(int d);
int read_from_file(int **buf, int *size, char *file_path);

#endif  // UTILITY_H_
