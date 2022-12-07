#include "AOvector.h"

template<typename T>
AOvector<T>::AOvector(int N) {
    // Initialize by specific capacity
    // No content is added, size = 0
    // Assign a default size value
    arr = new T[N];
    sz = N;
    cap = 0;
}

template<typename T>
AOvector<T>::AOvector(T k, int N) {
    // Initialize by n items from array
    arr = new T[N];
    sz = N;
    for(int i =0 ; i < N ; i++)
    {
        arr[i] = k;
    }
    cap = N;
}
template<typename T>
AOvector<T>::AOvector(AOvector& a) {
    // Initialize with a copy
    arr = new T[a.size()];
    sz = a.size();
    for (int i = 0; i < a.size(); i++) {
        *(arr + i) = a[i];
    }
    this->cap = a.cap;
    // deleting the vector.
    a.arr = nullptr;
    a.sz = 0;
    a.cap = 0;
}

template<typename T>
AOvector<T>::~AOvector() {
    // Delete allocated memory
    delete[] arr;
}

template<typename T>
int AOvector<T>::push_back(T item)
{
    // Add item to end of vec & return # of items and Increase capacity
    if(cap == sz){
        throw invalid_argument("Error out of Bounds");
    }
    else{
        cap +=1;
        arr[cap-1] = item;
        return cap-1;
    }
}

template<typename T>
T AOvector<T>::pop_back(){
    // Remove and return last element in vec
    T elem = this->arr[sz-2];
    arr[sz-2] = NULL;
    cap -=1;
    return elem;
}
template<typename T>
int AOvector<T>::size() {
    return sz;
}

template<typename T>
T& AOvector<T>::operator[](int k) {
    // Access item by reference and Throw an exception if out of range
    if (k < sz) return arr[k];
    else throw invalid_argument("Error out of Bounds\n");
}


template<typename T>
ostream& operator<<(std::ostream& os, const AOvector<T>& obj) // ope
{
    for(int i =0 ; i < obj.cap ; i++)
    {
        os << obj.arr[i] << " ";
    }
    return os << endl;
}

