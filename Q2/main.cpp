#include<iostream>
#include<utility>
#include <memory>
#include"dVector.h"

using namespace std::rel_ops;
dVector done(int);


int main(){
    dVector dVector1{};
    dVector dVector3{};
    dVector1.push_back(1);
    dVector1.push_back(2);
    dVector1.push_back(5);
    dVector dVector2{dVector1};
    dVector dVector4{done(1)};
    //dVector2 = dVector1;
    std::cout << (dVector1*dVector2) << std::endl;
    dVector3 = dVector1 + dVector2;
    dVector2.pop_back();
    dVector2.show();
    dVector3.show();
    dVector4.show();
    std::cout << dVector3.capacity() << std::endl;
    dVector3.size();

return 0;
}


dVector done(int n){
    dVector a{};
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    dVector b{a};
    if (n == 1)
        return a;
    else
        return b;
}