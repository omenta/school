/* Name of Program: guessNumber
 * File: secretNumber.cpp
 * Purpose: Generates a secret number for user to guess what it is
 * Author: Amos Nyarongi
 * Date Created: January 12, 2016
 * Last Modified: April 02, 2016
 * Module 02: Arrays and Vectors
 *-----------------------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <math.h>
using namespace std;
vector<int>number; // this holds the secret number
vector<int>userNumber; // this holds the guess
int guess, tries = 0;
void hint();

void instructions(){
    cout<<"\n\tINSTRUCTIONS: This is a number guessing game."<<endl;
    cout<<"\tThe rules are simple: a 5-digit a secret number is generated"<<endl;
    cout<<"\tand you have to try and guess what it is. You have 10 tries"<<endl;
    cout<<"\tto get it right, and points are awarded according to how many"<<endl;
    cout<<"\ttries it takes you to guess the number. Fewer tries, mean"<<endl;
    cout<<"\tmore points! After each guess, I will give you a hint to help"<<endl;
    cout<<"\tyou with the guess. Here's how the hint works: "<<endl;
    cout<<"\t\t1 = Right Number, Right Place."<<endl;
    cout<<"\t\t2 = Right Number, Wrong Place."<<endl;
    cout<<"\t\t0 = Wrong Number."<<endl;
    cout<<"\tFor example: "<<endl;
    cout<<"\t\tIf the secret number is 12345, and your guess is 11235, "<<endl;
    cout<<"\t\tthe hint would be, 10221. Got it?"<<endl;
    cout<<"\n\t\t\t\t***GOOD LUCK!***"<<endl;
}
//generates random digit for each of the 5 digit secret number
void secretNumber() {
    srand(static_cast<unsigned int>(time(0)));
    int a = rand()%10;
    int b = rand()%10;
    int c = rand()%10;
    int d = rand()%10;
    int e = rand()%10;
    number.push_back(a);
    number.push_back(b);
    number.push_back(c);
    number.push_back(d);
    number.push_back(e);

}

//keep user score
int scores(){
    int score = 10 - tries;
    return  score;
}

//gives user feedback
void feedback(){
    if(scores() < 5){
        cout<<"You didn't do well!"<<endl;
    }
    else if(scores()>4 && scores() <9){
        cout<<"You did a good job!"<<endl;
    }
    else{
        cout<<"Outstanding Job!"<<endl;
    }
}

//prompts user to enter guess
void guessedNumber(){
    int rem;
    cout<<"\n\t\t\tSecret Number: * * * * *"<<endl;
    cout<<"\n\tWhat's your guess?";
    while(userNumber != number && tries <=10) {
        cout << "\n\t\tGuess: ";
        cin >> guess;
        for (int i = 0; i < 5; i++) {
            rem = guess % 10;
            guess = guess / 10;
            userNumber.push_back(rem);
        }
        reverse(userNumber.begin(), userNumber.end());
        if(userNumber != number && tries <=10) {

            cout << "\n\tTry again!";
            cout << "\n\tTries left: " << 9 - (tries);
            hint();
            tries++;
            cout<<endl;
            userNumber.clear(); //reset the user guess
        }
        else if (userNumber == number && tries <= 10) {
            cout << "\tYou guessed it correctly!" << endl;
            cout << "Score: " << scores() << endl;
        }
        else {
            cout << "\n\tYou couldn't guess it. Game Over!" << endl;
            cout << "\tThe secret number is: ";
            for (int i = 0; i < 5; i++) {
                cout << number[i] << " ";
            }
            cout << "\n\tScore: 0" << endl;
        }
    }
}


//generates a hint
void hint(){
    cout<<"\n\t\tYour Guess: ";
    for(int i=0;i<5;i++){
        cout<<userNumber[i]<<" ";
    }
    int hintDigit;
    cout<<"\n\t\t      Hint: ";
    for(int i = 0; i < 5; i++){
        if(userNumber[i]==number[i]){
            hintDigit = 1;
        }
        else if((find(number.begin(), number.end(), userNumber[i])!=number.end()) && (userNumber[i]!=number[i])){
            hintDigit = 2;
        }
        else{
            hintDigit = 0;
        }
        cout<<hintDigit<<" ";
    }
}

int main() {
    char again = 'y';
    instructions();
    while(again != 'n') {
        number.clear(); //resets secret number at the end of each game
        userNumber.clear(); //resets user guess at the end of each game
        tries = 0; // resets tries at the end of game
        secretNumber();
		
		//this portion of code can be turned on during debug to display secret number generated
        /*
         for (int i = 0; i < 5; i++) {
            cout << number[i] << " ";
        }
        */
		
        guessedNumber();
        feedback();
        again = 'y';
        //ask if user wants to play again
        cout<<"\n\tWould you like to play again? ";
        cin>>again;
    }

    return 0;
}
