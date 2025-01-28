#pragma once
#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"
#include "EnemyData.h"
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
	EnemyData m_enemyData;
	Camera m_camera;
	Goal m_goal;
	Score m_score;
};

