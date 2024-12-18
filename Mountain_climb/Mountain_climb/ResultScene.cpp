#include "ResultScene.h"
#include "DxLib.h"
#include "Pad.h"

ResultScene::ResultScene()
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Init()
{
	int score = 0;
}

void ResultScene::End()
{
}

SceneManager::SceneKind ResultScene::Update()
{
	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		return SceneManager::SceneKind::kTitleScene;
	}
	return SceneManager::SceneKind::kResultScene;
}

void ResultScene::Draw(Stage* stage)
{
	int score = stage->BrokenBlock() * 100;
	DrawString(10, 10, "ResultScene", 0xffffff);
	DrawString(10, 30, "Press A Button", 0xffffff);
	DrawFormatString(10, 50, 0xffffff, "score:%d", score);
}
