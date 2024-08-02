#include "Player.h"


Player::Player()
{
	pos_.x = 100.0f;
	pos_.y = 360.0f;
	speed_ = 5.0f;
}

void Player::Init()
{
	pos_.x = 100.0f;
	pos_.y = 360.0f;
	speed_ = 5.0f;
	shootCooldown = 0.3f;
	shootTimer = 0.0f;
}

Player::~Player()
{
	for (Bullet* bullet : bullets_) {
		delete bullet;
	}
	bullets_.clear();
}


void Player::Update(){

	shootTimer += 1.0f / 60.0f;
	// Update bullets
	for (auto& bullet : bullets_) {
		bullet->Update();
	}

}


void Player::Draw()
{
	Novice::DrawBox(int(pos_.x), int(pos_.y), 100, 100, 0.0f, WHITE, kFillModeSolid);
	// Draw bullets
	for (const auto& bullet : bullets_) {
		bullet->Draw();
	}
}

void Player::MoveRight()
{
	this->pos_.x += speed_;
}

void Player::MoveLeft()
{
	this->pos_.x -= speed_;
}

void Player::MoveUp()
{
	this->pos_.y -= speed_;
}

void Player::MoveDown()
{
	this->pos_.y += speed_;
}

void Player::Shoot()
{
	if (shootTimer >= shootCooldown) {
	Vector2 bulletPos = { pos_.x + 45, pos_.y + 45 }; 
	bullets_.push_back(new Bullet(bulletPos));
	shootTimer = 0.0f;
	}
}