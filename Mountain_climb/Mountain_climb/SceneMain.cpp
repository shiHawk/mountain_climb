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
	m_stage.Init();
	m_player.Init();
	m_enemy.Init();
}

void SceneMain::End()
{
	m_stage.End();
	m_player.End();
	m_enemy.End();
}

SceneManager::SceneKind SceneMain::Update()
{
	m_stage.Update(&m_player);
	m_player.Update();
	m_enemy.Update();
	Pad::Update();

	bool isPlayerHit = true;

	if (m_player.GetPlayerHp() <= 0)
	{
		//return SceneManager::SceneKind::kTitleScene;
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

	if (isPlayerHit)
	{
		m_player.OnDamage();
	}
	return SceneManager::SceneKind::kSceneMain;
}



void SceneMain::Draw()
{
	m_stage.Draw();
	m_player.Draw();
	m_enemy.Draw();
}
