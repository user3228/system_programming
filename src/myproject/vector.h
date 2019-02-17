#include <iostream>
#include <utility>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>
 
using namespace std;
 
template<class T> class Vector {
    private:
 
        T* elem;
        int sz;
 
    public:
 
        Vector(int s): elem{new T[s]}, sz{s} {}
 
        // copy-constructor
        Vector(Vector& source): elem{new T[source.size()]}, sz{source.size()} {
            // cout << "copy constructor called" << '\n';
 
            copy(source.begin(), source.end(), elem);
        }
 
        // move-constructor
        Vector(Vector&& source) {
            // cout << "move constructor called" << '\n';
 
            sz = source.size();
 
            elem = new T[sz];
 
            move(source.begin(), source.end(), elem);
 
        }
 
        ~Vector() {
            delete[] elem;
        }
 
 
        Vector& operator=(Vector& source) {
            // cout << "copy assignement called" << '\n';
            sz = source.size();
 
            elem = new T[sz];
 
            copy(source.begin(), source.end(), elem);
 
            return *this;
        }
 
        // move-assignement
        Vector& operator=(Vector&& source) {
            // cout << "move assignement called" << '\n';
            sz = source.size();
 
            elem = new T[sz];
 
            move(source.begin(), source.end(), elem);
 
            return *this;
        }      
 
 
        T* begin() { return &elem[0]; }
 
        T* end() { return &elem[sz]; }
 
        int size() { return sz; }
 
        T& operator[](int i) { return elem[i]; }
 
        void push_back(const T& value) {
            // cout << "copy push_back called" << '\n';
           
 
            T* new_elem = new T[sz+1];
            move(elem, elem+sz, new_elem);
 
 
            new_elem[sz] = value;
            ++sz;
            delete[] elem;
 
 
            elem = new_elem;
        }
 
        void push_back(T&& value) {
            // cout << "move push_back called" << '\n';
 
 
            T* new_elem = new T[sz+1];
            move(elem, elem+sz, new_elem);
 
            new_elem[sz] = move(value);
            ++sz;
 
            delete[] elem;
 
            elem = new_elem;
        }
 
        void pop_back() {
            --sz;
            T* new_elem = new T[sz];
 
            move(elem, elem+sz, new_elem);
            delete[] elem;
            elem = new_elem;
        }
 
        void swap(Vector& other) {
            T* new_elem = new T[other.sz];
            for (auto i=other.size()-1; i>=0; --i) {
                new_elem[i] = other[i];
                other.pop_back();
            }
 
            for (auto i=0; i<sz; ++i) {
                other.push_back(elem[i]);
            }
 
            delete[] elem;
            elem = new_elem;
        }
};
 
 
template<class T> void swap(Vector<T>& one, Vector<T>& another) {
    one.swap(another);
}
 
Vector<int> f(Vector<int> v) {
    return v;
}
