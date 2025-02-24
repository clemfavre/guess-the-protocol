#include <gtest/gtest.h>
#include "../code/parser.h"
#include "../code/parser.cpp"
#include <iostream>


TEST(parserTest, oneSimpleChar) {
    // Capture stdout
    testing::internal::CaptureStdout();
    //call function to test
    int error = fsm("../res/oneSimpleChar.txt");
    //print error
    std::cout << error;
    // Get the captured output
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "a0");
}

TEST(parserTest, oneSimpleCharStartingWithOnes) {
    testing::internal::CaptureStdout();
    int error = fsm("../res/oneSimpleCharStartingWithOnes.txt");
    std::cout << error;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "a0");
}

TEST(parserTest, severalGluedChar) {
    testing::internal::CaptureStdout();
    int error = fsm("../res/severalGluedChar.txt");
    std::cout << error;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "abc0");
}

TEST(parserTest, severalNonGluedChar) {
    testing::internal::CaptureStdout();
    int error = fsm("../res/severalNonGluedChar.txt");
    std::cout << error;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "abc0");
}

TEST(parserTest, hiddenMessage) {
    testing::internal::CaptureStdout();
    int error = fsm("../res/bitstream.txt");
    std::cout << error;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Welcome to the Team0");
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