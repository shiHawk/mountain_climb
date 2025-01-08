#include "SceneManager.h"
#include "DxLib.h"
#include "Pad.h"
#include "TitleScene.h"
#include "SceneMain.h"
#include "ResultScene.h"
#include <cassert>


SceneManager::SceneManager():
	m_kind(kTitleScene),
	m_pTitleScene(nullptr),
	m_pSceneMain(nullptr),
	m_pResultScene(nullptr)
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
	if (m_pResultScene != nullptr)
	{
		delete m_pResultScene;
		m_pResultScene = nullptr;
	}
}

void SceneManager::Init()
{
	switch (m_kind)
	{
	case SceneManager::kTitleScene:
		m_pTitleScene = new TitleScene();
		m_pTitleScene->Init();
		break;
	case SceneManager::kSceneMain:
		m_pSceneMain = new SceneMain();
		m_pSceneMain->Init();
		break;
	case SceneManager::kResultScene:
		m_pResultScene = new ResultScene();
		m_pResultScene->Init();
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
	case SceneManager::kTitleScene:
		m_pTitleScene->End();
		delete m_pTitleScene;
		m_pTitleScene = nullptr;
		break;
	case SceneManager::kSceneMain:
		m_pSceneMain->End();
		delete m_pSceneMain;
		m_pSceneMain = nullptr;
		break;
	case SceneManager::kResultScene:
		m_pResultScene->End();
		delete m_pResultScene;
		m_pResultScene = nullptr;
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
	Pad::Update();
	SceneKind nextKind = m_kind;

	switch (m_kind)
	{
	case SceneManager::kTitleScene:
		nextKind = m_pTitleScene->Update();
		break;
	case SceneManager::kSceneMain:
		nextKind = m_pSceneMain->Update();
		break;
	case SceneManager::kResultScene:
		nextKind = m_pResultScene->Update(&m_stage);
		break;
	case SceneManager::kSceneNum:
		break;
	default:
		assert(false);
		break;
	}
	if (nextKind != m_kind)
	{
		End();

		m_kind = nextKind;

		Init();
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
	case SceneManager::kResultScene:
		m_pResultScene->Draw(&m_stage);
		break;
	case SceneManager::kSceneNum:
		break;
	default:
		assert(false);
		break;
	}
}
