#include "ResultScene.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	int changeScene = 1;
	int stageNumber = 1;
	bool returnTitle = false;
}

ResultScene::ResultScene():
	m_score(0),
	m_handle(-1),
	m_fontHandle(0),
	m_fontScoreHandle(0),
	m_rank(0)
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Init()
{
	m_fontHandle = CreateFontToHandle("Elephant", 32, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	m_fontScoreHandle = CreateFontToHandle("Elephant", 64, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
}

void ResultScene::End()
{
	DeleteFontToHandle(m_fontHandle);
}

SceneManager::SceneKind ResultScene::Update(Stage* stage)
{
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
	int blockBonus = m_stage.BrokenBlock();
	int remainingTimeBounus = 3000 - m_timer.RemainingTime();
	if (3000 - m_timer.RemainingTime() < 0)
	{
		remainingTimeBounus = 0;
	}

	if (remainingTimeBounus >= 2000)
	{
		m_rank = 1;
	}
	else if (remainingTimeBounus >= 1000)
	{
		m_rank = 2;
	}
	else
	{
		m_rank = 3;
	}
	m_score = blockBonus + remainingTimeBounus;
	DrawFormatStringToHandle(250, 10, 0xffffff, m_fontHandle, "Stage %d", stageNumber);
	DrawFormatStringToHandle(200, 400, 0xffffff, m_fontHandle, "Press A Button");
	DrawFormatStringToHandle(120, 200, 0x00ff00, m_fontScoreHandle, "Time:%d", remainingTimeBounus);
	DrawFormatStringToHandle(120,250, 0x00ff00,m_fontScoreHandle,"Score:%d",m_score);
}

