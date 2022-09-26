#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
int randomNumber;
int attemptsTotal;
int attemptsLeft;

int main() {
	printf("\033[35m----------------------------------------------\n");
	printf("    Welcome to the number guessing game!\n");
	printf("          The name says it self.\n");
	printf("----------------------------------------------\n\033[37m");
	// Generate random number from 1-100
	srand(time(0));
	randomNumber = rand() % 100;
	randomNumber += 1;
	difficulty();
	printf("Guess the randomly generated number! (0-100)\n");
	guessing();
}

// Let player choose difficulty
int difficulty() {
	printf("Choose difficulty:\n(E)asy (8 Guesses)\n(N)ormal (6 Guesses)\n(H)ard (4 Guesses)\n(C)ustom\n");
	char chooseDiff;
	scanf(" %c", &chooseDiff);
	if (chooseDiff == 'e' || chooseDiff == 'E') {
		attemptsTotal = 8;
		attemptsLeft = attemptsTotal;
	}
	else if (chooseDiff == 'n' || chooseDiff == 'N') {
		attemptsTotal = 6;
		attemptsLeft = attemptsTotal;
	}
	else if (chooseDiff == 'h' || chooseDiff == 'H') {
		attemptsTotal = 4;
		attemptsLeft = attemptsTotal;
	}
	else if (chooseDiff == 'c' || chooseDiff == 'C') {
		printf("Enter the number of guesses: ");
		int customGuesses;
		scanf(" %d", &customGuesses);
		attemptsTotal = customGuesses;
		attemptsLeft = attemptsTotal;
	}
	// Input wasn't valid, retrying
	else {
		printf("\033[31mInvalid charcter.\n\033[37");
		difficulty();
	}
}

int guessing() {
	if (attemptsLeft != 0) {
		// There are guesses left, give hint or win
		int guess;
		scanf("%d", &guess);
		if (guess > randomNumber) {
			printf("\033[33mThe number is lower. \033[37m");
			attemptsLeft-=1;
			guessing();
		}
		else if (guess < randomNumber)
		{
			printf("\033[33mThe number is higher. \033[37m");
			attemptsLeft-=1;
			guessing();
		}
		else {
			attemptsLeft = attemptsTotal;
			printf("\033[92mThat is correct!\n\033[37m");
			restart(0);
		}
	}
	// No guesses left, you lost
	else {
		attemptsLeft = attemptsTotal;
		printf("\nThe number was %d", randomNumber);
		printf("\033[31m\nYou have failed. \033[37mDo you want to switch difficulty? (y/n) : ");
		char switchDiff;
		scanf(" %c", &switchDiff);
		if (switchDiff == 'y') {
			// Switch difficulty & Continue
			difficulty();
			restart(1);
		}
		else {
			// Continue or Exit
			restart(0);
		}
	}
}

int restart(int skipIntro) {
	if (skipIntro != 1) {
		printf("Do you want to play again? (y/n) : ");
		char yesNo;
		scanf(" %c", &yesNo);
		// Generate new random number and continue
		if (yesNo == 'y') {
			randomNumber = rand() % 100;
			randomNumber += 1;
			printf("Guess the randomly generated number! (1-100)\n");
			guessing();
		}
		// Exit code
		else {
			printf("\nSad to see you go!\n\n\n\n\n\n\n");
			return 0;
		}
	}
	else
	{
		randomNumber = rand() % 100;
		randomNumber += 1; 
		printf("Guess the randomly generated number! (1-100)\n");
		guessing();
	}
}