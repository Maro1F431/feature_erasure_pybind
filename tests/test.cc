#include <gtest/gtest.h>

#include "../src/func.hh"

TEST(add_tests, itsthree)
{
    ASSERT_EQ(3, add(1,2));
}
