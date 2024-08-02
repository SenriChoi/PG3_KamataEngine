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

    activeEnemyCount_ = enemies_.size();

}

void StageScene::Update(char keys[], char preKeys[])
{
	//Spaceキー
	if (!preKeys[DIK_C] && keys[DIK_C]) {
		sceneNo = CLEAR;
	}
    if (activeEnemyCount_ <= 0) {
        sceneNo = CLEAR;
    }
	//get input
	std::vector<ICommand*> commands = inputHandler_->HandleInput();


	//set command
	for (ICommand* command : commands) {
		if (command) {
			command->Exec(*player_);
		}
	}
	//update
	player_->Update();

	for (Enemy* enemy : enemies_) {
		if (enemy) {
			enemy->Update();
		}
	}

    // Update bullets
    for (auto it = player_->GetBullets().begin(); it != player_->GetBullets().end(); ) {
        Bullet* bullet = *it;
        if (bullet) {
            bullet->Update();
            if (!bullet->IsActive()) {
                delete bullet;
                it = player_->GetBullets().erase(it);
            }
            else {
                ++it;
            }
        }
    }

    // Check for collisions between bullets and enemies
    for (auto bulletIt = player_->GetBullets().begin(); bulletIt != player_->GetBullets().end(); ) {
        Bullet* bullet = *bulletIt;
        if (bullet) {
            Vector2 bulletPos = bullet->GetPosition();
            bool bulletHit = false;

            for (Enemy* enemy : enemies_) {
                if (enemy && enemy->IsActive()) {
                    Vector2 enemyPos = enemy->GetPosition();

                    // Calculate the bounds for collision detection
                    float bulletLeft = bulletPos.x - 10; // 10 / 2
                    float bulletRight = bulletPos.x + 10; // 10 / 2
                    float bulletTop = bulletPos.y - 10; // 10 / 2
                    float bulletBottom = bulletPos.y + 10; // 10 / 2

                    float enemyLeft = enemyPos.x - 25; // 50 / 2
                    float enemyRight = enemyPos.x + 25; // 50 / 2
                    float enemyTop = enemyPos.y - 25; // 50 / 2
                    float enemyBottom = enemyPos.y + 25; // 50 / 2

                    // Check for overlap
                    if (bulletRight > enemyLeft && bulletLeft < enemyRight &&
                        bulletBottom > enemyTop && bulletTop < enemyBottom) {
                        // Collision detected
                        bullet->Deactivate(); // Deactivate the bullet
                        enemy->Deactivate();// Deactivate the 
                        activeEnemyCount_ -= 1;
                        delete bullet;
                        bulletIt = player_->GetBullets().erase(bulletIt);
                        bulletHit = true;
                        break; // Exit the loop once the bullet is processed
                    }
                }
            }

            if (!bulletHit) {
                ++bulletIt;
            }
        }
    }
}



void StageScene::Draw()
{
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