#include "StageScene.h"
#include <vector>
void StageScene::Init(){
	//初期化

	inputHandler_ = new InputHandler();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveUpCommand2PressKeyW();
	inputHandler_->AssignMoveDownCommand2PressKeyS();
	inputHandler_->AssignShootCommand2PressKeySpace();


	player_ = new Player();

	enemies_.push_back(new Enemy(Vector2{ 800.0f, 100.0f }));
	enemies_.push_back(new Enemy(Vector2{ 1000.0f, 300.0f }));
	enemies_.push_back(new Enemy(Vector2{ 1200.0f, 500.0f }));


    for (Enemy* enemy : enemies_) {
        enemy->SetHitCallback(OnEnemyHit);
    }

    activeEnemyCount_ = enemies_.size();

}

bool StageScene::CheckCollision(const Vector2& bulletPos, const Vector2& enemyPos) {
    float bulletLeft = bulletPos.x - 5; // 10 / 2
    float bulletRight = bulletPos.x + 5; // 10 / 2
    float bulletTop = bulletPos.y - 5; // 10 / 2
    float bulletBottom = bulletPos.y + 5; // 10 / 2

    float enemyLeft = enemyPos.x - 25; // 50 / 2
    float enemyRight = enemyPos.x + 25; // 50 / 2
    float enemyTop = enemyPos.y - 25; // 50 / 2
    float enemyBottom = enemyPos.y + 25; // 50 / 2

    return bulletRight > enemyLeft && bulletLeft < enemyRight &&
        bulletBottom > enemyTop && bulletTop < enemyBottom;
}

void StageScene::HandleCollisionsRecursive(std::vector<Bullet*>& bullets, size_t bulletIndex, size_t enemyIndex) {
    if (bulletIndex >= bullets.size() || enemyIndex >= enemies_.size()) {
        return; 
    }

    Bullet* bullet = bullets[bulletIndex];
    Enemy* enemy = enemies_[enemyIndex];

    if (bullet && bullet->IsActive() && enemy && enemy->IsActive()) {
        if (CheckCollision(bullet->GetPosition(), enemy->GetPosition())) {
            bullet->Deactivate();
            enemy->Deactivate();
            activeEnemyCount_ -= 1;
            delete bullet;
            bullets.erase(bullets.begin() + bulletIndex);
            delete enemy;
            enemies_.erase(enemies_.begin() + enemyIndex);            
            HandleCollisionsRecursive(bullets, bulletIndex, enemyIndex);
        }
        else { 
            HandleCollisionsRecursive(bullets, bulletIndex + 1, enemyIndex);
        }
    }
    else {
        HandleCollisionsRecursive(bullets, bulletIndex + 1, enemyIndex);
    }
}

void StageScene::Update(char keys[], char preKeys[])
{
    // Space C
    if (!preKeys[DIK_C] && keys[DIK_C]) {

    }

    if (activeEnemyCount_ <= 0) {
        sceneNo = CLEAR;
    }

    // get input
    std::vector<ICommand*> commands = inputHandler_->HandleInput();

    // set command
    for (ICommand* command : commands) {
        if (command) {
            command->Exec(*player_);
        }
    }

    // update player
    player_->Update();

    // update enemies using template function
    for (Enemy* enemy : enemies_) {
        if (enemy) {
            UpdatePosition(enemy);
        }
    }

    // update bullets using template function
    for (auto it = player_->GetBullets().begin(); it != player_->GetBullets().end();) {
        Bullet* bullet = *it;
        if (bullet) {
            UpdatePosition(bullet);
            if (!bullet->IsActive()) {
                delete bullet;
                it = player_->GetBullets().erase(it);
            }
            else {
                ++it;
            }
        }
    }

    // handle collisions using recursive function
    HandleCollisionsRecursive(player_->GetBullets(), 0, 0);
}



void StageScene::Draw()
{
    Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);//bg
	Novice::ScreenPrintf(640, 360, "Stage");
	player_->Draw();

	for (Enemy* enemy : enemies_) {
		if (enemy) {
			enemy->Draw();
		}
	}

    for (Bullet* bullet : player_->GetBullets()) {
        if (bullet) {
            bullet->Draw();
        }
    }
}

void OnEnemyHit(Enemy* enemy) {
    Novice::ScreenPrintf(int(enemy->GetPosition().x), int(enemy->GetPosition().y), "Hit!");
}