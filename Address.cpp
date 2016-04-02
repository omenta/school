/* Name of Program: Address
 * Purpose: Print out memory addresses for various data types
 * Author: Amos Nyarongi
 * Date Created: January 20, 2016
 * -------------------------------------------------------*/
#include <iostream>
#include "stdafx.h"

using namespace std;

int main() {
    char unit = 'm';
    string name = "Alvin";
    int numbers[]={1, 2, 3, 4, 5};
    int temperature = 75;
    double grade = 3.5;
    cout<<"\nCharacter has memory address "<<&unit;
    cout<<"\nString has a memory address "<<&name;
    cout<<"\nInteger has a memory address "<<&temperature;
    cout<<"\nDouble has a memory address "<<&grade;
    cout<<"\nArray numbers has the memory address "<<&numbers;
    cout<<"\nArray numbers[0] has the memory address "<<&numbers[0];
    cout<<"\nArray numbers[1] has the memory address "<<&numbers[1];
    cout<<"\nArray numbers[2] has the memory address "<<&numbers[2];
    cout<<"\nArray numbers[3] has the memory address "<<&numbers[3];
    cout<<"\nArray numbers[4] has the memory address "<<&numbers[4];

	system("pause");
    return 0;
}
