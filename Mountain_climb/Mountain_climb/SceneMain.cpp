#include "SceneMain.h"
#include "DxLib.h"
#include"Pad.h"

namespace
{

}

SceneMain::SceneMain():
	m_bgmHandle(0),
	m_lifeHandle(-1)
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
	m_enemyData.Init();
	m_goal.Init();
	m_bgmHandle = LoadSoundMem("data/image/bgm.mp3");
	m_lifeHandle = LoadGraph("data/image/Idle .png");

	for (int i = 0; i < 3; i++)
	{
		m_life[i].Init();
		m_life[i].SetHandle(m_lifeHandle);
		m_life[i].SetIndex(i);
	}
}

void SceneMain::End()
{
	m_stage.End();
	m_player.End();
	m_enemyData.End();
	m_goal.End();
	for (int i = 0; i < 3; i++)
	{
		m_life[i].End();
	}
	DeleteSoundMem(m_bgmHandle);
	DeleteGraph(m_lifeHandle);
}

SceneManager::SceneKind SceneMain::Update()
{
	m_stage.Update(&m_player,&m_score);
	m_player.Update();
	m_enemyData.Update();
	m_camera.Update(&m_player);
	m_goal.Update();
	Pad::Update();
	for (int i = 0; i < 3; i++)
	{
		m_life[i].Update();
	}
	PlaySoundMem(m_bgmHandle, DX_PLAYTYPE_LOOP);
	
	// プレイヤーと敵の当たり判定
	bool isPlayerHit = false;
	
	// プレイヤーとゴールの当たり判定
	bool isGoalHit = true;

	if (m_player.GetPlayerHp() <= 0)
	{
		return SceneManager::SceneKind::kTitleScene;
	}

	for (int i = 0; i < kEnemyNum; i++)
	{
		// 敵1体1体との当たり判定
		bool isTempHit = true;
		Enemy enemy = m_enemyData.GetEnemyDate(i);
		if (m_player.GetLeft() > enemy.GetRight())
		{
			isTempHit = false;
		}
		if (m_player.GetTop() > enemy.GetBottom())
		{
			isTempHit = false;
		}
		if (m_player.GetRight() < enemy.GetLeft())
		{
			isTempHit = false;
		}
		if (m_player.GetBottom() < enemy.GetTop())
		{
			isTempHit = false;
		}

		if (isTempHit)
		{
			isPlayerHit = true;
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
	m_enemyData.Draw(&m_camera);
	m_goal.Draw(&m_camera);
	for (int i = 0; i < m_player.GetPlayerHp(); i++)
	{
		m_life[i].Draw();
	}
}
