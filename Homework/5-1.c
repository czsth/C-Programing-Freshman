/*
*简述：
*  本程序是个游戏，扔俩色子得到两色子数字的和，如果该数字第一轮数字使isFirstRoundLose()
*  不为零，则输；如果使isFirstRoundWin()不为零，则赢；否则继续。直到本轮所得到的数字与
*  上一轮相同，则赢；或使得到 DIE(此处是7)，则输。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIE 7    //die number in other rounds(not in first round)

int roll(int *a, int *b);		//roll the dices
void printWelcome();
int isFirstRoundWin(int total);
int isFirstRoundLose(int total);
void printInfo(int roundCounter, int diceA, int diceB, int winNum);

int main(int argc, char const *argv[]) {
	srand(time(NULL));  //random seed initialize
	enum State { WIN, LOSE, CONTINUE } state = CONTINUE;
	int winNum = 0, currNum = 0;	//win number is the target number
	int isFirstRound = 1;
	int isExit = 0;		//if the game will exit this round
	int roundCounter = 1;	//the number of current round
	int diceA, diceB;

	//game start
	while (1) {
		currNum = roll(&diceA, &diceB);

		//check if this is first round
		if (isFirstRound) {
			printWelcome();
			if (isFirstRoundWin(currNum)) {
				state = WIN;
			}
			else if (isFirstRoundLose(currNum)) {
				state = LOSE;
			}
			isFirstRound = 0;
		}

		else {
			if (currNum == winNum) {
				state = WIN;
			}
			else if (currNum == DIE) {
				state = LOSE;
			}
		}

		printInfo(roundCounter, diceA, diceB, winNum);

		//check current state
		switch (state) {
		case WIN:
			printf("         Congratulations!\n\n");
				isExit = 1;		//set exit flag
				break;

		case LOSE:
			printf("          Oh! Bad luck.\n\n");
			isExit = 1;		//set exit flag
			break;

		case CONTINUE:
			winNum = currNum;
			roundCounter++;
			printf("       Go into next round!\n\n");
			break;
		}

		//exit if exit flag set(LOSE or WIN)
		if (isExit) {
			break;
		}

	}

	return 0;
}

inline int roll(int *a, int *b) {
	*a = rand() % 6 + 1, *b = rand() % 6 + 1;   //two dice
	return *a + *b;
}

void printWelcome() {
	printf("    Welcome to the Dice Game!\n\n");
}

inline int isFirstRoundWin(int total) {
	if (total == 7 || total == 11) {	//these are given numbers
		return 1;
	}
	return 0;
}

inline int isFirstRoundLose(int total) {
	if (total == 2 || total == 3 || total == 12) {		//these are given numbers
		return 1;
	}
	return 0;
}

void printInfo(int roundCounter, int diceA, int diceB, int winNum) {
	printf("----------------------------------\n");
	printf("            Round %2d\n", roundCounter);
	if (roundCounter == 1) {
		printf("     This is your first round\n");
	}
	else {
		printf(" Your win number this round is: %d\n", winNum);
		printf("     Hope it is not a 7 !\n");
	}
	printf("\n  Dice A: %d, Dice B: %d, Total: %d\n", diceA, diceB, diceA + diceB);
	printf("----------------------------------\n");
}
