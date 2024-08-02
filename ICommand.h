#pragma once
#include "Player.h"

class Player;

class ICommand
{
public:
    virtual ~ICommand() {}
    virtual void Exec(Player& player) = 0;
};

class MoveRightCommand : public ICommand
{
public:
    void Exec(Player& player) override;
};

class MoveLeftCommand : public ICommand
{
public:
    void Exec(Player& player) override;
};

class MoveUpCommand : public ICommand
{
public:
    void Exec(Player& player) override;
};

class MoveDownCommand : public ICommand
{
public:
    void Exec(Player& player) override;
};

class ShootCommand : public ICommand
{
public:
    void Exec(Player& player) override;
};