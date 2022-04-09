#include "Player.h"
#include <utility>

Player::Player(std::string InName, BoardContent InSign)
: Name(std::move(InName)), Sign(InSign) {}

Player::~Player() = default;

const std::string &Player::getName() const {
	return Name;
}
