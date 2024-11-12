#include "SceneManager.h"
#include"DxLib.h"
#include "SceneMain.h"
#include "TitleScene.h"
#include <cassert>


SceneManager::SceneManager():
	m_kind(kSceneMain),
	m_pTitleScene(nullptr),
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
	if (m_pTitleScene != nullptr)
	{
		delete m_pTitleScene;
		m_pTitleScene = nullptr;
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
	case SceneManager::kTitleScene:
		m_pTitleScene = new TitleScene();
		m_pTitleScene->Init();
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
		m_pSceneMain->End();
		break;
	case SceneManager::kTitleScene:
		m_pTitleScene->End();
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
		m_pSceneMain->Update();
		break;
	case SceneManager::kTitleScene:
		m_pTitleScene->Update();
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
		m_pSceneMain->Draw();
		break;
	case SceneManager::kTitleScene:
		m_pTitleScene->Draw();
		break;
	default:
		assert(false);
		break;
	}
}
