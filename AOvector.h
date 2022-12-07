#ifndef AOVECTOR_AOVECTOR_H
#define AOVECTOR_AOVECTOR_H
#include <iostream>
#include <iterator>
using namespace std;

template<typename T> // declaration
class AOvector; // forward declare to make function declaration possible

template<typename T> // declaration
ostream& operator<<(std::ostream&, const AOvector<T>&);

template<typename T>
class AOvector {
private:
    T *arr;
    int sz;
    int cap = 0;
public:
    ~AOvector();
    AOvector(int N);
    AOvector(T k, int N);
    AOvector(AOvector &a);
    AOvector &operator=(const AOvector &a);
    AOvector &operator=(const AOvector &&a);
    int size();
    T &operator[](int k);
    int push_back(T item);
    T pop_back();
    friend ostream& operator<< <> (std::ostream&, const AOvector&);


};

#endif //AOVECTOR_AOVECTOR_H
