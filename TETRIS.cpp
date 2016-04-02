// Tetris TETRIS.cpp : Defines the entry point for the console application.
/* File: Tetris.cpp
* Purpose: Plays the game of TETRIS
* Author: Amos Nyarongi
* Date Created: November 19, 2015
* Last Modified: April 02, 2016
* ------------------------------------------------------------------------*/

#include "stdafx.h"
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <WinCon.h>
#include <string>
#include <iostream>

using namespace std;

/*INSTRUCTIONS*/
void instructions() {
	bool cont = false;
	string rpsYou;
	cout << "\n\t\t\tINSTRUCTIONS" << endl;
	cout << "\tTETRIS is a game played by manipulating 7 pieces (Tetriminos) of different shapes " << endl;
	cout << "\tas they fall into a bucket. Use the following keys to play: " << endl;
	cout << "\tLEFT and RIGHT arrow keys - shift the piece left and right respectively." << endl;
	cout << "\tUP arrow key - rotates the piece." << endl;
	cout << "\tDOWN arrow key - Speeds the piece to the bottom." << endl;
	cout <<	"\t\t\tENJOY!"<< endl;
	cout << "\tPress 'ENTER' to proceed..." << endl;
	getline(cin, rpsYou);
	if (rpsYou == "") {
		cont;
		system("cls");
	}
	system("cls");
}

/*This Class is for defining the different tetris shapes (Tetriminos): O, S, L, T, J, Z, and I.
* These tetriminos are defined in different arrays. */
class TetrisShape {
public:
	char shapeArray[4][4];
	int X, Y;
	void setShape(int shapeType) {
		switch (shapeType) {
		case 0://J
			shapeArray[0][0] = ' ';	shapeArray[1][0] = ' '; shapeArray[2][0] = ' '; shapeArray[3][0] = ' ';
			shapeArray[0][1] = ' '; shapeArray[1][1] = 'X'; shapeArray[2][1] = ' '; shapeArray[3][1] = ' ';
			shapeArray[0][2] = ' '; shapeArray[1][2] = 'X'; shapeArray[2][2] = ' '; shapeArray[3][2] = ' ';
			shapeArray[0][3] = 'X'; shapeArray[1][3] = 'X'; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
			break;
		case 1://L
			shapeArray[0][0] = ' ';	shapeArray[1][0] = ' '; shapeArray[2][0] = ' '; shapeArray[3][0] = ' ';
			shapeArray[0][1] = ' '; shapeArray[1][1] = 'X'; shapeArray[2][1] = ' '; shapeArray[3][1] = ' ';
			shapeArray[0][2] = ' '; shapeArray[1][2] = 'X'; shapeArray[2][2] = ' '; shapeArray[3][2] = ' ';
			shapeArray[0][3] = ' '; shapeArray[1][3] = 'X'; shapeArray[2][3] = 'X'; shapeArray[3][3] = ' ';
			break;
		case 2://I
			shapeArray[0][0] = ' ';	shapeArray[1][0] = 'X'; shapeArray[2][0] = ' '; shapeArray[3][0] = ' ';
			shapeArray[0][1] = ' '; shapeArray[1][1] = 'X'; shapeArray[2][1] = ' '; shapeArray[3][1] = ' ';
			shapeArray[0][2] = ' '; shapeArray[1][2] = 'X'; shapeArray[2][2] = ' '; shapeArray[3][2] = ' ';
			shapeArray[0][3] = ' '; shapeArray[1][3] = 'X'; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
			break;
		case 3://T
			shapeArray[0][0] = ' ';	shapeArray[1][0] = ' '; shapeArray[2][0] = ' '; shapeArray[3][0] = ' ';
			shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = ' '; shapeArray[3][1] = ' ';
			shapeArray[0][2] = 'X'; shapeArray[1][2] = 'X'; shapeArray[2][2] = 'X'; shapeArray[3][2] = ' ';
			shapeArray[0][3] = ' '; shapeArray[1][3] = 'X'; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
			break;
		case 4://Z
			shapeArray[0][0] = ' ';	shapeArray[1][0] = ' '; shapeArray[2][0] = ' '; shapeArray[3][0] = ' ';
			shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = ' '; shapeArray[3][1] = ' ';
			shapeArray[0][2] = 'X'; shapeArray[1][2] = 'X'; shapeArray[2][2] = ' '; shapeArray[3][2] = ' ';
			shapeArray[0][3] = ' '; shapeArray[1][3] = 'X'; shapeArray[2][3] = 'X'; shapeArray[3][3] = ' ';
			break;
		case 5://S
			shapeArray[0][0] = ' ';	shapeArray[1][0] = ' '; shapeArray[2][0] = ' '; shapeArray[3][0] = ' ';
			shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = ' '; shapeArray[3][1] = ' ';
			shapeArray[0][2] = ' '; shapeArray[1][2] = 'X'; shapeArray[2][2] = 'X'; shapeArray[3][2] = ' ';
			shapeArray[0][3] = 'X'; shapeArray[1][3] = 'X'; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
			break;
		case 6://O
			shapeArray[0][0] = ' ';	shapeArray[1][0] = ' '; shapeArray[2][0] = ' '; shapeArray[3][0] = ' ';
			shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = ' '; shapeArray[3][1] = ' ';
			shapeArray[0][2] = ' '; shapeArray[1][2] = 'X'; shapeArray[2][2] = 'X'; shapeArray[3][2] = ' ';
			shapeArray[0][3] = ' '; shapeArray[1][3] = 'X'; shapeArray[2][3] = 'X'; shapeArray[3][3] = ' ';
			break;
		}
	};
	/*picks a random shape*/
	TetrisShape() {
		setShape(rand() % 7);
		X = 4;
		Y = -2;
	};
	/*this sets the shape on the nextShape area so the user knows what 
	shape is coming next - this is a Work in Progress*/
	TetrisShape(int n) {
		setShape(rand() % 7);
		X = 15;
		Y = -12;

	};
};

/*This function sets the cursor position*/
void setCursorTo(int x, int y) {
	HANDLE handle;
	COORD position;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(handle, position);
	FlushConsoleInputBuffer(handle);
}

/*This is for moving the shape*/
void moveShape(TetrisShape &currentShape, int newShapeTopLeftX, int newShapeTopLeftY) {
	currentShape.X += newShapeTopLeftX;
	currentShape.Y += newShapeTopLeftY;
}

bool moveCheck(int direction, TetrisShape &currentShape, char bucket[][12], char permBucket[][12]) {
	switch (direction) {
	case 0:
		for (int i = 0; i<4; i++) {
			for (int j = 0; j<4; j++) {
				if ((currentShape.Y + 1 + j) >= 0 && (currentShape.Y + 1 + j) <25 
					&& (i + currentShape.X) >= 0 && (i + currentShape.X) < 12) {
					if (currentShape.shapeArray[i][j] == 'X' 
						&& (permBucket[currentShape.Y + 1 + j][i + currentShape.X] == '#'
						|| permBucket[currentShape.Y + 1 + j][i + currentShape.X] == 'X')) {
						return false;
					}
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i<4; i++) {
			for (int j = 0; j<4; j++) {
				if (currentShape.shapeArray[i][j] == 'X' 
					&& (permBucket[currentShape.Y + j][i + currentShape.X + 1] == '#'
					|| permBucket[currentShape.Y + j][i + currentShape.X + 1] == 'X')) {
					return false;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i<4; i++) {
			for (int j = 0; j<4; j++) {
				if (currentShape.shapeArray[i][j] == 'X' 
					&& (permBucket[currentShape.Y + j][i + currentShape.X + 2] == '#'
					|| permBucket[currentShape.Y + j][i + currentShape.X + 2] == 'X')) {
					return false;
				}
			}
		}
		break;


	case -1:
		for (int i = 0; i<4; i++) {
			for (int j = 0; j<4; j++) {
				if (currentShape.shapeArray[i][j] == 'X' 
					&& (permBucket[currentShape.Y + j][i + currentShape.X - 1] == '#'
					|| permBucket[currentShape.Y + j][i + currentShape.X - 1] == 'X')) {
					return false;
				}
			}
		}
		break;
	case -2:
		for (int i = 0; i<4; i++) {
			for (int j = 0; j<4; j++) {
				if (currentShape.shapeArray[i][j] == 'X' 
					&& (permBucket[currentShape.Y + j][i + currentShape.X - 2] == '#'
					|| permBucket[currentShape.Y + j][i + currentShape.X - 2] == 'X')) {
					return false;
				}
			}
		}
		break;

	/*this checks when the piece is rotating so it doesn't collide with the sides of the bucked or other shapes*/
	case -10:
		for (int i = 0; i<4; i++) {
			for (int j = 0; j<4; j++) {
				if (currentShape.shapeArray[i][j] == 'X' 
					&& (permBucket[currentShape.Y + j][i + currentShape.X] == '#'
					|| permBucket[currentShape.Y + j][i + currentShape.X] == 'X')) {
					return false;
				}
			}
		}
		break;

	}
	return true;
}

/*This function is to control the rotating of shapes*/
void rotShape(TetrisShape &c, char bucket[][12], char permBucket[][12]) {
	char temp[4][4];
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			temp[i][j] = c.shapeArray[i][j];
		}
	}
	char tempCellVal = c.shapeArray[0][0];
	c.shapeArray[0][0] = c.shapeArray[0][3];
	c.shapeArray[0][3] = c.shapeArray[3][3];
	c.shapeArray[3][3] = c.shapeArray[3][0];
	c.shapeArray[3][0] = tempCellVal;
	tempCellVal = c.shapeArray[0][1];
	c.shapeArray[0][1] = c.shapeArray[1][3];
	c.shapeArray[1][3] = c.shapeArray[3][2];
	c.shapeArray[3][2] = c.shapeArray[2][0];
	c.shapeArray[2][0] = tempCellVal;
	tempCellVal = c.shapeArray[0][2];
	c.shapeArray[0][2] = c.shapeArray[2][3];
	c.shapeArray[2][3] = c.shapeArray[3][1];
	c.shapeArray[3][1] = c.shapeArray[1][0];
	c.shapeArray[1][0] = tempCellVal;
	tempCellVal = c.shapeArray[1][1];
	c.shapeArray[1][1] = c.shapeArray[1][2];
	c.shapeArray[1][2] = c.shapeArray[2][2];
	c.shapeArray[2][2] = c.shapeArray[2][1];
	c.shapeArray[2][1] = tempCellVal;

	/*These let you move right or left to correct stuck Tetriminos*/
	if (!moveCheck(-10, c, bucket, permBucket)) {
		if (!moveCheck(-1, c, bucket, permBucket) && moveCheck(1, c, bucket, permBucket))
			moveShape(c, 1, 0);
		else if (!moveCheck(-2, c, bucket, permBucket) && moveCheck(2, c, bucket, permBucket))
			moveShape(c, 2, 0);
		else if (moveCheck(-1, c, bucket, permBucket) && !moveCheck(1, c, bucket, permBucket))
			moveShape(c, -1, 0);
		else if (moveCheck(-2, c, bucket, permBucket) && !moveCheck(2, c, bucket, permBucket))
			moveShape(c, -2, 0);

		else {
			for (int i = 0; i<4; i++) {
				for (int j = 0; j<4; j++) {
					c.shapeArray[i][j] = temp[i][j];
				}
			}
		}
	}
}

/*This function is to get user in put and swith between keys pressed and act accordingly*/
void getUserInput(TetrisShape &currentShape, char bucket[][12], char permBucket[][12]) {//get user input
	enum { UP_ARROW = 72, DOWN_ARROW = 80, LEFT_ARROW = 75, RIGHT_ARROW = 77 };
	int c = 0;
	if (_kbhit()) {
		/*switch between the pressed keys*/
		switch (c = _getch()) {
		case LEFT_ARROW:
			if (moveCheck(-1, currentShape, bucket, permBucket))moveShape(currentShape, -1, 0);
			break;
		case RIGHT_ARROW:
			if (moveCheck(1, currentShape, bucket, permBucket))moveShape(currentShape, 1, 0);
			break;
		case UP_ARROW:
			rotShape(currentShape, bucket, permBucket);
			break;
		case DOWN_ARROW:
			while (moveCheck(0, currentShape, bucket, permBucket)) {
				currentShape.Y++;
			}
			break;
		}
	}
}

/*This function calculates the scores.*/
int Score(char(&permBucket)[25][12]) {
	int heightArr[4] = { -1,-1,-1,-1 };
	int moveNum = 0;
	int score = 0;
	for (int i = 24; i>0; i--) {
		if (permBucket[i][1] == 'X' && permBucket[i][2] == 'X' 
			&& permBucket[i][3] == 'X' && permBucket[i][4] == 'X' 
			&& permBucket[i][5] == 'X'
			&& permBucket[i][6] == 'X'&& permBucket[i][7] == 'X'
			&& permBucket[i][8] == 'X'&& permBucket[i][9] == 'X'
			&& permBucket[i][10] == 'X') {
			heightArr[moveNum] = i;
			moveNum++;
		}
	}
	switch (moveNum) {
	case 1:
		score = 100;
		break;
	case 2:
		score = 300;
		break;
	case 3:
		score = 550;
		break;
	case 4:
		score = 800;
		break;
	}
	if (moveNum>0) {
		char temp[25][12] = { ' ' };
		int startMove = moveNum;
		for (int i = moveNum; i<24; i++) {
			while (heightArr[moveNum - 1] == i) {
				moveNum--;
				i++;
			}
			for (int j = 1; j<11; j++) {
				temp[i + moveNum][j] = permBucket[i][j];
			}
		}
		for (int i = 0; i<24; i++) {
			for (int j = 1; j<11; j++) {
				permBucket[i][j] = temp[i][j];
			}
		}
	}
	return score;
}

/*This function checks if the shapes have reached the top of the bucket*/
bool CheckTop(char permBucket[][12]) {
	for (int i = 1; i<11; i++) {
		if (permBucket[0][i] == 'X') return true;
	}
	return false;
}

/*Function to ask the user if they want to play again!*/
bool PlayAgain() {
	char playAgain = ' ';
	setCursorTo(16, 12);
	cout << "          GAME OVER!";
	setCursorTo(16, 13);
	cout << "Would you like to play again?[y/n]: " << endl;
	do {
		/*set the cursor to the middle of the screen and print the playAgain message*/
		setCursorTo(16, 14);
		cin >> playAgain;
		cin.clear();
		cin.ignore(10000, '\n');
		if (playAgain == 'Y' || playAgain == 'y') {
			system("cls");
			return true;
		}
		if (playAgain == 'N' || playAgain == 'n') {
			system("cls");
			setCursorTo(16, 12);
			cout << "      Thank You For Playing. ";
			setCursorTo(16, 13);
			cout << "            GOODBYE!" << endl;
			cout << endl;
			system("pause");
			return false;
		}

		/*this is 'play again' input verification for user input*/
	} while ((playAgain != 'Y' || playAgain != 'Y') && (playAgain != 'N' 
		|| playAgain != 'n'));
	return false;
}

void main() {
	instructions();
	bool play = true;
	do {

		time_t t;
		time(&t);
		long t2 = static_cast<long> (t);
		srand(t2);
		int score = 0;

		bool fail = false;
		bool set = false;

		char bucket[25][12] = { ' ' }; /*inside the bucket*/

		for (int i = 0; i<25; i++) {
			if (i<12)bucket[i][i] = ' ';
			bucket[i][11] = '#';
			bucket[i][0] = '#';
			if (i<12)bucket[24][i] = '#';
		}

		/*This is a permanent bucket*/
		char permBucket[25][12] = { ' ' };
		for (int i = 0; i<25; i++) {
			if (i<12)permBucket[i][i] = ' ';
			permBucket[i][11] = '#';
			permBucket[i][0] = '#';
			if (i<12)permBucket[24][i] = '#';
		}

		/* */
		setCursorTo(0, 0);
		for (int i = 0; i<25; i++) {
			setCursorTo(0, i);
			for (int j = 0; j<12; j++) {
				cout << bucket[i][j];
			}
		}
		/*game loop starts here*/
		do {
			TetrisShape currentShape = TetrisShape();
			TetrisShape nextShape = TetrisShape(2);
			do {
				/*organizes the bucket afteer the shape, creates the persistent bucket*/
				for (int i = 0; i<25; i++) {
					for (int j = 1; j<12; j++) {
						bucket[i][j] = permBucket[i][j];
					}
				}

				/*aligns the shape in the middle of the bucket before dropping it*/
				for (int i = 0; i<4; i++) {
					setCursorTo(currentShape.X, i + currentShape.Y);
					for (int j = 0; j<4; j++) {
						if (currentShape.shapeArray[i][j] != ' ' 
							&& j + currentShape.Y > -1)
							bucket[j + currentShape.Y][i + currentShape.X] = currentShape.shapeArray[i][j];
					}
				}
				/*prints the bucket */
				setCursorTo(0, 0);
				for (int i = 0; i<25; i++) {
					setCursorTo(0, i);
					for (int j = 0; j<12; j++) {
						cout << bucket[i][j];
					}
					/*prints the next shape*/
					if (i == 2) {
						if (score < 1500) {
							cout << " Status: NOVICE";
							nextShape;
						}
						else if (score >= 1500 && score < 3000) {
							cout << " Status: INTERMEDIATE";
						}
						else if (score >= 3000 && score < 6000) {
							cout << " Status: EXPERT";
						}
						else {
							cout << " Status: PROFESSIONAL";
						}
					}
					/*this increases the levels as the score increases*/
					if (i == 5) {
						cout << " Level: ";
						if (score <= 500) {
							cout << 1;
						}
						else if (score >= 500 && score < 1000) {
							cout << 2;
						}
						else if (score >= 1000 && score < 1500) {
							cout << 3;
						}
						else if (score >= 1500 && score < 2000) {
							cout << 4;
						}
						else if (score >= 2000 && score < 2500) {
							cout << 5;
						}
						else if (score >= 2500 && score < 3000) {
							cout << 6;
						}
						else if (score >= 3000 && score < 3500) {
							cout << 7;
						}
					}
					/*prints user score*/
					if (i == 7)
						cout << " Your Score: " << score << endl;

				}

				/*checks to make sure the shape, and both buckets are displayed*/
				if (!moveCheck(0, currentShape, bucket, permBucket)) {
					currentShape.Y = 25;
					set = true;
				}
				if (set) {
					for (int i = 0; i<25; i++) {
						for (int j = 0; j<12; j++) {
							permBucket[i][j] = bucket[i][j];
						}
					}
				}
				/*this checks if the down key was pressed and drops the shape accordingly*/
				if (!set)currentShape.Y++;
				for (int i = 0; i<150; i++) {
					Sleep(1);
					if (!set)getUserInput(currentShape, bucket, permBucket);
				}
				if (set)score += Score(permBucket);
				if (set && CheckTop(permBucket)) fail = true;
				set = false;
			} while (currentShape.Y<24);
		} while (!fail); /*end of game loop*/
	} while (PlayAgain());
	return;
}
