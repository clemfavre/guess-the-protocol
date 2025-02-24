#include <gtest/gtest.h>
#include "../code/parser.h"
#include "../code/parser.cpp"
#include <iostream>

/*
ERROR TABLE
    0 --> no error
    1 --> error : other char than '0' or '1' found in the bitstream
    3 --> error : can not find/open the file.txt
    4 --> error : EOF while reading a char
    5 --> error : other char than '0' or '1' found while reading a char (TO DO)
    6 --> error : other char than '0' just after reading a char (TO DO)
*/

//return value of fsm() == 0 --> no error
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

//return value of fsm() == 1 --> ERROR : other char than '0' or '1' found
TEST(parserTest, CharAInTheBitsequenceReturn1) {
    testing::internal::CaptureStdout();
    int error = fsm("../res/CharAInTheBitsequenceReturn1.txt");
    std::cout << error;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1");
}

TEST(parserTest, CharAInTheBitsequenceAfterSeveralGluedCharReturn1) {
    testing::internal::CaptureStdout();
    int error = fsm("../res/CharAInTheBitsequenceAfterSeveralGluedCharReturn1.txt");
    std::cout << error;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "abc1");
}

//return value of fsm() == 3 --> ERROR : can not find/open the file.txt
TEST(parserTest, InexistingFile) {
    testing::internal::CaptureStdout();
    int error = fsm("../res/InexistingFile.txt");
    std::cout << error;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "3");
}

//return value of fsm() == 4 --> ERROR : EOF while reading a char
TEST(parserTest, EOFWhileReadingCharMiddle) {
    testing::internal::CaptureStdout();
    int error = fsm("../res/EOFWhileReadingChar.txt");
    std::cout << error;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "4");
}

TEST(parserTest, EOFWhileReadingCharBegining) {
    testing::internal::CaptureStdout();
    int error = fsm("../res/EOFWhileReadingCharBegining.txt");
    std::cout << error;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "4");
}

TEST(parserTest, EOFWhileReadingCharEnd) {
    testing::internal::CaptureStdout();
    int error = fsm("../res/EOFWhileReadingCharEnd.txt");
    std::cout << error;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "4");
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