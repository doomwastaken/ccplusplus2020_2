#include <gtest/gtest.h>

extern "C" {
    #include "sequential.h"
}

TEST(LisTest, BaseTest) {
    int buf[] = {13, 13, 15, 0, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4};
    int size = sizeof(buf) / sizeof (int);
    int right = 0;
    int left = 0;
    int res_size = 0;
    find_seq(buf, size, &left, &right);
    res_size = right - left;
    ASSERT_EQ(res_size, 7);
    ASSERT_EQ(buf[left], 0);
}
