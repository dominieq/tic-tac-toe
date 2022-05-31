#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(const string& Name_1, const string& Name_2) {
	Player_1 = new HumanPlayer(Name_1, X_SIGN);
	Player_2 = new HumanPlayer(Name_2, O_SIGN);
	GameBoard = new Board();
}

Game::Game(const std::string& Name) {
	Player_1 = new HumanPlayer(Name, X_SIGN);
	Player_2 = new ComputerPlayer("Computer", O_SIGN);
	GameBoard = new Board();
}

Game::~Game() {
	delete Player_1;
	delete Player_2;
	delete GameBoard;
}

void Game::PlayGame(ostream& StdOutput) {
	Moves = 0;
	BoardContent Winner = EMPTY;

	while (Winner == EMPTY && Moves < 9) {
		Winner = PerformMove(Player_1, StdOutput);
		if (Winner != EMPTY || Moves >= 9) break;
		Winner = PerformMove(Player_2, StdOutput);
	}

	switch (Winner) {
		case X_SIGN:
			StdOutput << Player_1->GetName() << " won" << endl;
			break;
		case O_SIGN:
			StdOutput << Player_2->GetName() << " won" << endl;
			break;
		default:
			StdOutput << "Draw" << endl;
			break;
	}
}

BoardContent Game::PerformMove(Player*& Player, ostream& StdOutput) {
	StdOutput << *GameBoard;
	Player->PerformMove(GameBoard);

	if (++Moves >= 5) {
		return GameBoard->DetermineWinner();
	} else {
		return EMPTY;
	}
}
