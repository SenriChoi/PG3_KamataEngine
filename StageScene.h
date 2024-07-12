#pragma once
#include "IScene.h"
#include "InputHandler.h"
#include "ICommand.h"
#include "Player.h"

class StageScene : public IScene
{
public:
	void Init() override;
	void Update(char keys[], char preKeys[]) override;
	void Draw() override;

private:
	InputHandler* inputHandler_ = nullptr;
	ICommand* iCommand_ = nullptr;
	Player* player_ = nullptr;

};