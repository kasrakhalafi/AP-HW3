#include <iostream>
#include <vector>
#include <string>

class MaxHeap;
std::ostream& operator<<(std::ostream& os,MaxHeap maxHeap);

class MaxHeap{
 public:
    std::vector<int> vec;
    int cnt{1};
    int *arr;

    int size();
    int operator[](int);
    int Parent(int);
    int RightChild(int);
    int LeftChild(int);
    void printArray();
    void max_Heapify(int);
    void Max();
    void getHeight();
    void add(int);
    void Delete();
    void HeapSort();
    MaxHeap();
    MaxHeap(const MaxHeap&);
    MaxHeap(int* , int);
 private:



  
};
