// UseOfSTLs.cpp : Defines the entry point for the console application.
/* Author: Amos Nyarongi
 * Date Created: March 06, 2016
 * Last Updated: April 02, 2016
 -------------------------------------------------------------------*/
#include "stdafx.h"
#include<iostream>
#include<list>
#include<algorithm>
#include<string>
using namespace std;
struct StudentInfo
{
	string name;
	int grade;
	//need to overload the > operator here
	friend bool operator > (StudentInfo &s1, StudentInfo &s2) {
		return s1.name>s2.name;
	}
	friend bool operator<(StudentInfo &s1, StudentInfo &s2) {
		return s1.name<s2.name;
	}
};

void populateStudentRecord(list<StudentInfo > &array) {
	StudentInfo S = { "\tAmos",94 };
	array.push_back(S);
	S.name = "\tBecca"; S.grade = 87;
	array.push_back(S);
	S.name = "\tAdalynn"; S.grade = 79;
	array.push_back(S);
	S.name = "\tOlivia"; S.grade = 88;
	array.push_back(S);
	S.name = "\tSierra"; S.grade = 84;
	array.push_back(S);
}
// In the main() function:
int main() {
	// Create a list of objects of StudentInfo type.
	cout << "\n\t-----------------------------" << endl;
	cout << "\t\tStudent Info" << endl;
	cout << "\t-----------------------------" << endl;
	list<StudentInfo> array;
	// Call the populateStudentRecord() to populate the list object.
	populateStudentRecord(array);
	// Use the built-in sort algorithm from STL to sort the list by name and display the information in this format "name - grade". Remember, you need to overload the < operator for the structure so that the StudentInfo structure type variables can be compared.
	array.sort();
	// Calculate the maximum and minimum grades and the class average and display them.
	list<StudentInfo>::iterator it = array.begin();
	int max = (*it).grade;
	int min = (*it).grade;
	double sum = 0;
	int count = 0;
	for (it = array.begin(); it != array.end(); it++) {
		cout << (*it).name << " - " << (*it).grade << endl;
		if ((*it).grade > max) max = (*it).grade;
		else if ((*it).grade < min) min = (*it).grade;
		sum += (*it).grade;
		count++;
	}
	cout << "\n\tMaximum grade is " << max << endl;
	cout << "\tMinimum grade is " << min << endl;
	cout << "\tAverage is " << (sum / count) << endl;
	cout <<"\t=============================\n"<< endl;

	system("pause");
	return 0;
}
