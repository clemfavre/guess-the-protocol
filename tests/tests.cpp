#include <gtest/gtest.h>

// Function to test
int add(int a, int b) {
    return a + b;
}

// Test case
TEST(AddTest, HandlesPositiveInput) {
    EXPECT_EQ(add(1, 2), 3);
}

TEST(AddTest, HandlesNegativeInput) {
    EXPECT_EQ(add(-1, -2), -3);
}

TEST(AddTest, HandlesMixedInput) {
    EXPECT_EQ(add(-1, 1), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}