#pragma once
#include "Vector2.h"
#include "Novice.h"
#include "Bullet.h"
#include <memory>
#include <vector>

class Player
{
public:
	//コンストラクタ
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

	//メンバ変数
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void Shoot();
	std::vector<Bullet*>& GetBullets() { return bullets_; }

private:
	Vector2 pos_;
	float speed_; 
	std::vector<Bullet*> bullets_;
	float shootCooldown = 0.5f; 
	float shootTimer = 0.0f;
};