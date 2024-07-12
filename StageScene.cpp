#include "StageScene.h"
void StageScene::Init(){
	//初期化
	inputHandler_ = new InputHandler();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();

	player_ = new Player();
}

void StageScene::Update(char keys[], char preKeys[])
{
	//Spaceキー
	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
		sceneNo = CLEAR;
	}
	//get input
	iCommand_ = inputHandler_->HandleInput();


	//set command
	if (this->iCommand_) {
		iCommand_->Exec(*player_);
	} 
	//update
	player_->Update();
}

void StageScene::Draw()
{
	Novice::ScreenPrintf(640, 360, "Stage");
	player_->Draw();
}