#include "TitleScene.h"
#include "DxLib.h"
#include "Pad.h"

TitleScene::TitleScene():
	m_titleHandle(-1),
	m_buttonHandle(-1),
	m_blinkCount(0)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	m_titleHandle = LoadGraph("data/image/title.png");
	m_buttonHandle = LoadGraph("data/image/button.png");
}

void TitleScene::End()
{
	DeleteGraph(m_titleHandle);
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
	DrawGraph(-130, 0, m_titleHandle,true);
	DrawGraph(-140, -20, m_buttonHandle, true);
}
