#include "TitleScene.h"
void TitleScene::Init(){}

void TitleScene::Update(char keys[], char preKeys[])
{
	//Spaceキー
	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(640, 360, "Title");
}