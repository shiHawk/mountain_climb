#include "ResultScene.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	int changeScene = 1;
	int stageNumber = 1;
}

ResultScene::ResultScene():
	m_score(0)
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Init()
{
	changeScene = 1;
}

void ResultScene::End()
{
}

SceneManager::SceneKind ResultScene::Update(Stage* stage)
{
	if (Pad::IsTrigger(PAD_INPUT_1) && changeScene == 1)
	{
		changeScene = 2;
		stage->ChangeStage();
		stageNumber++;
		return SceneManager::SceneKind::kSceneMain;
	}
	if (Pad::IsTrigger(PAD_INPUT_1) && changeScene == 2)
	{
		changeScene = 3;
		stage->ChangeStage();
		return SceneManager::SceneKind::kSceneMain;
	}
	if (Pad::IsTrigger(PAD_INPUT_1) && changeScene == 3)
	{
		changeScene = 0;
		stage->ChangeStage();
		stageNumber = 0;
		return SceneManager::SceneKind::kTitleScene;
	}
	return SceneManager::SceneKind::kResultScene;
}

void ResultScene::Draw(Stage* stage)
{
	m_score = stage->BrokenBlock();
	DrawFormatString(300, 10, 0xffffff, "Stage %d", stageNumber);
	DrawString(10, 30, "ResultScene", 0xffffff);
	DrawString(10, 50, "Press A Button", 0xffffff);
	DrawFormatString(10, 70, 0xffffff, "score:%d", m_score);
}

