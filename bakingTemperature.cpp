/*
 * Author: Amos Nyarongi
 * Programming II
 * Project: Module 01
 * Date Created: Jan 04, 2016
 * Last Updated: April 04, 2016
 * ----------------------------------*/

#include <iostream>
using namespace std;

int temperature=0; // temperature setting entered
int numDigits();
void instructions();
bool containsDigit(int number, int digit);

int main() {
    char again = 'y';
    int firstDigit=0, secondDigit=0, thirdDigit=0;
    int displayedTemp=0; // temperature that is displayed after adjusting for faulty keys

    instructions();
    while(again !='n') {
        //prompt user to enter temperature
        cout << "\n\tPlease enter a temperature setting: ";
        cin >> temperature;
        //keep asking until temperature in correct range is entered
        while (temperature < 0 || temperature > 999) {
            temperature=0;
            cout << "\tInvalid entry! Please enter a number between 0 and 999: ";
            cin >> temperature;
        }

        //determine if one of the entered keys is faulty
        if(containsDigit(temperature, 1) || containsDigit(temperature, 4) || containsDigit(temperature, 7)) {

            // iterate over number of digits entered
            switch (numDigits()){
                case 1:
                    //there's one key, entered and happens to be faulty therefore, the display is adjusted
                    displayedTemp = temperature + 1;
                    cout << "\tCooking temperature adjusted to: " << displayedTemp << " degrees.";
                    break;
                case 2:
                    firstDigit = temperature/10;
                    secondDigit = temperature%10;
                    //faulty key is the first digit of entered temperature therefore adjust the display accordingly
                    if(firstDigit == 1 || firstDigit == 4 || firstDigit == 7){
                        cout<<firstDigit<<endl; //TEMP
                        cout<<secondDigit<<endl; //TEMP
                        displayedTemp =((temperature/10) + 1) * 10;
                        cout << "\tCooking temperature adjusted to: " << displayedTemp << " degrees.";
                    }
                        //faulty key is the second digit of entered temperature, adjust the display accordingly
                    else if(secondDigit==1 || secondDigit == 4 || secondDigit == 7){
                        displayedTemp = (firstDigit * 10 + (secondDigit + 1)); //second digit is the faulty one
                        cout << "\tCooking temperature adjusted to: " << displayedTemp << " degrees.";
                    }
                    break;
                case 3:
                    firstDigit = temperature/100;
                    secondDigit = (temperature/10)%10;
                    thirdDigit = temperature%10;
                    //faulty key is the first digit of the entered temperature
                    if(firstDigit == 1 || firstDigit == 4 || firstDigit == 7){
                        displayedTemp = (firstDigit + 1) * 100;
                        cout << "\tCooking temperature adjusted to: " << displayedTemp << " degrees.";
                    }
                        //first key is the second
                    else if(secondDigit==1 || secondDigit == 4 || secondDigit == 7){
                        displayedTemp = (firstDigit * 100) + ((secondDigit + 1) * 10);
                        cout << "\tCooking temperature adjusted to: " << displayedTemp << " degrees.";
                    }
                        //faulty key is the third digit of entered temperature
                    else{
                        displayedTemp = (firstDigit * 100) + (secondDigit * 10) + (thirdDigit + 1);
                        cout << "\tCooking temperature adjusted to: " << displayedTemp << " degrees.";
                    }
                    cout<<"three digits"<<endl;
                    break;
                default:
                    cout<<"Error occured! Try again."<<endl; //this should never happen
                    break;
            }
        }
        else{ //no faulty digits entered, display the entered temperature
            displayedTemp = temperature;
            cout << "\tCooking temperature set to: " << displayedTemp << " degrees.";
        }

        //ask if user wants to enter a different temperature
        again = 'n';
        cout<<"\n\n\tWould you like to enter a different temperature?[y/n]: ";
        cin>>again;
    }

    system ("pause"); //works windows only!
    return 0;
}

//function to determine if the entered temperature contains digit from faulty keys(1, 4, 7)
bool containsDigit(int number, int digit)
{
    int x=0, y=0, z=0;
    if(numDigits()==1){
        x = number;
        return x == digit;
    }
    else if(numDigits()==2){
        x = number/10;
        y = number%10;
        return x == digit || y == digit;
    }
    else{
        x = number/100;
        y = (number/10)%10;
        z = number%10;
        return x == digit || y == digit || z == digit;
    }
}

//this function displays the instructions for the program
void instructions(){
    cout<<"\n\tINSTRUCTIONS: This program takes in baking temperature entered by user on"<<endl;
    cout<<"\ta phone-like keypad on oven and displays it on the screen. Unfortunately"<<endl;
    cout<<"\tthe keys 1, 4 and 7 are faulty and therefore when entered, the program "<<endl;
    cout<<"\twill display the next largest integer in place of the faulty key."<<endl;
}

//determine the number of digits of the temperature entered
int numDigits(){
    int digits;
    if(temperature < 10){
        digits = 1;
    }
    else if(temperature < 100 && temperature > 9){
        digits = 2;
    }
    else{
        digits = 3;
    }
    return digits;
}
