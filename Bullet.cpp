#include "Bullet.h"

Bullet::Bullet(Vector2 pos)
    : pos_(pos), speed_(10.0f), active_(true)
{
}

void Bullet::Update()
{
    pos_.x += speed_;
    if (pos_.x > 1280) { // Assuming screen width is 800
        active_ = false;
    }
}

void Bullet::Draw()
{
    if (active_) {
        Novice::DrawBox(int(pos_.x), int(pos_.y), 20, 20, 0.0f, WHITE, kFillModeSolid);
    }
}