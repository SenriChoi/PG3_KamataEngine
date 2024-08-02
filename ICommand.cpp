#include "ICommand.h"

void MoveRightCommand::Exec(Player& player)
{
	player.MoveRight();
}

void MoveLeftCommand::Exec(Player& player)
{
	player.MoveLeft();
}

void MoveUpCommand::Exec(Player& player)
{
	player.MoveUp();
}

void MoveDownCommand::Exec(Player& player)
{
	player.MoveDown();
}
void ShootCommand::Exec(Player& player)
{
	player.Shoot();
}