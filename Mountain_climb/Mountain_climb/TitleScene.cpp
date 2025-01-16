#include "TitleScene.h"
#include "DxLib.h"
#include "Pad.h"

TitleScene::TitleScene():
	m_handle(-1),
	m_buttonHandle(-1)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	m_handle = LoadGraph("data/image/title.png");
	m_buttonHandle = LoadGraph("data/image/button.png");
}

void TitleScene::End()
{
	DeleteGraph(m_handle);
	DeleteGraph(m_buttonHandle);
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
	DrawGraph(-130, 0,m_handle,true);
	DrawGraph(-140, -20, m_buttonHandle, true);
}
