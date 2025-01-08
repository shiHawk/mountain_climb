#include "ResultScene.h"
#include "DxLib.h"
#include "Pad.h"

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
	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		stage->ChangeStage();
		return SceneManager::SceneKind::kTitleScene;
	}
	return SceneManager::SceneKind::kResultScene;
}

void ResultScene::Draw(Stage* stage)
{
	m_score = stage->BrokenBlock();
	DrawString(10, 10, "ResultScene", 0xffffff);
	DrawString(10, 30, "Press A Button", 0xffffff);
	DrawFormatString(10, 50, 0xffffff, "score:%d", m_score);
}

