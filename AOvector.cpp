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
template<typename T>
void AOvector<T>:: erase(iterator itr) // 3 4 5 6  // 5  // 3 4 6 5
{
    int i, j, found=0;
    for(i=0 ; i < sz ; i++)
    {
        if(data[i] == *itr)
        {
            found = 1;
            for(int z = 0 , c = 0 ; z < sz ; z++ )
            {
                if(z == i)
                {
                    T elem = data[i];
                    continue;
                }
                else if ( z != i)
                {
                    data[c] = data[z];
                    c++;
                }
            }
            break;
        }
    }
    if(found==0)
        throw invalid_argument("\"An error has occured, index out of range.\"");
    else
    {
        pop_back();
    }
}

template<typename T>
void AOvector<T>::erase(iterator itr1 , iterator itr2)  // 3 4 5 6 7  // 3  // 2
{

    int firstindx ,secondindx , found = 0,newsize=1;
    for(int i = 0 ; i < sz ; i++)
    {
        if(*itr1 == *itr2)
        {
            found = 0;
            break;
        }
        if(data[i] == *itr1)
        {
            firstindx = i;
            found = 1;
        }
        else if (data[i] == *itr2)
        {
            secondindx = i;
            found = 1;
        }

    }
    for(int i = firstindx ; i <= secondindx ;i++) {
        newsize += 1;
    }
    if (found == 0 || firstindx==secondindx )
    {
        throw invalid_argument("\"An error has occured");
    }else
    {
        T* newdata = new T[capacity];
        copy(data + firstindx, data + secondindx+1 , newdata);
        for(int i = 0 , x = 0; i < sz ; i++)
        {
            bool founded = 0;
            for(int z = 0 ; z < newsize  ; z++)
            {
                if (data[i] == newdata[z])
                {
                    founded = true;
                    break;
                }
            }
            if(founded == 0)
            {
                data[x] = data[i];
                x++;
            }

        }
        realloc(data,sz- newsize );
        realloc(data,capacity);
        sz = sz- newsize;
    }
}


