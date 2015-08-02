#include <iostream>
#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    int gtRst = RUN_ALL_TESTS();
    getchar();

    return gtRst;
}
