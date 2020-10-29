#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Сравните и выведите в консоль время работы последовательного и параллельного с использованием нескольких
потоков алгоритмов, каждый из которых выделяет в динамической памяти числовой массив размером 100 Мб
и выполняет последовательный поиск в нем максимальной строго возрастающей последовательности.
*/

#include "utility.h"
#include "sequential.h"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return ARGS_ERROR;
    }

    char *f_path = argv[1];

    int *buf = NULL;
    int size = 0;

    int ret = read_from_file(&buf, &size, f_path);

    if (ret == FILE_OPEN_ERROR) {
        printf("Wrong path to file\n");
        return FILE_OPEN_ERROR;
    } else if (ret == MEMORY_ALLLOC_ERROR) {
        printf("Memory allocation error\n");
        return MEMORY_ALLLOC_ERROR;
    } else if (ret == FILE_CONTENT_ERROR) {
        printf("The file must contain only numbers\n");
        return FILE_CONTENT_ERROR;
    }

    printf("Sequential implementation:\r\n");
    int right = 0;
    int left = 0;

    clock_t begin = clock();
    ret = find_seq(buf, size, &left, &right);
    clock_t end = clock();
    double time_seq = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Run lasted: %f\r\n", time_seq);

    if (ret == MEMORY_ALLLOC_ERROR) {
        free(buf);
        printf("Memory allocation error\n");
        return MEMORY_ALLLOC_ERROR;
    }


    printf("Sequence size %d in [%d:%d]\r\n", right-left, left, right);

    free(buf);
    return 0;
}
