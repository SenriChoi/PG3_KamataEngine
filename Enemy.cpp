#include "Enemy.h"

Enemy::Enemy(Vector2 pos)
    : pos_(pos), speed_(10.0f), active_(true), direction_(1.0f)
{
   
}

void Enemy::Update()
{
    if (!active_) return;

    pos_.y += speed_ * direction_;

    if (pos_.y <= 0 || pos_.y >= 720-25) {
        direction_ *= -1; 
    }
}

void Enemy::Draw()
{
    if (active_) {
        Novice::DrawBox(int(pos_.x), int(pos_.y), 50, 50, 0.0f, RED, kFillModeSolid);
    }
}