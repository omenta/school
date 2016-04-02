// LateBinding.cpp : Defines the entry point for the console application.
//
/* LateBinding.cpp
* Purpose: Demonstrates how polymorphism works
* Author: Amos Nyarongi
* Date Created: February 06 2016
* Last Modified: April 02, 2016
* ------------------------------------------------*/

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Person {
protected:
    string name, address, city, state, phoneNumber;
    int zip;
public:
    //Default constructor
    Person() :
            name("Dalyton Nunda"),
            address("186 E Howard St"),
            city("Winona"),
            state("MN"),
            zip(55987),
            phoneNumber("507-313-4022")
    {}
    virtual void display();
};
/*Person display function to display the values*/
void Person::display() {
    cout << "\tName:    " << name << endl;
    cout << "\tAddress: " << address << endl;
    cout << "\tCity:    " << city << endl;
    cout << "\tState:   " << state << endl;
    cout << "\tZip:     " << zip << endl;
    cout << "\tPhone:   " << phoneNumber << endl;
}
/* Student class that inherits from the person class*/
class Student : public Person {
protected:
    string course;
    char grade;
    double GPA;

public:
    //constructor
    Student() :
            course("Psychology"),
            grade('A'),
            GPA(3.5)
    {}
    virtual void display(){
        cout<<"Student:"<<endl;
        Person::display();
        cout << "\tGrade:   " << grade << endl;
        cout << "\tCourse:  " << course << endl;
        cout << "\tGPA:     " << GPA << endl;
    };
};


/*Professional class that inherits from the Person class*/
class Professional : public Person {
private:
    string profession;
    int experience;
public:
    // Constructor
    Professional () :
            profession("Doctor"),
            experience(11)
    {}

    virtual void display(){
        cout<<"Professional:"<<endl;
        Person::display();
        cout << "\tProfession:    " << profession << endl;
        cout << "\tYears of experience: " << experience << endl;
    }
};

int main() {

    Person *person1 = new Person();
    Student *student1 = new Student();
    Professional *professional1 = new Professional();

    cout<<"Person: "<<endl;
    person1->display();
    student1->display();
    professional1->display();

    system("Pause");

    return 0;
}
