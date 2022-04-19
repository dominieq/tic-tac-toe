#include <gtest/gtest.h>
#include "../../src/game/Game.h"

class GameTest : public ::testing::Test {
protected:
	Game Subject;

	void SetUp() override {
		Subject = Game("TestPlayer1", "TestPlayer2");
	}
};

TEST(GameTest, should_properly_construct_and_destruct_game) {
	Game NewGame("Player1", "Player2");
	ASSERT_EQ(true, true);
}

TEST(GameTest, should_properly_construct_and_destruct_game_with_one_player) {
	ASSERT_NO_THROW(Game NewGame("Player"));
}
