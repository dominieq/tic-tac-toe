#include "Menu.h"
#include <iostream>
#include <utility>

Menu::Menu(std::string InTitle, std::vector<std::string> InChoices) :
		Title(std::move(InTitle)), Choices(std::move(InChoices)) {}

Menu::~Menu() = default;

int Menu::ShowAndWait() const {
    int UserChoice = 0;
    std::cout << Title << std::endl;

    for (int i = 0; i < Choices.size(); i++) {
        std::cout << i + 1  << ": " << Choices[i] << std::endl;
    }
    std::cout << ": ";
    std::cin >> UserChoice;
    return UserChoice;
}
