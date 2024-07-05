#include "ClearScene.h"

void ClearScene::Init(){}

void ClearScene::Update(char keys[], char preKeys[])
{
	//Spaceキー
	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(640, 360, "Clear");
}