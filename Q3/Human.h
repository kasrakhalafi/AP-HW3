#include<iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class human{
public:
    human(std::string firstName,std::string lastName,int hairColor, int eyeColor, int age, bool gender, int numberOfChildren);
    std::string getFirstName();
    std::string getLastName();
    bool getGender();
    int getHairColor();
    int getEyeColor();
    int getAge();
    bool operator>(human*);
    bool operator==(human*);
    human*operator+(human*);
    void operator++();
    bool isChildOf(human*);
    bool isFatherOf(human*);
    bool isMotherOf(human*);
    void printChildren();
protected:
private:
    std::string boyName[6]{"mohammad","ali","hossein","milad","amin","mehdi"};
    std::string girlName[6]{"fatemeh","zahra","mohaddeseh","shahla","zeinab","shokoofeh"};
    std::string firstName,lastName;
    human* father;
    human* mother;
    human* spouse;
    human* children;
    int hairColor,eyeColor,age,numberOfChildren;
    bool gender;
};
