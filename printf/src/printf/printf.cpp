#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <printf/printf.h>
using namespace std;
int main() {
message(cout, "test % template % % % % %\n", "test", 'h', 'q', 'w');
}
