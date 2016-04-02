/* Name of Program: Pass by Value and by Reference
 * Purpose: Displays variable values after they are passed to functions by value and by reference
 * Author: Amos Nyarongi
 * Date Created: January 20, 2016
 * -------------------------------------------------*/

#include <iostream>
#include "stdafx.h"
using namespace std;

//pass by value function
string byValue(string name1){
    name1 = "Thomas";
    cout<<name1;
    return name1;
}

//pass by reference function
string byReference(string &name1){
    name1="James";
    cout<<name1;
    return name1;
}

int main() {
    string name1 = "Barry"; //variable initialized with value "Barry"

    cout<<"\n\tVariable has the value of "<<name1<<endl;
    cout<<"\n\tCalling pass by value..."<<endl;
    cout<<"\tParameter now has the value ";
    byValue(name1);

    cout<<"\n\tpass by value returned "<<endl;
    cout<<"\tVariable name has the value "<<name1<<endl;
    cout<<"\n\tcalling pass by references..."<<endl;
    cout<<"\tParameter now has the value ";
    byReference(name1);
    cout<<"\n\tcall by reference returned "<<endl;
    cout<<"\tVariable name has the value "<<name1;


    system("pause");
    return 0;
}
