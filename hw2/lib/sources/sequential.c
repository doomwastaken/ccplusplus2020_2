#include <stdlib.h>
#include <stdio.h>

#include "sequential.h"
#include "utility.h"

int find_seq(const int *buf, int buf_size, int *l_index, int *r_index) {
    if (buf_size <=1) {
        return buf_size;
    }

    if (!buf) {
        return NULLPTR;
    }

    int left = 0;
    int right = 0;
    int left_temp = 0;
    int right_temp = 0;

    for (int i=1; i < buf_size; i++) {
        if (buf[i-1] <= buf[i]) {
            right_temp = i;
        } else if ((right-left) < (right_temp - left_temp)) {
            right = right_temp;
            left = left_temp;
            left_temp = right;
        }
    }
    *l_index = left;
    *r_index = right;
    return OK_EVENT;
}
