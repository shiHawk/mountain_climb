#include "TitleScene.h"
#include "DxLib.h"


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
	return SceneManager::SceneKind();
}

void TitleScene::Draw()
{
	DrawString(10, 10, "TitleScene", 0xffffff);
}
