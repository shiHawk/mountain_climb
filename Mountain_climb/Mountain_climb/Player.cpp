#include "Player.h"
#include "DxLib.h"
#include"Pad.h"
#include "game.h"
#include <cassert>

namespace
{
	// キャラクターグラフィックの幅と高さ
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;

	// アニメーションのコマ数
	constexpr int kIdleAnimNum = 11;
	constexpr int kRunAnimNum = 12;

	// アニメーション1コマのフレーム数
	constexpr int kSingleAnimFrame = 4;

	// キャラクターの移動速度
	constexpr float kSpeed = 2.0f;

	// 地面の高さ
	constexpr float kFieldHeight = 480.0f - 48.0f;

	// ジャンプ処理
	constexpr float kJumpPower = -9.3f;	// ジャンプの初速
	constexpr float kGravity = 0.4f;	// 重力

	// 左右の壁
	constexpr float kLeftWall = 64.0f;
	constexpr float kRightWall = 96.0f;
}

Player::Player() :
	m_handleIdle(-1),
	m_handleRun(-1),
	m_pos(320.0f,kFieldHeight),
	m_isDirLeft(false),
	m_animFrame(0),
	m_isRun(false),
	m_isJump(false),
	m_jumpSpeed(0.0f)
{
}

Player::~Player()
{
}

void Player::Init()
{
	m_handleIdle = LoadGraph("data/image/Idle .png");
	assert(m_handleIdle != -1);

	m_handleRun = LoadGraph("data/image/run.png");
}

void Player::End()
{
	// グラフィックを解放
	DeleteGraph(m_handleIdle);
	DeleteGraph(m_handleRun);
}

void Player::Update()
{
	m_animFrame++;
	// m_animFrame
	// 待機中は0~65 0~71
	// m_animFrame >= 66 の時に移動アニメから待機アニメに切り替わる

	int totalFrame = kIdleAnimNum * kSingleAnimFrame;
	if (m_isRun)
	{
		totalFrame = kRunAnimNum * kSingleAnimFrame;
	}
	if (m_animFrame >= kIdleAnimNum * kSingleAnimFrame)
	{
		m_animFrame = 0;
	}
	
	// 前回のアニメーションを覚えておく
	bool isLastRun = m_isRun;

	// 左右にキャラクターを動かす
	m_isRun = false;
	if (Pad::IsPress(KEY_INPUT_LEFT))
	{
		// 左キーを押しているときの処理
		m_pos.x -= kSpeed;
		m_isDirLeft = true;
		m_isRun = true;
	}
	if (Pad::IsPress(KEY_INPUT_RIGHT))
	{
		// 右キーを押しているときの処理
		m_pos.x += kSpeed;
		m_isDirLeft = false;
		m_isRun = true;
	}
	// 1ボタンでジャンプ
	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		if (!m_isJump)
		{
			m_isJump = true;
			m_jumpSpeed = kJumpPower;
		}
	}

	// 左の壁に当たる
	if (m_pos.x <= kLeftWall)
	{
		m_pos.x = kLeftWall;
	}

	// 右の壁に当たる
	if (m_pos.x >= Game::kScreenWidth - kRightWall)
	{
		m_pos.x = Game::kScreenWidth - kRightWall;
	}

	if (m_isJump)
	{
		m_pos.y += m_jumpSpeed;
		m_jumpSpeed += kGravity;
		if (m_jumpSpeed > 0)
		{
			if (m_pos.y >= kFieldHeight)
			{
				// ジャンプ終了
				m_isJump = false;
				m_jumpSpeed = 0.0f;

				// 地面にめり込まないようにする
				m_pos.y = kFieldHeight;
			}
		}
	}
}

void Player::Draw()
{
	int animNo = m_animFrame / kSingleAnimFrame;

	int useHandle = m_handleIdle;
	if (m_isRun)
	{
		useHandle = m_handleRun;
	}

	DrawRectGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y ),
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		useHandle, true, m_isDirLeft);
}

float Player::GetLeft() const
{
	return (m_pos.x - kGraphWidth / 2);
}

float Player::GetTop() const
{
	return (m_pos.y - kGraphHeight);
}

float Player::GetRight() const
{
	return (m_pos.x + kGraphWidth / 2);
}

float Player::GetBottom() const
{
	return m_pos.y;
}
