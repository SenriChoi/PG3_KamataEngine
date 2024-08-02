#pragma once
#include "Vector2.h"
#include "Novice.h"
#include"cal.h"

class Enemy {
public:
    Enemy(Vector2 pos);

    typedef void (*HitCallback)(Enemy*);
    void SetHitCallback(HitCallback callback) { hitCallback_ = callback; }

    void Update();
    void Draw();
    bool IsActive() const { return active_; }
    void Deactivate();
    Vector2 GetPosition() const { return pos_; }



private:
    Vector2 pos_;
    float speed_;
    bool active_;
    float direction_;
    HitCallback hitCallback_;
};