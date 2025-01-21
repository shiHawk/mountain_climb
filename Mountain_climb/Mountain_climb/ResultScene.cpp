#include "ResultScene.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	int changeScene = 1;
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
	
}

void ResultScene::End()
{
}

SceneManager::SceneKind ResultScene::Update(Stage* stage)
{
	if (Pad::IsTrigger(PAD_INPUT_1) && changeScene == 1)
	{
		changeScene = 1;
		stage->ChangeStage();
		return SceneManager::SceneKind::kSceneMain;
	}
	else if (Pad::IsTrigger(PAD_INPUT_1) && changeScene == 2)
	{
		changeScene = 2;
		stage->ChangeStage();
		return SceneManager::SceneKind::kSceneMain;
	}
	else if (Pad::IsTrigger(PAD_INPUT_1) && changeScene == 3)
	{
		changeScene = 0;
		stage->ChangeStage();
		return SceneManager::SceneKind::kTitleScene;
	}
	return SceneManager::SceneKind::kResultScene;
}

void ResultScene::Draw(Stage* stage)
{
	m_score = stage->BrokenBlock();
	DrawFormatString(300, 10, 0xffffff, "Stage %d", changeScene);
	DrawString(10, 30, "ResultScene", 0xffffff);
	DrawString(10, 50, "Press A Button", 0xffffff);
	DrawFormatString(10, 70, 0xffffff, "score:%d", m_score);
}

