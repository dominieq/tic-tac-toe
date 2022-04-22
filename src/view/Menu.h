#ifndef TICTACTOE_MENU_H
#define TICTACTOE_MENU_H

#include <string>
#include <vector>

/**
 * A simple menu with a title and list of choices.
 *
 * @author Dominik Szmyt
 * @since 1.0.0
 */
class Menu {
	std::string Title;
	std::vector<std::string> Choices;

public:
	/**
	 * Create an instance with a title and list of choices.
	 *
	 * @param InTitle   The title.
	 * @param InChoices The list of choices.
	 */
	Menu(std::string InTitle, std::vector<std::string> InChoices);

	virtual ~Menu();

	/**
	 * Displays <code>Title</code> and <code>Choices</code> in consecutive lines.
	 * For example:
	 * @code
	 *     Title
	 *     1: First Choice
	 *     2: Second Choice
	 *     :
	 * @endcode
	 * The last line is for a user to enter theirs selection.
	 * The input is then returned as a result.
	 *
	 * @param StdInput  The input stream. Preferably <code>cin</code>.
	 * @param StdOutput The output stream. Preferably <code>cout</code>.
	 * @return User's selection.
	 */
	virtual int ShowAndWait(std::istream& StdInput, std::ostream& StdOutput) const;
};


#endif //TICTACTOE_MENU_H
