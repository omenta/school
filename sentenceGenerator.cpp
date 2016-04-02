/* File: sentenceGenerator.cpp
 * Module 05 - Sentence Generator
 * Author: Amos Nyarongi
 * Date Created: November 04, 2015
 * Last Modified: April 02, 2016
 *-----------------------------------*/

#include<iostream>
using namespace std;
int main() {

     cout<<"\nDESCRIPTION:"<<endl;
     cout<<"\tThis program makes a sentence of the form <subject>+<verb>+<object>"<<endl;
     cout<<"\tby picking a random subject, random verb and random object"<<endl;
     cout<<"\tfrom the arrays of nouns, verbs and objects below. Each array contains"<<endl;
     cout<<"\t5 string elements."<<endl;

    int sentences;

    // declare 3 arrays each of 5 string elements
    string nouns[5] = {"Mary", "Jonas", "Reuben", "Sarah", "Ben"};
    string verbs[5] = {"knows", "loves", "likes", "studies", "hates"};
    string objects[5] = {"Math", "piano", "acting", "people", "driving"};

    srand(time(NULL)); //seeds the random number

    //ask the user how many sentences they want to write
    cout << "\nHow many sentences do you want to print?" << endl;
    cin >> sentences;
    for (int i = 0; i < sentences; i++) {

        //generate random number for each array to pick out a random element
        string noun = nouns[rand() % 5];
        string verb = verbs[rand() % 5];
        string object = objects[rand() % 5];

        //output the sentence
        cout << noun << " " << verb << " " << object << "." << endl;
    }
    system ("pause");
    return 0;
}
