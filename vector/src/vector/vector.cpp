#include <iostream>
#include <utility>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector/vector.h>

int main() {
 
    Vector<ofstream> v(0);
 
    // ofstream ("a", ios::out);
    //ofstream b_file("b", ios::out);
    //ofstream c_file("c", ios::out);
 
    v.push_back(ofstream("a", ios::out));
    v.push_back(ofstream("b", ios::out));
    v.push_back(ofstream("c", ios::out));
    //v.push_back(&b_file);
    //v.push_back(&c_file);
 
 
    // ostrm.write(to_string(i)); // binary output
    //ostrm << 123 << "abc" << '\n';
 
    random_device rd;
    mt19937 g(rd());
 
    shuffle(v.begin(), v.end(), g);
 
    for (auto i = 0; i < v.size(); ++i) {
        v[i] << i;
    }
}
