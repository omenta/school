/* File: highestScore.cpp
 * Module 02 - Gathering Scores
 * Author: Amos Nyarongi
 * Date Created: October 14, 2015
 * Last Modified: April 02, 2016
 *----------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

int highestScore() {
    cout << "Welcome to the Score Viewer Program!\n" << endl;

    //declare variables
    string player1, player2, player3;
    int player1Score = 0, player2Score = 0, player3Score = 0, highestScore = 0, tie = 0;

    //get the player and score input
    cout << "Please enter the player names and scores...\n"<<endl;
    cout << "Player1 Name: ";
    cin >> player1;
    cout << "Enter " << player1 << "'s score: ";
    cin >> player1Score;

    //makes sure the score is greater than 0 and an integer
    while (player1Score < 0 || cin.fail()) {
	cin.clear();
        cin.ignore();
        player1Score = 0;
	cout << "The score you entered is invalid. Please try again: "<<endl;
	cout << "Enter "<< player1<< "'s score: ";
	cin >> player1Score;
    }

    cout << "Player2 Name: ";
    cin >> player2;

    //makes sure you don't enter two similar names
    while (player2 == player1) {
	cin.clear();
        cin.ignore();
	cout << "You already used that name. Please use a different name. "<<endl;
	cout << "Player2 Name: ";
	cin >> player2;
    }
    cout << "Enter " << player2 << "'s score: ";
    cin >> player2Score;
    while (player2Score < 0 || cin.fail()) {
	cin.clear();
	cin.ignore();
	cout << "The score you entered is invalid. Please try again: "<<endl;
	cout << "Enter " << player2 << "'s score: ";
	cin >> player2Score;
    }

    cout << "Player3 Name: ";
    cin >> player3;
    while (player3 == player1 || player3 == player2) {
	cin.clear();
        cin.ignore();
	cout << "You already used that name. Please use a different name." << endl;
	cout << "Player3 Name: ";
	cin >> player3;
    }
    cout << "Enter " << player3 << "'s score: ";
    cin >> player3Score;
    while (player3Score < 0 || cin.fail()) {
	cin.clear();
	cin.ignore();
	cout << "The score you entered is invalid. Please try again: " << endl;
	cout << "Enter " << player3 << "'s score: ";
	cin >> player3Score;
    }


    //determine the highest score
    if (player1Score > player2Score)
    {
	if (player1Score > player3Score)
        {
            highestScore = player1Score;
        }
    }
    else if (player2Score > player1Score)
    {
	if (player2Score > player3Score)
        {
            highestScore = player2Score;
        }
    }
    else if (player3Score > player1Score)
    {
	if (player3Score > player2Score)
	{
            highestScore = player3Score;
	}
    }
    //this checks if there's a tie in the score
    else if (highestScore == player1Score == player2Score
	|| highestScore == player1Score == player3Score
	|| highestScore == player2Score == player3Score)
    {
	highestScore = tie;
    }
    else
    {
        cout<<"Unable to calculate high score."<<endl;
        cout<<"Please check your values and try again."<<endl;
    }

    //display scores summary
    cout << "\nHere's the score summary: " << endl;
    cout << player1 << " scored " << player1Score << endl;
    cout << player2 << " scored " << player2Score << endl;
    cout << player3 << " scored " << player3Score << endl;

    //output for the highest score
    if (highestScore == player1Score) {
        cout << player1 << " has the highest score of " << player1Score << endl;
	}
    else if (highestScore == player2Score) {
		cout << player2 << " has the highest score of " << player2Score << endl;
    }
    else if (highestScore == player3Score) {
	cout << player3 << " has the highest score of " << player3Score << endl;
    }
    else if (highestScore == tie) {
	if (player1Score == player2Score  //this checks if the tie score is among all players
		&& player2Score == player3Score
		&& player3Score == player1Score) {
		highestScore = player1Score = player2Score = player3Score;
            cout << "No high score, all players are tied at " << highestScore << endl;
	}
        else if (player1Score == player2Score) {
            highestScore = player2Score = player1Score;
            cout << player1 << " is tied with " << player2 << " for high score of " << highestScore << endl;
	}
	else if (player2Score == player3Score) {
            highestScore = player2Score = player3Score;
            cout << player2 << " is tied with " << player3 << " for high score of " << highestScore << endl;
	}
	else if (player3Score == player1Score) {
            highestScore = player3Score = player2Score;
            cout << player2 << " is tied with " << player3 << " for high score of " << highestScore << endl;
	}
	else {
            cout << "There was an error getting the scores! Please try again." << endl;
	}
    }
    else {
        cout << "Error getting highest score! Please try again." << endl;
	}

    //this pauses the program at the end of execution. Only works on windows!
    system("pause");
    return 0;
}
