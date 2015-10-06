//
// Name of Program: Number Crunch
// Purpose: Adds and Displays Some Math
// Author: Amos Nyarongi
// Date Created: October 06, 2015
//
#include <iostream>
using namespace std;
int main()
{
    cout<<"\t\t\nWelcome to the Number Crunch Program!\n\n";

    //variables to hold the answers to calculations
    int answer1 = 8 + 5;
    int answer2 = 8 - 2;
    int answer3 = 8 * 4;
    int answer4 = 8 / 5;
    double answer5 = 8.0/2.0;
    int answer6 = 8 % 5;
    int answer7 = 8 + 4 * 5;
    int answer8 = (8 + 4) * 5;

    //displaying to the output
    cout<<"8 + 5 = "<<answer1<<endl;
    cout<<"8 - 2 = "<<answer2<<endl;
    cout<<"8 * 4 = "<<answer3<<endl;
    cout<<"8 / 5 = "<<answer4<<endl;
    cout<<"8.0 / 2.0 = "<<answer5<<endl;
    cout<<"8 % 5 = "<<answer6<<endl;
    cout<<"8 + 4 * 5 = "<<answer7<<endl;
    cout<<"(8 + 4) * 5 = "<<answer8<<endl;
    cout<<"Thank you for using the program!\n";

    //prompt the user to exit program
    cout<<"\tPress 'ENTER' to exit the program...";
    cin.get();
    return 0;
}
