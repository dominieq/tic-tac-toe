#include "game/Game.h"
#include "view/Menu.h"
#include <iostream>

using namespace std;

int main() {
	vector<string> MainMenuChoices;
	MainMenuChoices.emplace_back("New Game");
	MainMenuChoices.emplace_back("Help");
	MainMenuChoices.emplace_back("Exit");
	Menu MainMenu("Tic-Tac-Toe", MainMenuChoices);

	vector<string> NewGameChoices;
	NewGameChoices.emplace_back("Local Game");
	NewGameChoices.emplace_back("Against AI");
	NewGameChoices.emplace_back("Go Back");
	Menu NewGameMenu("New Game", NewGameChoices);

	int MainChoice = 0;
	while (MainChoice != 3) {
		switch (MainChoice = MainMenu.ShowAndWait()) {
			case 1: {
				int NewGameChoice = 0;
				while (NewGameChoice != 3) {
					switch (NewGameChoice = NewGameMenu.ShowAndWait()) {
						case 1: {
							Game Game("Player1", "Player2");
							Game.PlayGame();
							break;
						}
						default:
							break;
					}
				}
				break;
			}
			case 2:
				cout << "Please be patient, help is coming!" << endl;
				break;
			default:
				break;
		}
	}
	cout << "Exiting..." << endl;
	return 0;
}
