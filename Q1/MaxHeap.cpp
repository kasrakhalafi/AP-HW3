#include "MaxHeap.h"
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

MaxHeap::MaxHeap(){//use vector for creating the max heap and mine code's first value of vector is 0
    vec.push_back(0);
}

MaxHeap::MaxHeap(const MaxHeap& maxHeap) {//constructor of max heap
    for(size_t i = 0; i < maxHeap.vec.size() ; ++i) {
        vec.push_back(maxHeap.vec[i]);//push backing all vectors to the new vector
        int current = static_cast<int>(vec.size()-1);//changing     unsigned long to it
        while(current != 1)
        {
            if(vec[current] > vec[current >> 1])
            {
                std::swap(vec[current], vec[current >> 1]);
                current >>= 1;
            }
            else break;
        }
    }
}

MaxHeap::MaxHeap(int* arr, int size) {//constructor for max heap which gets name of array and size of it
    vec.push_back(0);

    for (int i{}; i < size; ++i) {//push backing all arrays into a vector
        vec.push_back(arr[i]);

        int current = static_cast<int>(vec.size()-1);
        while(current != 1)//heaping!!
        {
            if(vec[current] > vec[current >> 1])
            {
                std::swap(vec[current], vec[current >> 1]);
                current >>= 1;
            }
            else break;
        }
        //max_Heapify(1);
    }

}


void MaxHeap::max_Heapify(int inputt) {//declaring the max heapify
    size_t input = inputt;//cause of warning changed int to size_t
    size_t l = input;
    if((input << 1) < vec.size() && vec[l] < vec[input << 1])//this is the the formula!
    {
        l = input << 1;
    }
    else if((input << 1) + 1 < vec.size() && vec[l] < vec[(input << 1) + 1])
    {
        l = (input << 1) + 1;
    }
    if(input != l)
    {
        std::swap(vec[input], vec[l]);
        max_Heapify(l);
    }
}

void MaxHeap::add(int a) {//push backing the new number then sort it
  vec.push_back(a);
    int current = static_cast<int>(vec.size()-1);
    while(current != 1)//sorting the added number to vector
    {
        if(vec[current] > vec[current >> 1])
        {
            std::swap(vec[current], vec[current >> 1]);
            current >>= 1;
        }
        else break;
    }
}

int MaxHeap::size() {
    return vec.size();
}

std::ostream& operator<<(std::ostream& os,MaxHeap maxHeap){ // declaring the cout
    for (int i = 1; i < maxHeap.size()  ; i++) {
        os << maxHeap.vec[i] << " ";
        for (int j = 0; j < 10; j++) {
            if(i == std::pow(2,j) - 1){//this is used for going to the new line
                std::cout << std::endl;
                break;
            }
        }
    }
    return os;
}

void MaxHeap::Delete() {//removing the greatest number
    if(vec.size() != 1){
        std::swap(vec[vec.size()-1] , vec[1]);//changing the first and last value of vector
        vec.pop_back();//poping back the greatest number
        max_Heapify(1);//sorting
    }
}

void MaxHeap::Max() {//showing the greatest number
    std::cout << "Max of heap is: " << vec[1] << std::endl;
}

void MaxHeap::getHeight(){//getting the height
    for (size_t i = 1; i < vec.size()  ; i++) {
        for (int j = 0; j < 10; j++) {
            if(i == std::pow(2,j) - 1){
                cnt++;
                break;
            }
        }
    }
    std::cout << "Height of this tree is: " << cnt << std::endl;
}


int MaxHeap::Parent(int x) {            //with the formula :)
    return vec[(x-1)/2 +1];
}

int MaxHeap::LeftChild(int x) {         //with the formula :)
    return vec[(2*x) + 2];
}

int MaxHeap::RightChild(int x) {        //with the formula :)
    return vec[(2*x) + 3];
}

void MaxHeap::HeapSort() {
    sort(vec.begin(), vec.end(), std::greater<>());//sorting with a simple formula!!
    /*std::vector<int> vector;             //this other formula was to getting out the greatest number out and then sort it and do int till the all of vector is finished!
    vector.push_back(0);                   //but unfortunately this way was not completed
    int x{static_cast<int>(vec.size())};   //this way does not work

    int current = static_cast<int>(vec.size()-1);
    while(current != 1)
    {
        if(vec[current] > vec[current >> 1])
        {
            std::swap(vec[current], vec[current >> 1]);
            current >>= 1;
        }
        else break;
    }

    for(size_t i{}; i < x ; i++){


        vector.push_back(vec[1]);
        std::cout << x << "  " <<  vec[x - i -1] << std::endl;
        std::cout << i << " is " << vec[1] << std::endl;
        std::swap(vec[1] , vec[x-i]);
        vec.pop_back();

        int cur = static_cast<int>(vec.size()-1);
        while(cur != 1)
        {
            if(vec[cur] > vec[cur >> 1])
            {
                std::swap(vec[cur], vec[cur >> 1]);
                current >>= 1;
            }
            else break;
        }

        max_Heapify(1);

    }*/
    //for (size_t j{1}; j < vec.size(); ++j) {
      //  std::cout << vec[j] << " ";
    //}
}

void MaxHeap::printArray() {//printing the array
    for (size_t i{}; i < vec.size()-1 ; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

}

int MaxHeap::operator[](int s) {//returning the value of the vector[s+1] cause vector[0] equals to 0
    return vec[s+1];
}


