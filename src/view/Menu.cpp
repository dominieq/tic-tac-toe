#include "Menu.h"
#include <iostream>
#include <utility>

using namespace std;

Menu::Menu(string InTitle, vector<string> InChoices) :
		Title(move(InTitle)), Choices(move(InChoices)) {}

Menu::~Menu() = default;

int Menu::ShowAndWait() const {
	int UserChoice = 0;
	cout << Title << endl;

	for (int i = 0; i < Choices.size(); i++) {
		cout << i + 1 << ": " << Choices[i] << endl;
	}
	cout << ": ";
	cin >> UserChoice;
	return UserChoice;
}
