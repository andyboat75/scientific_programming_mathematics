#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>

using std::cout;
using std::string;
using std::cin;
using std::endl;

//Define Class

class University {
private:
    string name;
    string city;
    int num_students;

public:
    void setName(string);

    void setCity(string);

    void setNum_students(int);

    string getName();

    string getCity();

    int getNum_students();

    void graduate();

    void newStudent();

};

//Define Functions

void University::setName(string Name) {
    name = Name;
}

void University::setCity(string City) {
    city = City;
}

void University::setNum_students(int NUM) {
    num_students = NUM;
}

string University::getName() {
    return name;
}

string University::getCity() {
    return city;
}

int University::getNum_students() {
    return num_students;
}

void University::graduate() {
    num_students = num_students - 1;
    assert(num_students >= 0);
}

void University::newStudent() {
    num_students = num_students + 1;
    assert(num_students >= 0);
}