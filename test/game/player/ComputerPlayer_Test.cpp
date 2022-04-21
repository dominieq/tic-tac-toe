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

TEST_F(ComputerPlayerTest, should_return_best_score_when_second_move) {

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