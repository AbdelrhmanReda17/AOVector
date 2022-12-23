#include "AOvector.h"


template<typename T>
AOvector<T>::AOvector(int cap) // constructor to make the AOVector
{
    data = new T[cap];  // here we created array named data to our AOVector with the given capacity
    sz = 0; // our size start from 0 because it's empty
    this->capacity = cap; // set the capacity variable equal the given capacity
}

template <typename T>
AOvector<T>::~AOvector(){ // destructor to delete the AOVector
    delete[] data;
}

template <typename T>
AOvector<T>::AOvector(T* data, int n) : capacity(n), sz(0) { // constructor to create the vector and take an array and copy all the element from array to vector without delete it
    this->data = new T[capacity]; // here we created array named data to our AOVector with the given capacity
    for (int i = 0; i < n ; i++) { // here add the other data to out vector data
        this->data[sz] = data[i];
        sz++; // increase the size in the loop
    }
}

template <typename T>
AOvector<T>::AOvector(AOvector &a) //Copy Constructor
{
    this -> sz = a.sz;  // start to make the size equal other vector size
    this -> capacity = a.capacity; // start to make the capacity equal other vector capacity
    this-> data = new T[capacity]; // here we created array named data to our AOVector
    for(int i = 0 ; i < sz ; i++)  // here add the other data to out vector data
        this->data[i] = a.data[i];
}

template <typename T>
AOvector<T>& AOvector<T>::operator=(const AOvector &a) // Copy Assignment
{
    if(this != &a) // check if the user add a different AOVector in the parameter
    {
        delete[] data; // delete the old data
        this -> sz = a.sz; // start to make the size equal other vector size
        this -> capacity = a.capacity; // start to make the capacity equal other vector capacity
        for(int i = 0 ; i < sz ; i++) // here add the other data to out vector data
            this->data[i] = a.data[i];
    }
    return this;
}

template <typename T>
AOvector<T>& AOvector<T>::operator=(const AOvector && other) // Move Assignment
{
    if(this != &other) // check if the user add a different AOVector in the parameter
    {
        delete[] data;      // delete the old
        this -> sz = other.sz; // start to make the size equal other vector size
        this -> capacity = other.capacity;  // start to make the capacity equal other vector capacity
        for(int i = 0 ; i < sz ; i++) // here add the other data to out vector data
            this->data[i] = other.data[i];
        other.data = nullptr; // then delete the other vector
    }
    return this;
}
template<typename T>
T& AOvector<T>::operator[](int index) // Overload in [] to return the value
{
    if(index > sz-1)  // check if index less than the size-1 (Out of our range)
        throw invalid_argument("An error has occured, index out of range." ); // throw  an invalid argument and off the program
    return data[index]; // else return the value which in this index.
}

template<typename T>
void AOvector<T>::push_back(T elem) // push back an element into vector
{
    if(sz < capacity){ // if size of vector less than the capacity then push
        sz += 1; // increase our size
        this-> data[sz-1] = elem; // push the element
    }
    else{ // else we have to make a resizing
        cout << "Resizing to " << capacity*2 << endl;
        T* newdata = new T[capacity*2]; // here new data array with new capacity *= 2
        capacity *= 2; // reset the capacity
        for(int i = 0; i < sz; i++){ // take all the element from the old data to the new
            newdata[i] = data[i];
        }
        delete[] data;  // delete the old data
        data = newdata; // make the old = new
        newdata = nullptr; // then delete the old
        data[sz++] = elem; // add the element and reset the size += 1;
    }
}

template<typename T>
T AOvector<T>::pop_back() // function to pop back the last element in the AOVector
{
    T elem = data[sz-1]; // element variable to saving the last element in the data
    realloc(data,sz - 1);   //reallocating memory to truncate the last value.
    realloc(data,capacity); // then reallocating the data array with the old capacity
    sz--; // decrease our size by 1
    return elem; // return the element variable
}

template<typename T>
void AOvector<T>:: erase(iterator itr)  //function to deleting an element with iterator
{
    int i, j, found=0; // i , j , found our
    for(i=0 ; i < sz ; i++)  // create a for loop to resort the data as add the element that we want to delete in last digit
    {
        if(data[i] == *itr) // here's a check to check if data[i] = out iterator value
        {
            found = 1; // if it's then we increase the found variable
            for(int z = 0 , c = 0 ; z < sz ; z++ ) // for loop to sort the data
            {
                if(z == i) // if z == i then we save the elem and continue and increase only i , z variable
                {
                    T elem = data[i];
                    continue;
                }
                else if ( z != i) // else we add the element in index c and increase the c and z
                {
                    data[c] = data[z];
                    c++;
                }
            }
            break; // break
        }
    }
    if(found==0) // if found == 0 that mean invalid iterator then we throw an invaild argument
        throw invalid_argument("\"An error has occured, index out of range.\"");
    else // else that mean the found and make sort, so we call a pop_back() function to pop back the last element
    {
        pop_back();
    }
}

template<typename T>
void AOvector<T>::erase(iterator itr1 , iterator itr2)  //function to delete the element in range of the first iterator and the second iterator
{

    int firstindx ,secondindx , found = 0,newsize=1; // here's our variables , found , newsize , second and first indx
    for(int i = 0 ; i < sz ; i++) // here is a for loop to get the index of the iterators variable and our check on the iterator
    {
        if(&itr1 == &itr2)  // if address first iterator == address second iterator that mean an invalid iterator
        {
            found = 0; // here's found = 0
            break; // and break
        }
        if(data[i] == *itr1) // if data[i] == first iterator value then store the index(i) in first_index variable and increase found variable
        {
            firstindx = i;
            found = 1;
        }
        else if (data[i] == *itr2)  // if data[i] == second iterator value then store the index(i) in second_index variable and increase found variable
        {
            secondindx = i;
            found = 1;
        }

    }
    for(int i = firstindx ; i <= secondindx ;i++) { // here's a for loop to get number of element we will delete (start from first index to the second index
        newsize += 1; // increase the newsize
    }
    if (found == 0 || firstindx==secondindx ) // here's our if loop if the found == 0 and if first index variable == the second index variable then throw an invalid argument because of the invalid iterators
    {
        throw invalid_argument("\"An error has occured");
    }else // else that mean valid iterators and valid range
    {
        T* newdata = new T[capacity]; // we start to make a new data
        copy(data + firstindx, data + secondindx+1 , newdata);  // here's a copy that copy all the data we want to delete from data array and add it into newdata array
        for(int i = 0 , x = 0; i < sz ; i++) // here's a for loop to add the check if element in new data then dont add it in the data array
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
        realloc(data,sz- newsize ); // then reallocating memory with our new size that's equal to our size - newdata.size()
        realloc(data,capacity); // after the first reallocating then we reallocation the data with the capacity

        sz = sz- newsize;   //reset the size variable with our new size
    }
}

template<typename T>
void AOvector<T>::clear() //function to delete all the element
{
    realloc(data,0 );       // here's we reallocation memory of data with 0 that mean truncate all the element
    realloc(data,capacity); // then we restore our data size by reallocation memory with the capacity
}

template<typename T>
void AOvector<T>::insert(iterator itr , T item)  // function to insert an item in before iterator location
{
    if(sz >= capacity){ // here's a check if size bigger than or equal our capacity
        cout << "Resizing to " << capacity * 2 << endl;
        T* newdata = new T[capacity*2]; //we start to resizing with capacity*=2; and add the element
        capacity *= 2; // set the capacity variable with the new value
        for(int i = 0 , x = 0; x < sz ; i++){   //  a for loop with (x,i) variable to re add the element with our new item
            if (*itr == data[i])    // check if the iterator value = our data[i] then add our item and increase (only i)
            {
                newdata[i] = item;
            }
            else {  // else add the old item and increase (x,i) variables
                newdata[i] = data[x];
                x++;
            }
        }
        sz = sz+1; // increase our size
        delete[] data;  //delete our data
        data = newdata; // set our data with newdata
        newdata = nullptr;  //delete new data
    }else
    {
        T* newdata = new T[capacity]; //we start to create an array with capacity
        for(int i = 0 , x = 0; x < sz ; i++){  //  a for loop with (x,i) variable to re add the element with our new item
            if (*itr == data[i])   // check if the iterator value = our data[i] then add our item and increase (only i)
            {
                newdata[i] = item;
            }
            else {
                newdata[i] = data[x]; // else add the old item and increase (x,i) variables
                x++;
            }
        }
        delete[] data;// delete our size
        data = newdata;// set our data with newdata
        newdata = nullptr; //delet new data
        sz+=1; // increase our size
    }
}

template<typename T>
void AOvector<T>::resize(){ // function to resize the AOVector with new double capacity
    cout << "Resizing to " << capacity*2 << endl;
    T* newdata = new T[capacity*2]; //we start to create a array with a new capacity that's equal to capacity*=2;
    capacity *= 2; // reset the capacity variable with our new capacity value
    for(int i = 0; i < sz; i++){ // add the element to our new vector
        newdata[i] = data[i];
    }
    delete[] data;  // delete the old data
    data = newdata; // make the old data equal the new data
    newdata = nullptr;  // delete the new data
}

template<typename T>
bool AOvector<T>::operator==(const AOvector &other) // operator equal to comparison our vector with another one (element by element)
{
    if(this-> sz == other.sz ) // check if the size of the old vector == he size of our new vector then he will compare else he will not
    {
        bool checked = false; // a bool variable to check if it's just one equal false then  return false
        for(int i = 0;i < sz ; i++) // start looping on the vectors
        {
            if(data[i] == other.data[i])    // if equal
                checked = true; // then checked variable equal true
            else
                return false;   // else he will return a false.
        }
        if(checked == true) // if he out of loop that mean it's ok , then he will return 1
            return true;
    }else
        return 0;
}

template<typename T>
bool AOvector<T>::operator<(const AOvector &other) // operator less than to comparison our vector with another one (element by element)
{
    if(sz == other.sz) {  // check if the size of the old vector == he size of our new vector then he will compare else he will not
        for (int i = 0; i < sz; i++) {  // start looping
            bool checked = false;   // a bool variable
            for (int i = 0; i < sz; i++) {  // start looping again
                if (data[i] < other.data[i])    // if the data[i] < then checked variable = true
                    checked = true;
                else if( data[i] > other.data[i]) // if the data[i] < then checked variable = false
                    checked = false;
                else
                    continue;
            }
            if(checked == false) // if he quit the first loop if checked == false then he will return 0 else return 1
                return 0;
            else
                return 1;
        }
    }else
    {
        throw invalid_argument("Error ! Size is different"); // return invalid size if the size not equal
    }
}

template<typename T>
bool AOvector<T>::empty(){ // function to check if the AO vector is empty
    if(sz == 0) // if size == 0 then return 1 else return 0
        return 1;
    else
        return 0;
}

template<typename T>
int AOvector<T>::size(){ // function to return the size
    return sz;
}

template<typename T>
int AOvector<T>::cap(){ // function to return the capacity
    return capacity;
}
template<typename T>
ostream& operator<< (std::ostream& out, const AOvector<T>& v)
{
    for(int i = 0 ; i < v.sz ; i++)
        out << v.data[i] << " ";
    out << endl;
    return out;
}
template<class T>
typename AOvector<T>::iterator AOvector<T>::begin(){
    return iterator(data);
}
template<class T>
typename AOvector<T>::iterator AOvector<T>::end(){
    return iterator(data[sz-1]);
}
