#include <gtest/gtest.h>
#include "MyFitnessPal.h"

TEST(SuiteName, TestName1) {
    utilizator u1;
    const utilizator& u2(u1);
    EXPECT_EQ(u1, u2);
}

TEST(SuiteName, TestName2) {
    utilizator u1(1,1,1,"1","1");
    const utilizator& u2(u1);
    EXPECT_EQ(u1, u2);
}


