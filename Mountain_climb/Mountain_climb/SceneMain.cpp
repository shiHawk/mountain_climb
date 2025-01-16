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
	for (int i = 0; i < 2; i++)
	{
		m_enemy[i].Init();
	
	}
	m_goal.Init();
}

void SceneMain::End()
{
	m_stage.End();
	m_player.End();
	for (int i = 0; i < 2; i++)
	{
		m_enemy[i].End();
	}
	m_goal.End();
}

SceneManager::SceneKind SceneMain::Update()
{
	m_stage.Update(&m_player,&m_score);
	m_player.Update();
	for (int i = 0; i < 2; i++)
	{
		m_enemy[i].Update();
	}
	m_camera.Update(&m_player);
	m_goal.Update();
	Pad::Update();

	// �v���C���[�ƓG�̓����蔻��
	bool isPlayerHit = true;
	// �v���C���[�ƃS�[���̓����蔻��
	bool isGoalHit = true;

	if (m_player.GetPlayerHp() <= 0)
	{
		return SceneManager::SceneKind::kTitleScene;
	}

	for (int i = 0; i < 2; i++)
	{
		if (m_player.GetLeft() > m_enemy[i].GetRight())
		{
			isPlayerHit = false;
		}
		if (m_player.GetTop() > m_enemy[i].GetBottom())
		{
			isPlayerHit = false;
		}
		if (m_player.GetRight() < m_enemy[i].GetLeft())
		{
			isPlayerHit = false;
		}
		if (m_player.GetBottom() < m_enemy[i].GetTop())
		{
			isPlayerHit = false;
		}
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
	for (int i = 0; i < 2; i++)
	{
		m_enemy[i].Draw(&m_camera);
	}
	m_goal.Draw(&m_camera);
}
