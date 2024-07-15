//Number guessing game
// Description: The player has to guess the secret number and he got 10 attempts

#include <iostream>
#include <time.h>
using namespace std;

int main() {
	// initialize random seed
	srand(time(NULL));

	// generate a random number btw 1 and 100
	int secretNumber = rand() % 100 + 1;
	int userInput = 0;

	// enter the loop. notifies if number is not numeric
	// also notifies if the guessed number is too high or too low
	// if the number is correct it leaves the loop
	cout << "Hi Player. Please guess the Secret Number" << endl;
	do {
		if(!(cin >> userInput)) {
			cout << "Only enter numeric numbers" << endl;
		} else {
			// if its to high notify to highg
			if(userInput > secretNumber) cout << "You guessed wrong and too high, try again!" << endl;
			// if its to low notify to low
			if(userInput < secretNumber) cout << "You guessed wrong and too low, try again!" << endl;
		}
	} while (userInput != secretNumber);

	// prints the final message
	cout << "You guessed write! The Secret Number was " << secretNumber << endl;
	return 0;
}