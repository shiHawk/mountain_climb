#pragma once
#include "SceneManager.h"
#include "Score.h"
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
	int m_score;
	int m_handle;
	int m_fontHandle;
	int m_fontScoreHandle;
	int m_fontRankHandle;
	int m_bgHandle;
	int m_clearHandle;
	int m_rank;
	int m_gameOverFrameCount;
	int m_blinkCount;
	int m_bgmHandle;
	int m_valume;
	int m_seHandle;
	Player m_player;
	Stage m_stage;
	Timer m_timer;
};

