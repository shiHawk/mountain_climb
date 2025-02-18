#pragma once
#include "SceneManager.h"
#include "Stage.h"
#include "Player.h"
#include "Timer.h"
class ResultScene
{
public:
	ResultScene();
	~ResultScene();

	void Init();
	void End();
	SceneManager::SceneKind Update(Stage* stage);
	void Draw();
private:
	// �\�������֌W
	int m_fontHandle;
	int m_fontScoreHandle;
	int m_fontRankHandle;
	int m_clearHandle;

	// �w�i
	int m_bgHandle;
	
	// BGM�֌W
	int m_bgmHandle;
	int m_valume;

	// �X�R�A�֌W
	int m_score;
	int m_rank;

	int m_FadeFrameCount;
	int m_blinkCount;
	
	Player m_player;
	Stage m_stage;
	Timer m_timer;
};

