#include "TitleScene.h"
#include "DxLib.h"
#include "Pad.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
}

void TitleScene::End()
{
}

SceneManager::SceneKind TitleScene::Update()
{
	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		return SceneManager::SceneKind::kSceneMain;
	}
	return SceneManager::SceneKind::kTitleScene;
}

void TitleScene::Draw()
{
	DrawString(10, 10, "TitleScene", 0xffffff);
	DrawString(10, 30, "Press A Button", 0xffffff); 
}
