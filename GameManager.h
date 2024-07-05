#pragma once

#include <memory>//  unique_ptrのため
#include "IScene.h"//シーンの基底クラスに加えて
#include "StageScene.h"//各シーンを読み込む
#include "TitleScene.h"
#include "ClearScene.h"

class GameManager
{
private:
	//シーンを保持するメンバー変数
	std::unique_ptr<IScene> sceneArr_[3];

	//どのステージを呼び出すかを管理する変数
	int currentSceneNo_;//現在のシーン
	int prevSceneNo_;//前のシーン

public:
	GameManager();	//コンストラクタ
	~GameManager();	//デストラクタ

	int Run(char keys[], char preKeys[]);	//この関数でゲームループを呼び出す
};

