/*
    +-----------------------------------------+
	| 06-Rock,Paper,Scissors,Lizard,Spock     |
	| - Author : Ibrahim Mohamed Abdul-Meged. |
	|		   : facebook.com/Ibrahiim.Pasha  |
	|		   : github.com/Ibrahiim-Pasha    |
	| - Date : 01/10/2016 - 09:59 AM          |
	+-----------------------------------------+
*/

#include <iostream>
#include <string>
#include <ctime>
#include "SomeErrors.h"
using namespace std;

CSomeErrors someError;

void welcome();
void result();
void getPlayerGame();
void getMachineGame();
void processing();
void playerWin(string pwin);
void machineWin(string mWin);
void gameContinue();
void finalResult();
void gameOver();
void gameAgain();
void defaultValueGame();
void exitGame();

int cScore, pScore, gameRound, ties, playerGameNumber;
string playerName, playerGame, MachineGame,
	   game[5] = { "Rock", "Paper", "Scissors", "Lizard", "Spock" };

int main()
{
	srand(time(NULL));

	defaultValueGame();
	welcome();
	result();
	getPlayerGame();
	getMachineGame();
	processing();

	system("PAUSE");
	return 0;
}

void welcome()
{
	
	cout << endl;
	cout << "Enter your name : ";
	cin >> playerName;
	cout << "\nEnter round : ";
	cin >> gameRound;
	system("CLS");

}


void result()
{
	cout << "\n\tComputer : " << cScore
		 << "\t" << playerName << " : " << pScore
		 << "\tTies : " << ties
		 << "\tRound : " << gameRound << endl << endl;
}

void getPlayerGame()
{
	cout << "YourGame : Rock(1) Paper(2) Scissors(3) Lizard(4) Spock(5) : ";
	cin >> playerGameNumber;

	switch (playerGameNumber)
	{
	case 1:
		playerGame = game[0];
		break;
	case 2:
		playerGame = game[1];
		break;
	case 3:
		playerGame = game[2];
		break;
	case 4:
		playerGame = game[3];
		break;
	case 5:
		playerGame = game[4];
		break;
	default:
		break;
	}
}

void getMachineGame()
{
	MachineGame = game[rand() % 5];
}

void processing()
{
	if (playerGame == MachineGame)
	{
		ties++;
		gameRound--;

		cout << "\n\n" << playerName << "Game : " << playerGame
			 << "\tMachineGame : " << MachineGame << "\t" << endl
			 << "\n\t\tTies!\n\n";

		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}

	//                       0       1         2          3         4
	// string game[5] = { "Rock", "Paper", "Scissors", "Lizard", "Spock" };

	/* Scissors cuts paper.
	   Paper covers rock.
	   Rock crushes lizard.
	   Lizard poisons Spock.
	   Spock smashes scissors.
	   Scissors decapitates lizard.
	   Lizard eats paper.
	   Paper disproves Spock.
	   Spock vaporizes rock.
	   Rock crushes scissors.
	*/

	// ********************* Player Win ********************* //
	else if ((playerGame == game[2] && MachineGame == game[1])) // Scissors && Paper
	{
		playerWin("cuts");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((playerGame == game[1] && MachineGame == game[0])) // Paper    && Rock
	{
		playerWin("covers");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((playerGame == game[0] && MachineGame == game[3])) // Rock     && Lizard
	{
		playerWin("crushes");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((playerGame == game[3] && MachineGame == game[4])) // Lizard   && Spock
	{
		playerWin("poisons");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((playerGame == game[4] && MachineGame == game[2])) // Spock    && Scissors
	{
		playerWin("smashes");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((playerGame == game[2] && MachineGame == game[3])) // Scissors && Lizard
	{
		playerWin("decapitates");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((playerGame == game[3] && MachineGame == game[1])) // Lizard   && Paper
	{
		playerWin("eats");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((playerGame == game[1] && MachineGame == game[4])) // Paper    && Spock
	{
		playerWin("disproves");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((playerGame == game[4] && MachineGame == game[0])) // Spock    && Rock
	{
		playerWin("vaporizes");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((playerGame == game[0] && MachineGame == game[2])) // Rock     && Scissors
	{
		playerWin("crushes");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}

	// ********************* Machine Win ********************* //
	else if ((MachineGame == game[2] && playerGame == game[1])) // Scissors && Paper
	{
		machineWin("cuts");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((MachineGame == game[1] && playerGame == game[0])) // Paper    && Rock
	{
		machineWin("covers");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((MachineGame == game[0] && playerGame == game[3])) // Rock     && Lizard
	{
		machineWin("crushes");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((MachineGame == game[3] && playerGame == game[4])) // Lizard   && Spock
	{
		machineWin("poisons");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((MachineGame == game[4] && playerGame == game[2])) // Spock    && Scissors
	{
		machineWin("smashes");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((MachineGame == game[2] && playerGame == game[3])) // Scissors && Lizard
	{
		machineWin("decapitates");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((MachineGame == game[3] && playerGame == game[1])) // Lizard   && Paper
	{
		machineWin("eats");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((MachineGame == game[1] && playerGame == game[4])) // Paper    && Spock
	{
		machineWin("disproves");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((MachineGame == game[4] && playerGame == game[0])) // Spock    && Rock
	{
		machineWin("vaporizes");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
	else if ((MachineGame == game[0] && playerGame == game[2])) // Rock     && Scissors
	{
		machineWin("crushes");
		gameOver();
		someError.question("Continue", &gameContinue, &exitGame);
	}
}

void playerWin(string pWin)
{
	pScore++;
	gameRound--;

	cout << "\n\n" << playerName << "Game : " << playerGame
		<< "\tMachineGame : " << MachineGame << "\t" << endl
		<< "\n\t\tYou " << pWin << " Machine!\n\n";
}

void machineWin(string mWin)
{
	cScore++;
	gameRound--;

	cout << "\n\n"<< playerName << "Game : " << playerGame
		<< "\tMachineGame : " << MachineGame << endl
		<< "\n\t\tMachine " << mWin << " You!\n\n";
}

void gameContinue()
{
	result();
	getPlayerGame();
	getMachineGame();
	processing();
}

void finalResult()
{
	if (pScore > cScore)
	{
		cout << "\n\t\t\t+----------+\n"
			 <<   "\t\t\t| You Win! |\n"
			 <<   "\t\t\t+----------+\n\n";
	}
	else if (cScore > pScore)
	{
		cout << "\n\t\t\t+--------------+\n"
			<<    "\t\t\t| Machine Win! |\n"
			<<    "\t\t\t+--------------+\n\n";
	}
	else
	{
		cout << "\n\t\t\t+-------+\n"
			 <<   "\t\t\t| Ties! |\n"
			 <<   "\t\t\t+-------+\n\n";
	}
}

void gameOver()
{
	if (gameRound == 0)
	{
		result();
		finalResult();
		someError.question("Again", &gameAgain, &exitGame);
	}
}

void gameAgain()
{
	defaultValueGame();
	welcome();
	result();
	getPlayerGame();
	getMachineGame();
	processing();
}

void defaultValueGame()
{
	cScore = 0; pScore = 0; ties = 0;
}

void exitGame()
{
	someError.exitProgram();
}