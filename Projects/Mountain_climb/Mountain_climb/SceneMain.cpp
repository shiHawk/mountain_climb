#include "SceneMain.h"
#include "DxLib.h"
#include"Pad.h"

namespace
{
	// ゲームオーバーの文字が表示されるまでのフレーム数
	constexpr int kFadeFrame = 60;
	constexpr int kFadeOutFrame = 255;
}

SceneMain::SceneMain():
	m_bgmHandle(0),
	m_lifeHandle(-1),
	m_gameOverHandle(-1),
	m_gameoverFrameCount(0),
	m_lifeBackHandle(0),
	m_fadeFrameCount(0),
	m_fontHandle(0)
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
	m_timer.Init();
	m_bgmHandle = LoadSoundMem("data/image/bgm.mp3");
	m_lifeHandle = LoadGraph("data/image/Idle .png");
	m_lifeBackHandle = LoadGraph("data/image/LifeBack.png");
	m_gameOverHandle = LoadGraph("data/image/gameover.png");
	PlaySoundMem(m_bgmHandle, DX_PLAYTYPE_LOOP);
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
	m_timer.End();
	for (int i = 0; i < 3; i++)
	{
		m_life[i].End();
	}
	DeleteSoundMem(m_bgmHandle);
	DeleteGraph(m_lifeHandle);
	DeleteGraph(m_gameOverHandle);
	DeleteGraph(m_lifeBackHandle);
}

SceneManager::SceneKind SceneMain::Update()
{
	m_fadeFrameCount++;
	
	if (m_fadeFrameCount > 30)
	{
		m_fadeFrameCount = 0;
	}
	m_stage.Update(&m_player);
	m_player.Update();
	m_enemyData.Update();
	m_camera.Update(&m_player);
	m_goal.Update();
	m_timer.Update();
	Pad::Update();
	for (int i = 0; i < 3; i++)
	{
		m_life[i].Update();
	}
	
	
	// プレイヤーと敵の当たり判定
	bool isPlayerHit = false;
	
	// プレイヤーとゴールの当たり判定
	bool isGoalHit = true;

	if (m_player.GetPlayerHp() <= 0)
	{
		m_player.End();
		m_gameoverFrameCount += 1;
		return SceneManager::SceneKind::kTitleScene;
		/*if (m_gameoverFrameCount > kFadeOutFrame)
		{
			m_gameoverFrameCount = kGameOverFadeFrame;
			
		}*/
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
	m_timer.Draw();
	m_goal.Draw(&m_camera);
	DrawGraph(0, -3, m_lifeBackHandle, true);
	for (int i = 0; i < m_player.GetPlayerHp(); i++)
	{
		m_life[i].Draw();
	}

	// フェード処理
	int fadeAlpha = m_gameoverFrameCount;
	// m_fadeFrameaCount = 0の時fadeAlpha = 255 真っ黒

	/*SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeAlpha);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);*/
	if (m_player.GetPlayerHp() <= 0)
	{
		DrawGraph(125, 125, m_gameOverHandle, true);
	}
}
