#include "Human.h"

human::human(std::string firstName,std::string lastName,int hairColor, int eyeColor, int age, bool gender, int numberOfChildren) {
  this->firstName=firstName;
  this->lastName=lastName;
  this->hairColor=hairColor;
  this->eyeColor=eyeColor;
  this->age = age;
  this->gender = gender;
  this->numberOfChildren = numberOfChildren;
}

bool human::getGender() {//returning gender
    return this->gender;
}

std::string human::getLastName() {//returning last
    return lastName;
}

std::string human::getFirstName() {//returning first name
    return firstName;
}

int human::getHairColor() {//returning hair color
    return hairColor;
}

int human::getEyeColor() {//returning eye color
    return eyeColor;
}

int human::getAge() {//returning age
    return age;
}

bool human::operator>(human* human1) {//checking the ages
    return this->age > human1->age;
}

bool human::operator==(human* human1) {//checking the two people to be same
    return ((this->firstName == human1->firstName) && (this->lastName == human1->lastName) && (this->age == human1->age) &&
    (this->hairColor == human1->hairColor) && (this->eyeColor == human1->hairColor) && (this->gender == human1->gender) &&
    (this->numberOfChildren == human1->numberOfChildren));

}

human* human::operator+(human* human1) {//making child!!
    if(this->spouse == human1){//checking to be sposes together
        srand((unsigned)time(0));
        bool gender = static_cast<bool>(rand()%2);//random making a male or female gender
        std::string name;
        if (gender == 0)
            name = boyName[rand()%5];//if male choosing a masculine name from boyName
        else
            name = girlName[rand()%5];//if female choosing a feminine name
        std::string lastName;
        if (human1->gender == 0)//checking for husband to name the child's last name to his or her father last name
            lastName = human1->lastName;
        else
            lastName = this->lastName;
        int hair = rand()%9;
        int eye = rand() % 9;
        int childNum{0};
        int childAge{0};
        human* human2 = new human(name,lastName, hair, eye,childAge,gender,childNum);
        return human2;
    }
    else//when two people are not married
    {
        return nullptr;
    }
}

void human::operator++() {//adding an age to the age of human
    age+=1;
}

bool human::isChildOf(human* human1) {
    if (human1 == mother)//checking to be mother of the child or not
        return true;
    else if (human1 == father)//checking to be father of the child
        return true;
    else//when non of above is true
        return false;

}

bool human::isFatherOf(human *human1) {
    if (this->father == human1->father)//checking to be father or not
        return true;
    else
        return false;
}

bool human::isMotherOf(human *human1) {//checking to be mother or not
    if (this->mother == human1->mother)
        return true;
    else
        return false;
}

void human::printChildren() {
    std::cout << children << std::endl;
}


