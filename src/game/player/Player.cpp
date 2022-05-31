#include "Player.h"

using namespace std;

Player::Player(string InName, BoardContent InSign)
		: Name(move(InName)), Sign(InSign) {}

Player::~Player() = default;

const string& Player::GetName() const {
	return Name;
}
