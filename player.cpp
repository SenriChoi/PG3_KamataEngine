#include "Player.h"

Player::Player()
{
	pos_.x = 100.0f;
	pos_.y = 100.0f;
	speed_ = 5.0f;
}

void Player::Init()
{
	pos_.x = 100.0f;
	pos_.y = 100.0f;
	speed_ = 5.0f;
}

void Player::Update(){}

void Player::Draw()
{
	Novice::DrawBox(int(pos_.x), int(pos_.y), 100, 100, 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveRight()
{
	this->pos_.x += speed_;
}

void Player::MoveLeft()
{
	this->pos_.x -= speed_;
}