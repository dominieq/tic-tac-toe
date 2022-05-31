#include <gtest/gtest.h>
#include "../../src/game/Board.h"

class BoardTest : public ::testing::Test {

protected:
	Board Subject;

	void SetUp() override {
		Subject = Board();
	}
};

TEST_F(BoardTest, should_not_find_toe_when_board_is_empty) {
	const BoardContent Actual = Subject.DetermineWinner();
	ASSERT_EQ(Actual, BoardContent::EMPTY);
}

TEST_F(BoardTest, should_return_true_when_board_is_empty) {

	// when
	const bool Actual = Subject.AnyMovesLeft();

	// then
	ASSERT_TRUE(Actual);
}

class BoardTestWithIndexAndSignParams :
		public BoardTest,
		public ::testing::WithParamInterface<std::tuple<int, BoardContent>> {

protected:
	void PopulateVerse(const int &VerseIndex) {
		for (int i = 0; i < Board::BoardSize; i++) {
			Subject[VerseIndex][i] = std::get<1>(GetParam());
		}
	}

	void PopulateColumn(const int &ColumnIndex) {
		for (int i = 0; i < Board::BoardSize; i++) {
			Subject[i][ColumnIndex] = std::get<1>(GetParam());
		}
	}
};

TEST_P(BoardTestWithIndexAndSignParams, should_find_toe_in_verse) {
	const int VerseIndex = std::get<0>(GetParam());
	PopulateVerse(VerseIndex);

	const BoardContent Actual = Subject.DetermineWinner();
	const BoardContent Expected = std::get<1>(GetParam());
	ASSERT_EQ(Actual, Expected);
}

TEST_P(BoardTestWithIndexAndSignParams, should_find_toe_in_column) {
	const int ColumnIndex = std::get<0>(GetParam());
	PopulateColumn(ColumnIndex);

	const BoardContent Actual = Subject.DetermineWinner();
	const BoardContent Expected = std::get<1>(GetParam());
	ASSERT_EQ(Actual, Expected);
}

INSTANTIATE_TEST_SUITE_P(
		find_toe_in_verse_and_column,
		BoardTestWithIndexAndSignParams,
		::testing::Values(
				std::make_tuple(0, O_SIGN),
				std::make_tuple(1, O_SIGN),
				std::make_tuple(2, O_SIGN),
				std::make_tuple(0, X_SIGN),
				std::make_tuple(1, X_SIGN),
				std::make_tuple(2, X_SIGN)));

class BoardTestWithSignParam :
		public BoardTest,
		public ::testing::WithParamInterface<BoardContent> {
};

TEST_P(BoardTestWithSignParam, should_find_toe_in_diagonal_from_left_to_right) {
	// given
	Subject[0][0] = GetParam();
	Subject[1][1] = GetParam();
	Subject[2][2] = GetParam();

	// when
	const BoardContent Actual = Subject.DetermineWinner();

	// then
	const BoardContent Expected = GetParam();
	ASSERT_EQ(Actual, Expected);
}

TEST_P(BoardTestWithSignParam, should_find_toe_in_diagonal_from_right_to_left) {
	// given
	Subject[0][2] = GetParam();
	Subject[1][1] = GetParam();
	Subject[2][0] = GetParam();

	// when
	const BoardContent Actual = Subject.DetermineWinner();

	// then
	const BoardContent Expected = GetParam();
	ASSERT_EQ(Actual, Expected);
}

TEST_P(BoardTestWithSignParam, should_return_false_when_board_is_filled) {

	// given
	for (int i = 0; i < Board::BoardSize; i++) {
		for (int j = 0; j < Board::BoardSize; j++) {
			Subject[i][j] = GetParam();
		}
	}

	// when
	const bool Actual = Subject.AnyMovesLeft();

	// then
	ASSERT_FALSE(Actual);
}

INSTANTIATE_TEST_SUITE_P(
		board_test_with_x_and_o_signs,
		BoardTestWithSignParam,
		::testing::Values(
				X_SIGN,
				O_SIGN));
