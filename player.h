#pragma once
#include "Vector2.h"
#include "Novice.h"
class Player
{
public:
	//コンストラクタ
	Player();

	void Init();
	void Update();
	void Draw();

	//メンバ変数
	void MoveRight();
	void MoveLeft();

private:
	Vector2 pos_;
	float speed_; 
};