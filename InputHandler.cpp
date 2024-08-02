#include "InputHandler.h"
#include "Novice.h"


std::vector<ICommand*> InputHandler::HandleInput()
{
    std::vector<ICommand*> commands;

    if (Novice::CheckHitKey(DIK_D)) {
        commands.push_back(pressKeyD_);
    }
    if (Novice::CheckHitKey(DIK_A)) {
        commands.push_back(pressKeyA_);
    }
    if (Novice::CheckHitKey(DIK_W)) {
        commands.push_back(pressKeyW_);
    }
    if (Novice::CheckHitKey(DIK_S)) {
        commands.push_back(pressKeyS_);
    }
    if (Novice::CheckHitKey(DIK_SPACE)) {
        commands.push_back(pressKeySpace_);
    }


    return commands;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
	ICommand* command = new MoveLeftCommand();
	this->pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommand2PressKeyD()
{
	ICommand* command = new MoveRightCommand();
	this->pressKeyD_ = command;
}

void InputHandler::AssignMoveUpCommand2PressKeyW()
{
	ICommand* command = new MoveUpCommand();
	this->pressKeyW_ = command;
}

void InputHandler::AssignMoveDownCommand2PressKeyS()
{
	ICommand* command = new MoveDownCommand();
	this->pressKeyS_ = command;
}

void InputHandler::AssignShootCommand2PressKeySpace()
{
    ICommand* command = new ShootCommand();
    this->pressKeySpace_ = command;
}