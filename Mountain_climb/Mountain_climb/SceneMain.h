#pragma once
#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"
#include "EnemyDate.h"
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
	EnemyDate m_enemyDate;
	Camera m_camera;
	Goal m_goal;
	Score m_score;
};

