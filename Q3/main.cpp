#include<iostream>
#include "Human.h"

int main(){

    human human1("kasra","khalafi",10,8,21,false,0);
    human human2("parsa","khalafi",9,5,21,false,0);
    human human3("kian","khalafi",6,7,26,false,0);
    std::cout << "first name of this human is : " << human1.getFirstName() << std::endl;
    std::cout << "last name of this human is : " << human1.getLastName() << std::endl;
    std::cout << "gender of this human is : " << human1.getGender() << std::endl;
    std::cout << "hair color of this human is : " << human1.getHairColor() << std::endl;
    std::cout << "eye color of this human is : " << human1.getEyeColor() << std::endl;
    std::cout << "age of this human is : " << human1.getAge() << std::endl;
    std::cout << "comparison of age is : " << (&human3 > &human1) << std::endl;
    std::cout << "comparison of these two humans : " << (&human1 == &human2) << std::endl;
    //std::cout << "random " << << " " << rand()%100 << std::endl;
    return 0;
}
