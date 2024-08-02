#pragma once
#include "IScene.h"
#include "InputHandler.h"
#include "ICommand.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include"cal.h"
#include <vector>
#include <memory>

class StageScene : public IScene
{
public:
	void Init() override;
	void Update(char keys[], char preKeys[]) override;
	void Draw() override;


private:
	InputHandler* inputHandler_ = nullptr;
	ICommand* iCommand_ = nullptr;
	Player* player_ = nullptr;
	std::vector<Enemy*> enemies_;
	size_t activeEnemyCount_ = 0;
	bool CheckCollision(const Vector2& bulletPos, const Vector2& enemyPos);
	void HandleCollisionsRecursive(std::vector<Bullet*>& bullets, size_t bulletIndex, size_t enemyIndex);
};

void OnEnemyHit(Enemy* enemy);