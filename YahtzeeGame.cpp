/* 
 * File: yahtzee.cpp
 * Author: Amos Nyarongi
 * Module 07 - Yatzee
 * Date Created: November 22, 2015
 * Last Updated: April 02, 2016
 .....................................*/
#include stdafx.h //not sure if it works on mac
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;
int rollDie(long t2);
int main(){

    //random number generator seeder
    srand(time(NULL));

    // stores scores
    vector<pair<int, string> > playerScores;


    // Welcome message and Game Rules
    cout << "\n\t\t•••••••••••• Welcome To Yahtzee! ••••••••••••••\n";
    cout << "\n    GAME RULES: The game has 13 rounds. Players take turns rolling ";
    cout << "\n    five dice to try and score with different combinations. There are 3 ";
    cout<<  "\n    rolls for each turn. For each roll, ";
    cout << "\n    roll, the player may choose to keep any number of dice he/she wishes.";
    cout << "\n    The object of the game is to fill every possible scoring combination,";
    cout << "\n    and the player with the highest total score wins! For each round, each";
    cout << "\n    player must enter a score into one of the combinations. The player may";
    cout << "\n    enter a 0 into any box if he or she does not wish to enter a score for";
    cout << "\n    the current dice combination left at the end of the turn.";
    cout << "\n\n                       Have fun!!!" << endl;
    cout <<"\n••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••";

    // Game loop. Initializes game to Y.
    string playAgain = "Y";
    while(playAgain == "Y")
    {
        // Prompt for, and input number of players
        int numOfPlayers = 0;
        cout << "\n\n\tPlease enter the number of players(1-4): ";
        cin >> numOfPlayers;

        // If player(s) have entered invalid number of players, prompt to enter again.
        while((numOfPlayers >= 5) || (numOfPlayers <= 0))
        {
            cout << "\n\tSorry, 4 is the max number of players.";
            cout << "\n\tPlease enter the number of players (1-4): ";
            cin >> numOfPlayers;
        }

        // this vector stors player names
        vector<string> names;

            // Prompts for names in a multiplayer game in order that turns will be played. Stores each name in vector "names."
            // cout << "\n\n\tEnter name(s) in the order they take their turn." << endl;
            for(int i = 0; i < numOfPlayers; i++)
            {
                string name;
                cout << "\n\tPlease enter player " << (i+1) << "'s name: ";
                cin >> name;
                names.push_back(name);
            }
        //}

        /*
        * Arrays track player's score. scoreComb ensures player cannot enter score into same
         * score category more than once and combPoints stores the points for each category.
        * For loop and nested For loop initialize arrays, and set all categories to false,
         * or unused for each player, and to -1 (1-4).
        */
        bool scoreComb[4][13];
        int combPoints[4][13];
        for(unsigned int j = 0; j < 4; j++)
        {
            for(unsigned int k = 0; k < 13; k++)
            {
                scoreComb[j][k] = false;
                combPoints[j][k] = 0;
            }
        }

        // calculates yatzee bonus
        bool yahtzeeBonus[4];
        for(unsigned int i = 0; i > 4; i++)
        {
            yahtzeeBonus[i] = 0;
        }

        // max number of rounds in a game
        const int MAX_ROUNDS = 13;
        int round = 1;

        while(round <= MAX_ROUNDS)
        {
            // loops though players' turns.
            for(int i = 0; i < numOfPlayers; i ++)
            {
                // "keepers" used to determine which dice are held, and which to re-roll.
                // create array of int, or 'dice,' for the game to use.
                string keepers;
                int die[5];
                cout << "\n\n\t\t•••"<< names[i] << "'s turn•••" << endl;
                cout << "\n\n\t\t     First roll results: \n\n";

                // for loop calls rollDie() function and iterates through all dice to create first roll.
                for(int j = 0; j < 5; j++)
                {
                    die[j] = rollDie(time(NULL));
                }

                // print roll results prompt user to enter 1s or 0s based dice they want to keep.
                cout << "\t\t        " << die[0] << " " << die[1] << " " << die[2] << " " << die[3] << " " << die [4];
                cout << "\n\n\n   Which dice would you like to keep?";
                cout << "\n   Enter 1 to keep, or 0 to re-roll. \n\t(e.g. 10101 re-rolls die 2 and 4): \n"<<endl;
                cin >> keepers;

                // For loop iterates through each character of the string, keepers, checking for a 1, or hold this die.
                // If a 1 is found, loop does not roll a new number for that die. Otherwise, new number is found for each die rolled.
                for(unsigned int j = 0; j < 5; j++)
                {
                    if(keepers[j] != '1')
                    {
                        die[j] = rollDie(time(NULL));
                    }
                }

                // Print player's second roll, prompt for the string keepers to determine which die should be held.
                cout << "\n\n\t\t        Your second rolls are: ";
                cout << "\n\n\t\t        " << die[0] << ' ' << die[1] << ' ' << die[2] << ' ' << die[3] << ' ' << die[4];
                cout << "\n\n   Select '1' or '0' for keep, or re-roll as before: ";
                cin >> keepers;

                // Roll all die that are not selected as keeper with the number 1
                for(unsigned int j = 0; j < 5; j++)
                {
                    if(keepers[j] != '1')
                    {
                        die[j] = rollDie(time(NULL));
                    }
                }
                // Prints player's final roll.
                cout << "\n\n\t\t        Your final dice combination is: ";
                cout << "\n\n\t\t        " << die[0] << ' ' << die[1] << ' ' << die[2] << ' ' << die[3] << ' ' << die[4];

                //Scoring category list
                cout << "\n\n\tEnd of "<<names[i]<<"'s turn."<<endl;
                cout << "======================================"<<endl;
                cout << "\n\tScore Board: ";
                cout << "\n\n\t---:Upper Section:---";
                cout << "\n\t1)•••Aces••••••••••••: "<<combPoints[i][1];
                cout << "\n\t2)•••Twos••••••••••••: "<<combPoints[i][2];
                cout << "\n\t3)•••Threes••••••••••: "<<combPoints[i][3];
                cout << "\n\t4)•••Fours•••••••••••: "<<combPoints[i][4];
                cout << "\n\t5)•••Fives•••••••••••: "<<combPoints[i][5];
                cout << "\n\t6)•••Sixes•••••••••••: "<<combPoints[i][1];
                cout << "\n\t---:Lower Section:---";
                cout << "\n\t7)•••3 of a Kind•••••: "<<combPoints[i][7];
                cout << "\n\t8)•••4 of a Kind•••••: "<<combPoints[i][8];
                cout << "\n\t9)•••Full House••••••: "<<combPoints[i][9];
                cout << "\n\t10)•••Small Straight•: "<<combPoints[i][10];
                cout << "\n\t11)•••Large Straight•: "<<combPoints[i][11];
                cout << "\n\t12)•••YAHTZEE!•••••••: "<<combPoints[i][12];
                cout << "\n\t13)•••Chance•••••••••: "<<combPoints[i][13]<<endl;
                cout << "====================================="<<endl;

                // declare variable option, prompt user for selection, assign selection.
                // Try again statement defines goto position (back to choice) if
                // selection has already been used.
                tryAgain:
                int option;
                cout << "\n\n\tPick category to score this turn to: ";
                cin >> option;

                // Switch handles user selection for score category input
                // goto statements return game back to choice for switch if category has already been used.
                switch(option)
                {
                    case 1:
                        if(scoreComb[i][1] == true)
                        {
                            cout << "\n\tAces have already been scored.";
                            goto tryAgain;
                        }
                        else
                        {
                            cout << "\n\tEnter the sum of all the ONES in your hand, or a 0: ";
                            cin >> combPoints[i][1];
                            scoreComb[i][1] = true;
                            break;
                        }
                    case 2:
                        if(scoreComb[i][2] == true)
                        {
                            cout << "\n\tTwos have already been scored.";
                            goto tryAgain;
                        }
                        else
                        {
                            cout << "\n\tEnter the sum of all TWOS in your hand, or a 0: ";
                            cin >> combPoints[i][2];
                            scoreComb[i][2] = true;
                            break;
                        }
                    case 3:
                        if(scoreComb[i][3] == true)
                        {
                            cout << "\n\tThrees have already been scored.";
                            goto tryAgain;
                        }
                        else
                        {
                            cout << "\n\tEnter the sum of all the THREES in your hand, or a 0: ";
                            cin >> combPoints[i][3];
                            scoreComb[i][3] = true;
                            break;
                        }
                    case 4:
                        if(scoreComb[i][4] == true)
                        {
                            cout << "\n\tFours have already been scored.";
                            goto tryAgain;
                        }
                        else
                        {
                            cout << "\n\tEnter the sum of all the FOURS in your hand, or a 0: ";
                            cin >> combPoints[i][4];
                            scoreComb[i][4] = true;
                            break;
                        }
                    case 5:
                        if(scoreComb[i][5] == true)
                        {
                            cout << "\n\tFives have already been scored.";
                            goto tryAgain;
                        }
                        else
                        {
                            cout << "\n\tEnter the sum of all the FIVES in your hand, or a 0: ";
                            cin >> combPoints[i][5];
                            scoreComb[i][5] = true;
                            break;
                        }
                    case 6:
                        if(scoreComb[i][6] == true)
                        {
                            cout << "\n\tSixes have already been scored.";
                            goto tryAgain;
                        }
                        else
                        {
                            cout << "\n\tEnter the sum of all the SIXES in your hand, or a 0: ";
                            cin >> combPoints[i][6];
                            scoreComb[i][6] = true;
                            break;
                        }
                    case 7:
                        if(scoreComb[i][7] == true)
                        {
                            cout << "\n\t3 of a Kind has already been scored.";
                            goto tryAgain;
                        }
                        else
                        {
                            cout << "\n\tEnter the sum of all dice in your hand, or a 0: ";
                            cin >> combPoints[i][7];
                            scoreComb[i][7] = true;
                            break;
                        }
                    case 8:
                        if(scoreComb[i][8] == true)
                        {
                            cout << "\n\t4 of a Kind has already been scored.";
                            goto tryAgain;
                        }
                        else
                        {
                            cout << "\n\tEnter the sum of all dice in your hand, or a 0: ";
                            cin >> combPoints[i][8];
                            scoreComb[i][8] = true;
                            break;
                        }
                    case 9:
                        if(scoreComb[i][9] == true)
                        {
                            cout << "\n\tFull House has already been scored.";
                            goto tryAgain;
                        }
                        else
                        {
                            cout << "\n\tIf you have a Full House, enter 25. Otherwise, enter 0: ";
                            cin >> combPoints[i][9];
                            scoreComb[i][9] = true;
                            break;
                        }
                    case 10:
                        if(scoreComb[i][10] == true)
                        {
                            cout << "\n\tSmall Straight has already been scored.";
                            goto tryAgain;
                        }
                        else
                        {
                            cout << "\n\tIf you have a Small Straight, enter 30. Otherwise, enter 0: ";
                            cin >> combPoints[i][10];
                            scoreComb[i][10] = true;
                            break;
                        }
                    case 11:
                        if(scoreComb[i][11] == true)
                        {
                            cout << "\n\tLarge Straight has already been scored.";
                            goto tryAgain;
                        }
                        else
                        {
                            std::cout << "\n\tIf you have a Large Straight, enter 40. Otherwise, enter 0: ";
                            std::cin >> combPoints[i][11];
                            scoreComb[i][11] = true;
                            break;
                        }
                    case 12:
                        if(scoreComb[i][12] == true)
                        {
                            // Determine whether Yahtzee has been previously scored or if a 0 was entered.
                            // If Yahtzee category is equal to 50 points, set Yahtzee bonus to true.
                            if(combPoints[i][12] == 50)
                            {
                                yahtzeeBonus[i] = true;
                                cout << "\n\tCongratulations! Yahtzee Bonus has been applied!";
                            }
                                // If yahtzee holds a score of zero and has been entered, explain Joker Rules and return to choice.
                            else
                            {
                                cout << "\n\tYou have already entered a 0 for Yahtzee!";
                                cout << "\n\n\tIf you have Yahtzee in hand, and have already entered a 0 in the";
                                cout << "\n\tYahtzee category, apply the sum of your dice to the appropriate Upper";
                                cout << "\n\tSection score category. If applicable Upper Section score is filled, apply";
                                cout << "\n\tthe sum to any Lower Section category. If all Lower Section scores";
                                cout << "\n\thave been filled, you must enter a 0 in any other Upper Section score.";
                                goto tryAgain;
                            }
                        }
                        else
                        {
                            cout << "\n\tIf you have scored YAHTZEE!, enter 50. Otherwise, enter 0: ";
                            cin >> combPoints[i][12];
                            scoreComb[i][12] = true;
                            break;
                        }
                        // if user has entered 13, checks to see if category already holds a score, and prints appropriate response or returns to tryAgain.
                    case 13:
                        if(scoreComb[i][13] == true)
                        {
                            cout << "\n\tChance has already been scored.";
                            goto tryAgain;
                        }
                        else
                        {
                            cout << "\n\tIf using chance, enter sum of all dice. Otherwise, enter 0: ";
                            cin >> combPoints[i][13];
                            scoreComb[i][13] = true;
                            break;
                        }
                        // if invalid number is entered, informs player that the number is not valid, and returns to tryAgain.
                    default:
                        cout << "\n\tThat is not a valid selection, please choose a number between 1 and 13.";
                        goto tryAgain;
                }


            }
            // Increments the round by one at the end of each round.
            round ++;
        }

        // holds final scores of each player
        vector<int> finalScores;

        // add and assign sum of the upper section scores to the uppSecTotals array for each separate player
        // and adds and assigns the sum of the lower section scores to the lowSectTotals array for each separate player.
        int uppSectTotals[4];
        int lowSectTotals[4];
        for(unsigned int i = 0; i < 4; i++)
        {
            uppSectTotals[i] = (combPoints[i][0] + combPoints[i][1] + combPoints[i][2] + combPoints[i][3] + combPoints[i][4] + combPoints[i][5]);
            lowSectTotals[i] = (combPoints[i][6] + combPoints[i][7] + combPoints[i][8] + combPoints[i][9] + combPoints[i][10] + combPoints[i][11] + combPoints[i][12]);
        }

        for(int i = 0; i < numOfPlayers; i++)
        {
            // tempScore used to total specific player's score. Once finished, applies final score to vector "finalScores."
            int tempScore = 0;
            // If Upper Section total is 63 or higher, applies bonus of 35 points.
            if(uppSectTotals[1] >= 63)
            {
                tempScore += 35;
            }
            // If Yahtzee Bonus has been scored, applies an additional bonus of 100 points.
            if(yahtzeeBonus[i] = true)
            {
                tempScore += 100;
            }
            // tempScore contains any bonuses, and adds total of upper section and lower section scores.
            tempScore += (uppSectTotals[i] + lowSectTotals[i]);

            // Adds tempScore to finalScores vector, and pairs the players name and final score into playerScores vector for the high scores list.
            finalScores.push_back(tempScore);
            playerScores.push_back(make_pair(finalScores[i], names[i]));
        }

        // High scores list header.
        cout << "\n\n\n              ••• Congratulations! You have completed the game! •••";
        cout << "\n\n              Scores in descending order are listed below: \n\n\n";

        // Sorts player scores from highest to lowest, then prints list. Notice iterator->second(names) is printed first, and iter->first (scores) is printed second.
        sort(playerScores.rbegin(), playerScores.rend());
        for(vector<pair<int, string> >::const_iterator iter = playerScores.begin(); iter != playerScores.end(); iter++)
        {
            cout << "\t" << iter->second << " " << iter->first << ".\n\n";
        }

        //ask if user wants to play again
        cout << "\n\n\t\tWould you like to play again?";
        cout << "\n\tEnter 'Y' to play again, or 'N' to end the game.";
        cin >> playAgain;

        // validates play again response
        while((playAgain != "Y") && (playAgain != "N"))
        {
            cout << "\n\tThat answer is invalid. Enter capital 'Y' or capital 'N.'";
            cin >> playAgain;
        }

        // Clears names and finalScores vectors for new game
        names.clear();
        finalScores.clear();

    }

    return 0;
}

// sumInitialRoll Function - Used if number of players is higher than one, returns
int sumInitialRoll(long t2)
{
    int roll1 = (rand() % 6 + 1);
    int roll2 = (rand() % 6 + 1);
    int roll3 = (rand() % 6 + 1);
    int roll4 = (rand() % 6 + 1);
    int roll5 = (rand() % 6 + 1);

    int startRoll = (roll1 + roll2 + roll3 + roll4 + roll5);

    return startRoll;
}

// rollDie Function. Called whenever the dice are rolled.
int rollDie(long t2)
{
    int roll = (rand() % 6 + 1);
    return roll;
}
