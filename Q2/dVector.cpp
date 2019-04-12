#include"dVector.h"
#include<iostream>
#include<cmath>

dVector::dVector(const dVector& vec) {//defining constructor
    array = new int[vec.cnt];//define the size of array dynamically
    cnt = vec.cnt;
    for (int i{} ; i < cnt - 1; ++i) { // filling the dynamic
        array[i] = vec.array[i];
    }
}

dVector::~dVector() {
    std::cout << "destructor" << std::endl;
    delete array;
}

dVector::dVector(dVector&& vec) { // move constructor
    std::cout << "move constructor " << std::endl;
    //delete array;
    cnt = vec.cnt;
    array = vec.array;
    vec.array = nullptr;
}

void dVector::push_back(int a){
    std::cout << a << " push backed" << std::endl;
    int* arrPrime;//arrPrime for saving the last ones
    arrPrime = new int[cnt - 1];
    for (int i{}; i < cnt - 1; i++) {
        arrPrime[i] = array[i];
    }
    delete array;//saved array in arrPrime and now delete array to use a new one with a size of one more than the lather
    array = new int[cnt];
    for (int i{}; i < cnt - 1; i++) {//filling the new size array with lather numbers
        array[i] = arrPrime[i];
    }
    array[cnt-1] = a;
    delete arrPrime;
    cnt++;//++ the cnt to add one to the size
}

void dVector::pop_back(){
    std::cout << "poped back! " << std::endl;
      int* arrPrime;//as same as push back!
      arrPrime = new int[cnt-1];
      for(int i{} ; i < cnt - 1 ; i++)
        {
          arrPrime[i] = array[i];
        }
      delete array;
      array = new int[cnt-1];
      for(int i{} ; i < cnt - 1 ; i++)//like the push back! but for deleting the last number
        {
          array[i] = arrPrime[i];
        }
      delete arrPrime;
      cnt--;
}

void dVector::size(){
  std::cout << (cnt-1) << std::endl;//i defined cnt one more than size! its default is ONE
}

int dVector::capacity(){
  int temp{};
  for(int i{} ; i < 50 ; i++)
        {
          if(cnt-1 < std::pow(2,i)){//using size and 2^n to find the n and return the 2^n
            temp = std::pow(2,i);
            break;
          }
        }
  return temp;
}

void dVector::show(){
    for(int i{0} ; i < cnt -1; i++)
        std::cout << array[i] << " " ;
    std::cout << std::endl;
}

dVector dVector::operator=(const dVector& vec) { //defined = to avoid dangling
    delete[] array;
    cnt = vec.cnt;
    array = new int[vec.cnt];
    for (int i{}; i < cnt - 1 ; ++i) {
        array[i] = vec.array[i];
    }
    return *this;
}


bool dVector::operator<(const dVector& dvec) const{
    if (this->cnt == dvec.cnt) {//checking size to be same
        bool cond = true;
        for (int i{0}; i < cnt-1; i++) {
            if (this->array[i] >= dvec.array[i]) {//if even one of arrays was larger change boolean to false
                cond = false;
                std::cout << i << " array is " << this->array[i] << " and dvec " << dvec.array[i] << std::endl;
                break;//break from for
            }
        }
        return cond;
    }
    else
    {
        std::cout << "this is unvalid , sizes are different " << std::endl;
        return false;
    }

  }

bool dVector::operator==(const dVector& dvec) const {
    if (this->cnt == dvec.cnt) {//checking for same size
        bool cond = true;
        for (int i{0}; i < cnt-1; i++) {
            if (this->array[i] != dvec.array[i]) {//if any of arrays did not match change boolean to false
                cond = false;
                std::cout << i << " array is " << this->array[i] << " and dvec " << dvec.array[i] << std::endl;
                break;//then break from for
            }
        }
        return cond;//return the true or false
    }
    else
    {
        std::cout << "this is unvalid , sizes are different " << std::endl;
        return false;
    }
}


dVector dVector::operator+(const dVector& dvec){//sum one bye one dVectors
  for(int i{} ; i < cnt-1 ; i++)
    {
      (*this).array[i] = (*this).array[i] + dvec.array[i];
    }
    return *this;
}

int dVector::operator*(const dVector& vec) const {
    if (this->cnt == vec.cnt)//checking for same size of dVectors
    {
        int sum{};
        for (int i{}; i < cnt - 1 ; ++i) {//summation of one by one multiply
            sum += this->array[i] * vec.array[i];
        }
        return sum;
    }
    else {//if sizes were not same returning zero
        std::cout << "sizes of two dVectors aren't same " << std::endl;
        return 0;
    }

}













