#pragma once

class TitleScene;
class SceneMain;
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
		kSceneMain,
		kTitleScene
	};
private:

	// 現在実行中のシーン
	SceneKind m_kind;

	SceneMain* m_pSceneMain;
	TitleScene* m_pTitleScene;
};

