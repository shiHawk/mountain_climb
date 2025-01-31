#include "ResultScene.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	int changeScene = 1;
	int stageNumber = 1;
	bool returnTitle = false;
	int bgX = 0;
	int bgY = 0;
	int scrollSpeed = 1;
}

ResultScene::ResultScene():
	m_score(0),
	m_handle(-1),
	m_fontHandle(0),
	m_fontScoreHandle(0),
	m_bgHandle(0),
	m_rank(0),
	m_fontRankHandle(0)
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Init()
{
	m_fontHandle = CreateFontToHandle("Elephant", 32, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	m_fontScoreHandle = CreateFontToHandle("Elephant", 64, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	m_fontRankHandle = CreateFontToHandle("Bodoni MT Black", 64, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	m_bgHandle = LoadGraph("data/image/bg.png");
	bgX = 0;
	bgY = 0;
}

void ResultScene::End()
{
	DeleteFontToHandle(m_fontHandle);
	DeleteFontToHandle(m_fontScoreHandle);
	DeleteGraph(m_bgHandle);
}

SceneManager::SceneKind ResultScene::Update(Stage* stage)
{
	bgX -= scrollSpeed;
	if (Pad::IsTrigger(PAD_INPUT_1) && changeScene == 1)
	{
		changeScene = 2;
		stage->ChangeStage();
		stageNumber++;
		returnTitle = false;
		return SceneManager::SceneKind::kSceneMain;
	}
	if (Pad::IsTrigger(PAD_INPUT_1) && changeScene == 2)
	{
		changeScene = 3;
		stage->ChangeStage();
		stageNumber++;
		returnTitle = true;
		return SceneManager::SceneKind::kSceneMain;
	}
	if (Pad::IsTrigger(PAD_INPUT_1) && returnTitle)
	{
		changeScene = 1;
		stageNumber = 1;
		returnTitle = false;
		stage->ChangeStage();
		return SceneManager::SceneKind::kTitleScene;
	}
	return SceneManager::SceneKind::kResultScene;
}

void ResultScene::Draw()
{
	if (bgX == -1000)
	{
		bgX = 0;
	}
	DrawGraph(bgX, bgY, m_bgHandle, true);
	DrawGraph(bgX+1000, 0, m_bgHandle, true);
	int blockBonus = m_stage.BrokenBlock();
	int remainingTimeBounus = 3000 - m_timer.RemainingTime();
	m_score = blockBonus + remainingTimeBounus;
	if (3000 - m_timer.RemainingTime() < 0)
	{
		remainingTimeBounus = 0;
	}

	if (remainingTimeBounus >= 2000)
	{
		DrawFormatStringToHandle(120, 300, 0xffffff, m_fontRankHandle, "Rank A");
	}
	else if (remainingTimeBounus >= 1000)
	{
		DrawFormatStringToHandle(120, 300, 0xffffff, m_fontRankHandle, "Rank B");
	}
	else
	{
		DrawFormatStringToHandle(120, 300, 0xffffff, m_fontRankHandle, "Rank C");
	}
	
	DrawFormatStringToHandle(250, 10, 0xffffff, m_fontHandle, "Stage %d", stageNumber);
	DrawFormatStringToHandle(200, 400, 0xffffff, m_fontHandle, "Press A Button");
	DrawFormatStringToHandle(120, 150, 0xba55d3, m_fontScoreHandle, "Block:%d",blockBonus);
	DrawFormatStringToHandle(120, 200, 0xba55d3, m_fontScoreHandle, "Time:%d", remainingTimeBounus);
	DrawFormatStringToHandle(120,250, 0xba55d3,m_fontScoreHandle,"Score:%d",m_score);
}

