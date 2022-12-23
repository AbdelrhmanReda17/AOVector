#ifndef AOVECTOR_AOVECTOR_H
#define AOVECTOR_AOVECTOR_H
#include <bits/stdc++.h>

using namespace std;

template<typename T> // declaration
class AOvector; // forward declare to make function declaration possible

template<typename T> // declaration
ostream& operator<<(std::ostream&, const AOvector<T>&);


template<typename T>
class AOvector {
private:
    T *data; // array of data
    int sz; // size of element in data
    int capacity = 0;   // the hole size of array
public:
    typedef T* iterator; // iterator variable
    ~AOvector(); // destructor to delete the AOVector
    AOvector(int cap = 2); // constructor to make the AOVector
    AOvector(T* arr, int N); // constructor to create the vector and take an array and copy all the element from array to vector without delete it
    AOvector(AOvector &other); //Copy Constructor (copy element from another (left value) AOVector)
    AOvector &operator=(const AOvector &other); // Copy Assignment (copy element from another (left value) AOVector)
    AOvector &operator=(const AOvector &&other); // Move Assignment (copy element from another (right value) AOVector) (delete the other)
    T &operator[](int index); // Overload in [] to return the value which in this index.
    void push_back(T elem); // push back an element into vector
    T pop_back(); // function to pop back the last element in the AOVector
    int size(); // function to resize the AOVector with new double capacity
    friend ostream& operator<< <> (std::ostream&, const AOvector&); // operator overloading function to
    void insert(iterator itr , T item);  // function to insert an item in before iterator location
    void erase(iterator itr); //function to deleting an element with iterator
    void erase(iterator itr1 , iterator itr2);  //function to delete the element in range of the first iterator and the second iterator
    void clear(); //function to delete all the element
    iterator begin(); // end iterator to return iterator point to  first element
    iterator end();
    bool operator==(const AOvector<T>& other);  // operator equal to comparison our vector with another one (element by element)
    bool operator< (const AOvector<T>& other); // operator less than to comparison our vector with another one (element by element)
    int cap(); // function to return the capacity
    void resize(); // function to return the size
    bool empty(); // function to check if the AO vector is empty

};


#endif //AOVECTOR_AOVECTOR_H
