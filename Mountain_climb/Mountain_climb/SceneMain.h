#pragma once
#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"

class SceneMain
{
public:
	SceneMain();
	~SceneMain();

	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
private:
	Stage m_stage;
	Player m_player;
};

