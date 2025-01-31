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
	int m_titleHandle;
	int m_buttonHandle;
	int m_blinkCount;
	// グラフィックハンドル
	int m_handleIdle;
	// アニメーション関連
	int m_animFrame;	// フレーム数を数える
	// ジャンプ処理
	bool m_isJump;
	float m_jumpSpeed;
	Vec2 m_velocity;
	Vec2 m_pos;
	int m_scalingX;
	int m_scalingY;
};

