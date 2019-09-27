#include <iostream>
#include <time.h>


int UserChoiceFunc(int userChoice);
int ComputerChoiceFunc(int computerChoice);
void EvaluateTurnWinner(int userChoice, int computerChoice, int&userVictory, int&computerVictory);
bool DefineWinnerFunc(int userVictory, int computerVictory, bool isRunning);

int main() {

	int userChoice = 0;
	int computerChoice = 0;

	const int pierre = 1;
	const int papier = 2;
	const int ciseau = 3;
	srand(time(NULL));
	bool isRunning = true;
	int turnNumber = 0;
	int userVictory = 0;
	int computerVictory = 0;

	while (isRunning)
	{
	computerChoice = rand() % 3 + 1;
	turnNumber++;

	
	userChoice = UserChoiceFunc(userChoice);
	
		if (userChoice == 1|| userChoice == 2|| userChoice == 3 )
		{
			computerChoice = ComputerChoiceFunc(computerChoice);

			EvaluateTurnWinner(userChoice, computerChoice, userVictory, computerVictory);
			
			isRunning = DefineWinnerFunc(userVictory, computerVictory, isRunning);

			std::cout << "Score = " << userVictory << " for you, " << computerVictory << " for the computer\n";
			}
	}


		system("pause");
		return EXIT_SUCCESS;
}
	int UserChoiceFunc(int userChoice)
	{
		std::cout << "Chose a number to indicate ROCK(1), PAPER(2), SCISSOR(3)\n";
		std::cin >> userChoice;
		

		switch (userChoice)
		{
		case(1):
			std::cout << "you chose ROCK\n";
			break;
		case(2):
			std::cout << "you chose PAPER\n";
			break;
		case(3):
			std::cout << "you chose SCISSOR\n";
			break;
		default:
			std::cout << "Choice unavailable\n";
		}
		return userChoice;
	}

	int ComputerChoiceFunc(int computerChoice)
	{
		switch (computerChoice)
		{
		case(1):
			std::cout << "computer chose ROCK\n";
			break;
		case(2):
			std::cout << "computer chose PAPER\n";
			break;
		case(3):
			std::cout << "computer chose SCISSOR\n";
			break;
		}
		return computerChoice;
	}

	void EvaluateTurnWinner(int userChoice, int computerChoice, int&userVictory, int&computerVictory)
	{
		if (userChoice == 1 && computerChoice == 1 || userChoice == 2 && computerChoice == 2 || userChoice == 3 && computerChoice == 3)
		{
			std::cout << "no winner this turn\n";

		}
		if (userChoice == 1 && computerChoice == 2 || userChoice == 2 && computerChoice == 3 || userChoice == 3 && computerChoice == 1)
		{
			std::cout << "you lost this turn\n";
			computerVictory++;
		}
		if (userChoice == 1 && computerChoice == 3 || userChoice == 2 && computerChoice == 1 || userChoice == 3 && computerChoice == 2)
		{
			std::cout << "you won this turn\n";
			userVictory++;
		}

	}

	bool DefineWinnerFunc(int userVictory, int computerVictory, bool isRunning)
	{
		if (userVictory == 3)
		{
			std::cout << "You won the game !\n";
			isRunning == false;
		}
		if (computerVictory == 3)
		{
			std::cout << "You lost the game !\n";
			isRunning = false;
		}
		return isRunning;
	}
