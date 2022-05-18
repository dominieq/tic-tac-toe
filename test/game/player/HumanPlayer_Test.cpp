#include "gtest/gtest.h"
#include "../../../src/game/player/HumanPlayer.h"

using namespace std;

class HumanPlayerTest : public ::testing::Test {

protected:
	HumanPlayer* Subject;

	void SetUp() override {
		Subject = new HumanPlayer("TestPlayer", O_SIGN);
	}

	void TearDown() override {
		delete Subject;
	}
};

TEST_F(HumanPlayerTest, should_select_empty_field) {

	// given
	Board EmptyBoard;
	Board* EmptyBoardPointer = &EmptyBoard;

	stringstream Input("0 0");
	ostringstream Output;

	// when
	Subject->PerformMove(EmptyBoardPointer, Input, Output);

	// then
	const BoardContent ExpectedValue = EmptyBoard[0][0];
	const string ExpectedOutput = Output.str();

	EXPECT_EQ(ExpectedValue, O_SIGN);
	ASSERT_EQ(ExpectedOutput, "Enter row: Enter column: ");
}

TEST_F(HumanPlayerTest, should_not_select_marked_field) {

	// given
	Board FilledBoard;
	FilledBoard[0][0] = X_SIGN;

	Board* FilledBoardPointer = &FilledBoard;

	stringstream Input("0 0 1 1");
	ostringstream  Output;

	// when
	Subject->PerformMove(FilledBoardPointer, Input, Output);

	// then
	const BoardContent ExpectedValue_1 = FilledBoard[0][0];
	const BoardContent ExpectedValue_2 = FilledBoard[1][1];
	const string ExpectedOutput = Output.str();

	EXPECT_EQ(ExpectedValue_1, X_SIGN);
	EXPECT_EQ(ExpectedValue_2, O_SIGN);
	ASSERT_EQ(ExpectedOutput, "Enter row: Enter column: "
							  "Position's already taken. Choose again.\n"
							  "Enter row: Enter column: ");
}

class RowTestWithStdInputParam :
		public HumanPlayerTest,
		public ::testing::WithParamInterface<string> {
};

TEST_P(RowTestWithStdInputParam, should_choose_row_twice_when_input_value_is_not_allowed) {

	// given
	Board EmptyBoard;
	Board* EmptyBoardPointer = &EmptyBoard;

	stringstream Input(GetParam());
	ostringstream Output;

	// when
	Subject->PerformMove(EmptyBoardPointer, Input, Output);

	// then
	const BoardContent ExpectedValue = EmptyBoard[0][0];
	const string ExpectedOutput = Output.str();

	EXPECT_EQ(ExpectedValue, O_SIGN);
	ASSERT_EQ(ExpectedOutput, "Enter row: Row must be between 0 and 2.\nEnter row: Enter column: ");
}

INSTANTIATE_TEST_SUITE_P(
		row_test_with_sign_param,
		RowTestWithStdInputParam,
		::testing::Values(
				"-1 0 0",
				"3 0 0"));

class ColumnTestWithStdInputParam :
		public HumanPlayerTest,
		public ::testing::WithParamInterface<string> {
};

TEST_P(ColumnTestWithStdInputParam, should_choose_column_twice_when_input_value_is_not_allowed) {

	// given
	Board EmptyBoard;
	Board* EmptyBoardPointer = &EmptyBoard;

	stringstream Input("0 3 0");
	ostringstream Output;

	// when
	Subject->PerformMove(EmptyBoardPointer, Input, Output);

	// then
	const BoardContent ExpectedValue = EmptyBoard[0][0];
	const string ExpectedOutput = Output.str();

	EXPECT_EQ(ExpectedValue, O_SIGN);
	ASSERT_EQ(ExpectedOutput, "Enter row: Enter column: Column must be between 0 and 2.\nEnter column: ");
}

INSTANTIATE_TEST_SUITE_P(
		column_test_with_std_input_param,
		ColumnTestWithStdInputParam,
		::testing::Values(
				"0 -1 0",
				"0 3 0"));
