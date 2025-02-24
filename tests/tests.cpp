#include <gtest/gtest.h>
#include "../code/parser.h"
#include "../code/parser.cpp"
#include <iostream>


TEST(parserTest, parseOneSimpleChar) {
    // Capture stdout
    testing::internal::CaptureStdout();

    //call function to test
    int error = fsm("../res/test.txt");

    //print error
    std::cout << error;
    
    // Get the captured output
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "a0");
}











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