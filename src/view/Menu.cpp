#include "Menu.h"
#include <iostream>
#include <utility>

using namespace std;

Menu::Menu(string InTitle, vector<string> InChoices) :
		Title(move(InTitle)), Choices(move(InChoices)) {}

Menu::~Menu() = default;

int Menu::ShowAndWait(istream& StdInput, ostream& StdOutput) const {
	int UserChoice = 0;
	StdOutput << Title << endl;

	for (int i = 0; i < Choices.size(); i++) {
		StdOutput << i + 1 << ": " << Choices[i] << endl;
	}
	StdOutput << ": ";
	StdInput >> UserChoice;
	return UserChoice;
}
