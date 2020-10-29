#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

const int* generate_array(int d) {
    int* arr = malloc(sizeof(int)*d);

    if (!arr)
        return NULL;

    for (int i = 0; i < d; ++i) {
        arr[i] = rand();
    }
    return arr;
}

// TODO redo (testing only)

int read_from_file(int **buf, int *size, char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        return FILE_OPEN_ERROR;
    }

    int num_of_spaces = 0;
    char tmp;

    while ((tmp = fgetc(file)) != EOF) {
        if (tmp == ' ') {
            num_of_spaces++;
        }
    }

    *size = num_of_spaces + 1;
    (*buf) = (int*)malloc((*size) * sizeof(int));
    if (!(*buf)) {
        fclose(file);
        return MEMORY_ALLLOC_ERROR;
    }

    fseek(file, 0, SEEK_SET);
    int i = 0;
    int return_value = 0;

    do {
        return_value = fscanf(file, "%d", &((*buf)[i]));
        if (return_value == 0) {
            free(*buf);
            fclose(file);
            return FILE_CONTENT_ERROR;
        }
        i++;
    } while (return_value != EOF);

    fclose(file);
    return OK_EVENT;
}
