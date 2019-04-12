#include <iostream>
#include <string>
#include "MaxHeap.h"


int main()
{
  	MaxHeap h1{};
	h1.add(25);
	h1.add(32);
	h1.add(17);
	h1.add(23);
	h1.add(101);
	MaxHeap h3{h1};
	//std::cout << h1.size() << std::endl;

	std::cout << h1 << std::endl;
	h3.Max();
	h3.getHeight();
	/*
	101,
	32, 17,
	23, 25
	*/
	std::cout << "Parent is : " << h1.Parent(2) << std::endl; // 101
	std::cout << "Left Child is : " << h1.LeftChild(0) << std::endl;  // 32
	std::cout << "Right Child is : " << h1.RightChild(0) << std::endl;  // 17
    h1.Delete();


	int arr[7] {23, 1, 7, 52, 11, 10, 75};
	MaxHeap h2{arr, 7};
	std::cout << h2 << std::endl;
	h2.HeapSort();
	h2.printArray();
	std::cout << h2 << std::endl;



		
	return 0;
}

