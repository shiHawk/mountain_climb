#pragma once
#include "SceneManager.h"
class TitleScene
{
public:
	TitleScene();
	~TitleScene();
	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
private:
	// グラフィックハンドル
	int m_characterHandle;
	int m_titleHandle;
	int m_buttonHandle;

	// アニメーション関連
	int m_animFrame;	// フレーム数を数える
	int m_blinkCount;

	// ジャンプ処理
	bool  m_isJump;
	float m_jumpSpeed;

	Vec2 m_velocity;
	Vec2 m_pos;

	int m_fadeFrameCount;

	// BGM関連
	int m_bgmHandle;
	int m_valume;
};

