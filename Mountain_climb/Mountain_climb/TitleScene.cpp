#include "TitleScene.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	// キャラクターグラフィックの幅と高さ
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;

	// アニメーションのコマ数
	constexpr int kIdleAnimNum = 11;
	// アニメーション1コマのフレーム数
	constexpr int kSingleAnimFrame = 2;
	// ジャンプ処理
	constexpr float kJumpPower = -7.6f;	// ジャンプの初速
	// 重力
	float kJumpGravity = 0.2f;
	float kGravity = 0.3f;
}

TitleScene::TitleScene():
	m_titleHandle(-1),
	m_buttonHandle(-1),
	m_blinkCount(0),
	m_handleIdle(-1),
	m_animFrame(0),
	m_isJump(false),
	m_jumpSpeed(0),
	m_pos(80,330),
	m_scalingX(281),
	m_scalingY(77)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	m_titleHandle = LoadGraph("data/image/title.png");
	m_buttonHandle = LoadGraph("data/image/button2.png");
	m_handleIdle = LoadGraph("data/image/Idle .png");
}

void TitleScene::End()
{
	DeleteGraph(m_titleHandle);
	DeleteGraph(m_buttonHandle);
	DeleteGraph(m_handleIdle);
}

SceneManager::SceneKind TitleScene::Update()
{
	m_animFrame++;
	int totalFrame = kIdleAnimNum * kSingleAnimFrame;
	if (m_animFrame >= totalFrame)
	{
		m_animFrame = 0;
	}

	if (!m_isJump)
	{
		m_velocity.y += kGravity;
	}

	if (!m_isJump)
	{
		m_isJump = true;
		m_velocity.y = kJumpPower;
	}

	if (m_isJump)
	{
		m_velocity.y += kJumpGravity;
	}

	if (m_pos.y > 315)
	{
		m_isJump = false;
	}

	m_pos += m_velocity;

	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		return SceneManager::SceneKind::kSceneMain;
	}
	return SceneManager::SceneKind::kTitleScene;
}

void TitleScene::Draw()
{
	int animNo = m_animFrame / kSingleAnimFrame;
	DrawGraph(-130, -20, m_titleHandle,true);
	DrawGraph(180, 380, m_buttonHandle, true);
	DrawRectGraph(m_pos.x, m_pos.y,
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		m_handleIdle, true, false);
	DrawRectGraph(m_pos.x + 458, m_pos.y,
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		m_handleIdle, true, true);
}
