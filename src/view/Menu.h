#ifndef TICTACTOE_MENU_H
#define TICTACTOE_MENU_H

#include <string>
#include <vector>

class Menu {
    std::string Title;
    std::vector<std::string> Choices;

public:
    Menu(std::string InTitle, std::vector<std::string> InChoices);
    virtual ~Menu();

    virtual int ShowAndWait() const;
};


#endif //TICTACTOE_MENU_H
