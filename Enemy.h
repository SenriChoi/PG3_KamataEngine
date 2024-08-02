#pragma once
#include "Vector2.h"
#include "Novice.h"

class Enemy {
public:
    Enemy(Vector2 pos);

    void Update();
    void Draw();
    bool IsActive() const { return active_; }
    void Deactivate() { active_ = false; }
    Vector2 GetPosition() const { return pos_; }

private:
    Vector2 pos_;
    float speed_;
    bool active_;
    float direction_;
};