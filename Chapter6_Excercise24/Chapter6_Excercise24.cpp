// Chapter6_Excercise24.cpp  This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
	Program: Rock, Paper, Scissors Game
	Description: This program allows the user to play a game of Rock, Paper, Scissors against the computer.
				 The computer randomly selects a choice, and the user inputs their choice. The program determines the winner and display the results.
	Author: Marvin McCuller
	Date: 11/30/2024
	
*/

void displayMenu();
int getComputerChoice();
string getChoiceName(int choice);
int determineWinner(int userChoice, int computerChoice);


int main() {
	srand(static_cast<unsigned int>(time(0))); // Seed random number generator
	int userChoice, computerChoice;
	char playAgain;

	do {
		// Step 1: Generate the computer's choice
		computerChoice = getComputerChoice();

		// Step 2: Prompt the user for their  choice 
		displayMenu();
		cout << "Enter your choice (1 for Rock,2 for Paper, 3 for Scissors):";
		cin >> userChoice;

		// Validate user input
		while (userChoice < 1 || userChoice > 3) {
			cout << "Invalid choice. Please enter 1, 2, or 3:";
			cin >> userChoice;
		}

		// Step 3: Display both choices
		cout << "\nYou chose:" << getChoiceName(userChoice) << endl;
		cout << "Computer chose:" << getChoiceName(computerChoice) << endl;

		// Step 4: Determine and display the winner
		int winner = determineWinner(userChoice, computerChoice);
		if (winner == 0) {
			cout << "it's a tie! Play again to determine the winner.\n";
		}
		else if (winner == 1) {
			cout << "You win! Congratilations!\n";
		}
		else {
			cout << "The computer wins! Better luck next time.\n";
		}

		// Ask if the user wants to play again 
		cout << "Do you want to play again?(y/n):";
		cin >> playAgain;

	} while (playAgain == 'y' || playAgain == 'Y');

	cout << "Thank you for playing! Goodbye. \n";
	return 0;

}

// Function to display the menu
void displayMenu() {
	cout << "\nRock,Paper, Scissors Game\n";
	cout << "1. Rock\n";
	cout << "2. Paper\n";
	cout << "3. Scissors\n";


}

// Function to get the computer's random choice
int getComputerChoice() {
	return rand() % 3 + 1; // Generates a number between 1 and 3
}

// Function to convert chice number to name
string getChoiceName(int choice) {
	switch (choice) {
	case 1: return "Rock";
	case 2: return "Paper";
	case 3: return "Scissors";
	default: return "Invalid";
	}

}

// Function to determine the winner
int determineWinner(int userChoice, int computerChoice) {
	if (userChoice == computerChoice) {
		return 0;  // Tie
	} else if ((userChoice == 1 && computerChoice == 3) || // Rock beats Scissors
			   (userChoice == 2 && computerChoice == 1) || // Paper beats Rock
		       (userChoice == 3 && computerChoice == 2)) { // Scissors beats Paper
		return 1; // User wins
	}
	else {
		return -1; // Computer wins
	}
}