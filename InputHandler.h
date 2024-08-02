#pragma once
#include "ICommand.h"
#include <vector>

class InputHandler
{
public:
	std::vector<ICommand*> HandleInput();
	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveRightCommand2PressKeyD();
	void AssignMoveUpCommand2PressKeyW();
	void AssignMoveDownCommand2PressKeyS();
	void AssignShootCommand2PressKeySpace();

private:
	ICommand* pressKeyA_;
	ICommand* pressKeyD_;
	ICommand* pressKeyW_;
	ICommand* pressKeyS_;
	ICommand* pressKeySpace_;
} ;