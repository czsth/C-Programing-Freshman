#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ODIE 7    //die number in other rounds

int roll(int *a, int *b);		//roll the dices
void printWelcome();
int isFirstRoundWin(int total);
int isFirstRoundLose(int total);
void printInfo(int roundCounter, int diceA, int diceB, int winNum);

int main(int argc, char const *argv[]) {
	srand(time(NULL));  //random seed initialize
	enum State { WIN, LOSE, CONTINUE } state = CONTINUE;
	int winNum = 0, currNum = 0;
	int isFirstRound = 1;
	int isExit = 0;		//if the game will exit this round
	int roundCounter = 1;
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
			else if (currNum == ODIE) {
				state = LOSE;
			}
		}

		printInfo(roundCounter, diceA, diceB, winNum);

		//check current state
		switch (state) {
		case WIN:
			printf("         Congratulations!\n\n");
				isExit = 1;
				break;

		case LOSE:
			printf("          Oh! Bad luck.\n\n");
			isExit = 1;
			break;

		case CONTINUE:
			winNum = currNum;
			roundCounter++;
			printf("       Go into next round!\n\n");
			break;
		}

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
	if (total == 7 || total == 11) {
		return 1;
	}
	return 0;
}

inline int isFirstRoundLose(int total) {
	if (total == 2 || total == 3 || total == 12) {
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
