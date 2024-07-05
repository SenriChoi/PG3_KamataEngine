#pragma once
#include "Novice.h"

enum SCENE {
	TITLE,
	STAGE,
	CLEAR,
};
class IScene
{
protected:
	//シーン番号を管理する変数
	static int sceneNo;

public:
	//継承先で実装される関数
	//抽象クラスなので純粋仮想関数とする
	virtual void Init() = 0;
	virtual void Update(char keys[], char preKeys[]) = 0;
	virtual void Draw() = 0;

	//仮想デストラクタを用意しないと警告される
	virtual ~IScene();

	//シーン番号のゲッター
	int GetSceneNo();


};

