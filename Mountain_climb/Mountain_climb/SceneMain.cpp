#include "SceneMain.h"
#include "DxLib.h"
#include"Pad.h"

SceneMain::SceneMain()
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	m_stage.Init();
	m_player.Init();
}

void SceneMain::End()
{
	m_stage.End();
	m_player.End();
}

SceneManager::SceneKind SceneMain::Update()
{
	m_stage.Update(&m_player);
	m_player.Update();
	Pad::Update();
	return SceneManager::SceneKind::kSceneMain;
}



void SceneMain::Draw()
{
	m_stage.Draw();
	m_player.Draw();
}
