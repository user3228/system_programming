#include <iostream>
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
