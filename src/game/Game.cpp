#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(const string& Name_1, const string& Name_2) {
	Player_1 = new HumanPlayer(Name_1, X_SIGN);
	Player_2 = new HumanPlayer(Name_2, O_SIGN);
	GameBoard = new Board();
}

Game::~Game() {
	delete Player_1;
	delete Player_2;
	delete GameBoard;
}

void Game::PlayGame() {
	Moves = 0;
	BoardContent Winner = EMPTY;

	while (Winner == EMPTY && Moves < 9) {
		Winner = PerformMove(Player_1);
		if (Winner != EMPTY || Moves >= 9) break;
		Winner = PerformMove(Player_2);
	}

	switch (Winner) {
		case X_SIGN:
			cout << Player_1->getName() << " won" << endl;
			break;
		case O_SIGN:
			cout << Player_2->getName() << " won" << endl;
			break;
		default:
			cout << "Draw" << endl;
			break;
	}
}

BoardContent Game::PerformMove(Player*& Player) {
	cout << *GameBoard;
	Player->PerformMove(GameBoard);

	if (++Moves >= 5) {
		return GameBoard->IsToe();
	} else {
		return EMPTY;
	}
}