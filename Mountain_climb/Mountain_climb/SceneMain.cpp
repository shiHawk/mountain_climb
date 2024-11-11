#include "SceneMain.h"

SceneMain::SceneMain()
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	m_stage.Init();
}

void SceneMain::End()
{
	m_stage.End();
}

SceneManager::SceneKind SceneMain::Update()
{
	m_stage.Update();
	return SceneManager::SceneKind::kSceneMain;
}



void SceneMain::Draw()
{
	m_stage.Draw();
}
