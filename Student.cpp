// Student.cpp : Defines the entry point for the console application.
//
/* File: Student.cpp
 * Author: Amos Nyarongi
 * Date Created: January 26, 2014
 * Last Modified: April 02, 2016
 *-------------------------------------*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//Students class
class Student {
private:

	// Member Variables
	string studentName;
	int phoneNumber;
	int studentNumber;
	double GPA;

public:
	void displayValues();

	// Default constructor with default values
	Student() {
		studentName = "Adalynn";
		phoneNumber = 507555555;
		studentNumber = 12;
		GPA = 3.2;
	}

	// Non-Default Constructor
	Student(string studentName, int phoneNumber, int studentNumber, double GPA) {
		this->studentName = studentName;
		this->phoneNumber = phoneNumber;
		this->studentNumber = studentNumber;
		this->GPA = GPA;
	}

	// Destructor
	~Student() {}
};

// Member function to display the values
void Student::displayValues() {
	cout << "\tStudent Name: " << studentName << endl;
	cout << "\tStudent Phone Number: " << phoneNumber << endl;
	cout << "\tStudent Number: " << studentNumber << endl;
	cout << "\tStudent GPA: " << GPA << endl;
}

// Main function
int main() {
	//Two objects declared
	Student student1;
	Student student2("Olivia", 952555777, 25, 3.7);

	//Display variables to output screen
	cout << "Student 1: " << endl;
	student1.displayValues();
	cout << "Student 2: " << endl;
	student2.displayValues();

	system("pause");
	return 0;
}
