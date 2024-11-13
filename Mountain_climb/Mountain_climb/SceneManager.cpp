#include "SceneManager.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "SceneMain.h"
#include "Pad.h"
#include <cassert>


SceneManager::SceneManager():
	m_kind(kSceneMain),
	m_pTitleScene(nullptr),
	m_pSceneMain(nullptr)
{
}

SceneManager::~SceneManager()
{
	if (m_pTitleScene != nullptr)
	{
		delete m_pTitleScene;
		m_pTitleScene = nullptr;
	}
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
	case SceneManager::kTitleScene:
		m_pTitleScene = new TitleScene();
		m_pTitleScene->Init();
		break;
	case SceneManager::kSceneNum:
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
		delete m_pSceneMain;
		m_pSceneMain = nullptr;
		break;
	case SceneManager::kTitleScene:
		m_pTitleScene->End();
		delete m_pTitleScene;
		m_pTitleScene = nullptr;
		break;
	case SceneManager::kSceneNum:
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
	case SceneManager::kSceneNum:
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
	case SceneManager::kSceneNum:
		break;
	default:
		assert(false);
		break;
	}
}
