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
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x505050FF, kFillModeSolid);//bg

	Novice::ScreenPrintf(640, 360, "Title");
}