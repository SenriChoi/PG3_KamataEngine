#include "ClearScene.h"

void ClearScene::Init(){}

void ClearScene::Update(char keys[], char preKeys[])
{
	//Spaceキー
	if (!preKeys[DIK_C] && keys[DIK_C]) {
		sceneNo = TITLE;
	}
}
void ClearScene::Draw()
{
	Novice::ScreenPrintf(400, 360, "Clear");
	Novice::ScreenPrintf(400, 380, "Press the 'C' key to return to the title screen.");

}