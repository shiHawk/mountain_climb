#pragma once
#include"Score.h"
#include "Stage.h"

class TitleScene;
class SceneMain;
class ResultScene;
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init();
	void End();

	void Update();
	void Draw();
public:
	// 列挙型を使用して現在実行中のシーンを管理する
	enum SceneKind
	{
		kTitleScene,
		kSceneMain,
		kResultScene,
		kSceneNum
	};
private:
	Stage m_stage;
	// 現在実行中のシーン
	SceneKind m_kind;

	TitleScene* m_pTitleScene;
	SceneMain* m_pSceneMain;
	ResultScene* m_pResultScene;
};

