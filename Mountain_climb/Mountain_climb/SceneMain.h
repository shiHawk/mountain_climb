#pragma once
#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "Goal.h"
#include "Score.h"

class SceneMain
{
public:
	SceneMain();
	~SceneMain();

	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
	int m_bgmHandle;
private:
	Stage m_stage;
	Player m_player;
	Enemy m_enemy[7];
	Camera m_camera;
	Goal m_goal;
	Score m_score;
};

