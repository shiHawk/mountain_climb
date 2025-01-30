#include "SceneMain.h"
#include "DxLib.h"
#include"Pad.h"

namespace
{
	// �Q�[���I�[�o�[�̕������\�������܂ł̃t���[����
	constexpr int kGameoverFadeFrame = 60;
	constexpr int kFadeOutFrame = 255;
}

SceneMain::SceneMain():
	m_bgmHandle(0),
	m_lifeHandle(-1),
	m_gameOverHandle(-1),
	m_gameoverFrameCount(0)
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
}

SceneManager::SceneKind SceneMain::Update()
{
	m_fadeFrameCount++;
	if (m_fadeFrameCount > 30)
	{
		m_fadeFrameCount = 0;
	}
	m_stage.Update(&m_player,&m_score);
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
	PlaySoundMem(m_bgmHandle, DX_PLAYTYPE_LOOP);
	
	// �v���C���[�ƓG�̓����蔻��
	bool isPlayerHit = false;
	
	// �v���C���[�ƃS�[���̓����蔻��
	bool isGoalHit = true;

	if (m_player.GetPlayerHp() <= 0)
	{
		m_gameoverFrameCount += 2;
		if (m_gameoverFrameCount > kFadeOutFrame)
		{
			m_gameoverFrameCount = kGameoverFadeFrame;
			return SceneManager::SceneKind::kTitleScene;
		}
	}

	for (int i = 0; i < kEnemyNum; i++)
	{
		// �G1��1�̂Ƃ̓����蔻��
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
	for (int i = 0; i < m_player.GetPlayerHp(); i++)
	{
		m_life[i].Draw();
	}

	// �Q�[���I�[�o�[�̕\��
	if (m_player.GetPlayerHp() <= 0)
	{
		// 0~60�̊Ԃŕω�����m_gameoverFrameCount��
		// 0~255�̒l�ɕϊ�����K�v������

		// �������g�p���ĕϊ����s��
		// m_gameoverFrameCount��i�s�����ɕϊ�����
		float progressRate = static_cast<float>(m_gameoverFrameCount) / kGameoverFadeFrame;
		//printfDx("%f %%\n", progressRate);

		// ���������ۂ̓����x�ɕϊ�����
		int alpha = static_cast <int>(255 * progressRate);

		// �����ȍ~�ɌĂ΂��Draw�֐��̕`����@��ύX����
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

		/*int width = GetDrawStringWidthToHandle("GAME OVER", strlen("GAME OVER"), m_fontHandle);
		DrawStringToHandle(Game::kScreenWidth / 2 - width / 2, Game::kScreenHeight / 2 - 64 / 2,
			"GAME OVER", GetColor(255, 0, 0), m_fontHandle);*/

		// �ȍ~�̕\�������������Ȃ�Ȃ��悤�Ɍ��̐ݒ�ɖ߂��Ă���
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	// �t�F�[�h����
	int fadeAlpha = m_gameoverFrameCount;
	// m_fadeFrameaCount = 0�̎�fadeAlpha = 255 �^����

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeAlpha);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
