#include "SceneManager.h"
#include"DxLib.h"
#include "SceneMain.h"
#include <cassert>

SceneManager::SceneManager():
	m_kind(kSceneMain),
	m_pSceneMain(nullptr)
{
}

SceneManager::~SceneManager()
{
	if (m_pSceneMain != nullptr)
	{
		delete m_pSceneMain;
		m_pSceneMain = nullptr;
	}
}

void SceneManager::Init()
{
	switch (m_kind)
	{
	case SceneManager::kSceneMain:
		m_pSceneMain = new SceneMain();
		m_pSceneMain->Init();
		break;
	default:
		assert(false);
		break;
	}
}

void SceneManager::End()
{
	switch (m_kind)
	{
	case SceneManager::kSceneMain:
		m_pSceneMain = new SceneMain();
		m_pSceneMain->End();
		break;
	default:
		assert(false);
		break;
	}
}

void SceneManager::Update()
{
	switch (m_kind)
	{
	case SceneManager::kSceneMain:
		m_pSceneMain = new SceneMain();
		m_pSceneMain->Update();
		break;
	default:
		assert(false);
		break;
	}
}

void SceneManager::Draw()
{
	switch (m_kind)
	{
	case SceneManager::kSceneMain:
		m_pSceneMain = new SceneMain();
		m_pSceneMain->Draw();
		break;
	default:
		assert(false);
		break;
	}
}
