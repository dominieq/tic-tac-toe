#include <gtest/gtest.h>
#include "../../../src/game/player/ComputerPlayer.h"

class ComputerPlayerTest : public ::testing::Test {

protected:
	Board TestBoard;
	ComputerPlayer* Subject;

	void SetUp() override {
		TestBoard = Board();
		Subject = new ComputerPlayer("TestPlayer", X_SIGN);
	}

	void TearDown() override {
		delete Subject;
	}
};

TEST_F(ComputerPlayerTest, should_choose_optimal_first_move) {

	// when
	Board* TestBoardPointer = &TestBoard;
	Subject->PerformMove(TestBoardPointer);

	// then
	ASSERT_EQ(TestBoard[0][0], X_SIGN);
}

/*
 * Initial:
 *    o| |
 *    - - -
 *     | |
 *    - - -
 *     | |
 * Result:
 *    o| |
 *    - - -
 *     |x|
 *    - - -
 *     | |
 */
TEST_F(ComputerPlayerTest, should_choose_optimal_second_move) {

	// given
	TestBoard[0][0] = O_SIGN;

	// when
	Board* TestBoardPointer = &TestBoard;
	Subject->PerformMove(TestBoardPointer);

	// then
	ASSERT_EQ(TestBoard[1][1], X_SIGN);
}

/*
 * Initial:
 *    x|o|x
 *    - - -
 *    o|o|x
 *    - - -
 *     | |
 * Result:
 *    x|o|x
 *    - - -
 *    o|o|x
 *    - - -
 *     | |x
 */
TEST_F(ComputerPlayerTest, should_choose_winning_field) {

	// given
	TestBoard[0][0] = X_SIGN;
	TestBoard[0][1] = O_SIGN;
	TestBoard[0][2] = X_SIGN;

	TestBoard[1][0] = O_SIGN;
	TestBoard[1][1] = O_SIGN;
	TestBoard[1][2] = X_SIGN;

	// when
	Board* TestBoardPointer = &TestBoard;
	Subject->PerformMove(TestBoardPointer);

	// then
	EXPECT_EQ(TestBoard[2][0], EMPTY);
	EXPECT_EQ(TestBoard[2][1], EMPTY);
	ASSERT_EQ(TestBoard[2][2], X_SIGN);
}

/*
 * Initial:
 *    x|x|o
 *    - - -
 *    o|o|x
 *    - - -
 *    x|o|
 * Result:
 *    x|x|o
 *    - - -
 *    o|o|x
 *    - - -
 *    x|o|x
 */
TEST_F(ComputerPlayerTest, should_choose_draw_field) {

	// given
	TestBoard[0][0] = X_SIGN;
	TestBoard[0][1] = X_SIGN;
	TestBoard[0][2] = O_SIGN;

	TestBoard[1][0] = O_SIGN;
	TestBoard[1][1] = O_SIGN;
	TestBoard[1][2] = X_SIGN;

	TestBoard[2][0] = X_SIGN;
	TestBoard[2][1] = O_SIGN;

	// when
	Board* TestBoardPointer = &TestBoard;
	Subject->PerformMove(TestBoardPointer);

	// then
	ASSERT_EQ(TestBoard[2][2], X_SIGN);
}
