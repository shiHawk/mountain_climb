#include "SceneMain.h"
#include "DxLib.h"
#include"Pad.h"

SceneMain::SceneMain()
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	m_player.Init(&m_camera);
	m_camera.Init();
	m_stage.Init();
	

	m_enemy.Init();
	m_goal.Init();
}

void SceneMain::End()
{
	m_stage.End();
	m_player.End();
	m_enemy.End();
	m_goal.End();
}

SceneManager::SceneKind SceneMain::Update()
{
	m_stage.Update(&m_player,&m_score);
	m_player.Update();
	m_enemy.Update();
	m_camera.Update(&m_player);
	m_goal.Update();
	Pad::Update();

	// プレイヤーと敵の当たり判定
	bool isPlayerHit = true;
	// プレイヤーとゴールの当たり判定
	bool isGoalHit = true;

	if (m_player.GetPlayerHp() <= 0)
	{
		return SceneManager::SceneKind::kTitleScene;
	}

	if (m_player.GetLeft() > m_enemy.GetRight())
	{
		isPlayerHit = false;
	}
	if (m_player.GetTop() > m_enemy.GetBottom())
	{
		isPlayerHit = false;
	}
	if (m_player.GetRight() < m_enemy.GetLeft())
	{
		isPlayerHit = false;
	}
	if (m_player.GetBottom() < m_enemy.GetTop())
	{
		isPlayerHit = false;
	}


	if (m_player.GetLeft() > m_goal.GetRight())
	{
		isGoalHit = false;
	}
	if (m_player.GetTop() > m_goal.GetBottom())
	{
		isGoalHit = false;
	}
	if (m_player.GetRight() < m_goal.GetLeft())
	{
		isGoalHit = false;
	}
	if (m_player.GetBottom() < m_goal.GetTop())
	{
		isGoalHit = false;
	}

	if (isPlayerHit)
	{
		m_player.OnDamage();
	}

	if (isGoalHit)
	{
		return SceneManager::SceneKind::kResultScene;
	}
	return SceneManager::SceneKind::kSceneMain;
}



void SceneMain::Draw()
{
	m_stage.Draw(&m_camera);
	m_player.Draw();
	m_enemy.Draw(&m_camera);
	m_goal.Draw(&m_camera);
}
