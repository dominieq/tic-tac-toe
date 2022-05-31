#include <gtest/gtest.h>
#include "../../src/view/Menu.h"

using namespace std;

TEST(MenuTest, should_display_menu) {

	// given
	vector<string> Choices;
	Choices.emplace_back("Choice1");
	Choices.emplace_back("Choice2");

	Menu Subject("Title", Choices);

	stringstream Input("1");
	ostringstream Output;

	// when
	int Actual = Subject.ShowAndWait(Input, Output);
	string ActualOutput = Output.str();

	// then
	EXPECT_EQ(Actual, 1);
	ASSERT_EQ(ActualOutput, "Title\n1: Choice1\n2: Choice2\n: ");
}
