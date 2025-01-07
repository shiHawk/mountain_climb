#pragma once
#include "Player.h"
class Timer
{
public:
	Timer();
	~Timer();
	void Init();
	void End();
	void Update();
	void Draw();
private:
	Player m_player;
};

