#include "printf/printf.cpp"
#include <gtest/gtest.h>
#include <ostream>
#include <sstream>
#include <string>

TEST(message_function_test, wrong_number_of_args) {
  EXPECT_FALSE(message(std::cout, "% + % = %", 'a'));
  EXPECT_FALSE(message(std::cout, "%+%=%\n", 'a', 'b', 'c', 'd'));
}

TEST(message_function_test, right_result) {
  std::stringstream ss;
  message(ss, "% + % = %\n", "a", 2, 3.0);
  std::string result = ss.str();

  std::string right_result = "a + 2 = 3";
  EXPECT_EQ(right_result, result);
}#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <gtest/gtest.h>
#include <printf/printf.h>
Test(printf,Compare){
stingstream ss;
ss<<message(cout, "% + % = %\n",'a',2)
string k = ss.str();
EXPECT_EQ("a + 2 = %",k);
}

