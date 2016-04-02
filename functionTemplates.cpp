/* File: functionTemplates.cpp
 * Purpose: demonstrates the use of class templates
 * Author: Amos Nyarongi
 * Date created: February 25, 2016
 * Last Updated: April 02, 2016
 * -----------------------------------------------------*/
#include "stdafx.h"
#include <iostream>
using namespace std;

class Trip{
public:
    int length;
    Trip(int l){
        length = l;
    }
    bool operator<(Trip &T){
        return length < T.length;
    }
};

template <class T>
T findLargerValue(T one, T two){
    if(one < two){
        return two;
    }
    else{
        return one;
    }
}

//instructions function to explain what the program is supposed to do
void instructions(){
    cout<<"\nThis program demonstrates the use of class templates."<<endl;
    cout<<"When given two values, it will return the larger of "<<endl;
    cout<<"the two values."<<endl;
    cout<<"The program compares: "<<endl;
    cout<<"\t\t1. Two integer values"<<endl;
    cout<<"\t\t2. Two double values"<<endl;
    cout<<"\t\t3. Two Trip objects"<<endl;
    cout<<"*Note: I haven't implemented any input validation so enter the "<<endl;
    cout<<"values and types correctly, otherwise restart the program."<<endl;

}

int main(){
    instructions();
    int a, b;
    cout<<"\nIntegers: "<<endl;
    cout<<"\tEnter the first integer: ";
    cin>>a;
    cout<<"\tEnter the second integer: ";
    cin>>b;
    cout << "Larger integer is " << findLargerValue(a, b) << endl;
    double c, d;
    cout<<"\nDoubles: "<<endl;
    cout<<"\tEnter the first double: ";
    cin>>c;
    cout<<"\tEnter the second double: ";
    cin>>d;
    cout << "Larger double is " << findLargerValue(c, d) << endl;
    Trip T1(5), T2(3);
    cout<<"\nFinally for Trip Values: "<<endl;
    cout<<"Say T1(5) and T2(3)"<<endl;
    cout << "Larger Trip value is " << findLargerValue(T1, T2).length << endl;

    system("pause");
    return 0;
}
