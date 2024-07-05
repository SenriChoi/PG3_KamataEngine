#include "StageScene.h"
void StageScene::Init(){}

void StageScene::Update(char keys[], char preKeys[])
{
	//Spaceキー
	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
		sceneNo = CLEAR;
	}
}

void StageScene::Draw()
{
	Novice::ScreenPrintf(640, 360, "Stage");
}