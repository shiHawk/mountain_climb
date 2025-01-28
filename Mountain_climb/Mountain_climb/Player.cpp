#include "Player.h"
#include "DxLib.h"
#include"Pad.h"
#include "game.h"
#include <cassert>
#include "Camera.h"

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
	constexpr float kSpeed = 0.5f;
	// 無敵時間
	constexpr int kInvincible = 60;
	// 最大残機
	constexpr int kMaxHp = 3;

	// 地面の高さ
	constexpr float kFieldHeight = 480.0f - 48.0f;

	// 最高速度
	constexpr float kMaxSpeed = 2.6f;

	// ジャンプ処理
	constexpr float kJumpPower = -9.6f;	// ジャンプの初速
	// 重力
	float kJumpGravity = 0.4f;	
	float kGravity = 0.5f;
	// 落下判定
	bool FallFrag = false;

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
	m_invincibleCount(0),
	m_hp(kMaxHp),
	m_isJump(false),
	m_jumpSpeed(0.0f)
{
}

Player::~Player()
{
}

void Player::Init(Camera* camera)
{
	m_handleIdle = LoadGraph("data/image/Idle .png");
	assert(m_handleIdle != -1);

	m_handleRun = LoadGraph("data/image/run.png");
	m_camera = camera;
	m_camera->m_pos.SetPos(m_pos.x, m_pos.y);
}

void Player::End()
{
	// グラフィックを解放
	DeleteGraph(m_handleIdle);
	DeleteGraph(m_handleRun);
}

void Player::OnDamage()
{
	// 既にダメージを受けている(無敵時間)間は
	// 再度ダメージを受けることはない
	if (m_invincibleCount > 0)
	{
		return;
	}
	// 無敵時間(点滅する時間)を設定する
	m_invincibleCount = kInvincible;
	// ダメージを受ける
	m_hp--;
	printfDx("Damage ");
}

void Player::InstanceDeath()
{
	m_hp = 0;
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

	// 無敵時間の更新
	m_invincibleCount--;
	if (m_invincibleCount < 0)
	{
		m_invincibleCount = 0;
	}
	
	// 左右にキャラクターを動かす
	m_isRun = false;
	if (Pad::IsPress(KEY_INPUT_LEFT))
	{
		// 左キーを押しているときの処理
		m_velocity.x -= kSpeed;
		m_isDirLeft = true;
		m_isRun = true;
	}
	else if (Pad::IsPress(KEY_INPUT_RIGHT))
	{
		// 右キーを押しているときの処理
		m_velocity.x += kSpeed;
		m_isDirLeft = false;
		m_isRun = true;
	}

	if (!m_isRun)
	{
		m_velocity.x = 0.0f;
	}

	if (!m_isJump)
	{
		m_velocity.y += kGravity;
	}

	if (m_velocity.y > 0)
	{
		FallFrag = true;
	}
	else
	{
		FallFrag = false;
	}

	// velocityがkMaxSpeedになったら加速を止める
	if (m_velocity.x >= kMaxSpeed)
	{
		m_velocity.x = kMaxSpeed;
	}
	if (m_velocity.x <= -kMaxSpeed)
	{
		m_velocity.x = -kMaxSpeed;
	}

	// Aボタンでジャンプ
	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		if (!m_isJump)
		{
			m_isJump = true;
			m_velocity.y = kJumpPower;
		}
	}

	// 左の壁に当たる
	if (m_pos.x <= kLeftWall)
	{
		m_pos.x = kLeftWall + 0.1f;
		m_velocity.x = 0.0f;
	}

	// 右の壁に当たる
	if (m_pos.x >= Game::kScreenWidth - kRightWall)
	{
		m_pos.x = Game::kScreenWidth - kRightWall - 0.1f;
		m_velocity.x = 0.0f;
	}

	if (m_isJump)
	{
		m_velocity.y += kJumpGravity;
	}

	m_pos += m_velocity;
	//printfDx("player.pos:(%d,%d)\n",(int)m_pos.x, (int)m_pos.y+48);
}

void Player::Draw()
{
	if ((m_invincibleCount / 2) % 2)
	{
		return;
	}
	int animNo = m_animFrame / kSingleAnimFrame;

	int useHandle = m_handleIdle;
	if (m_isRun)
	{
		useHandle = m_handleRun;
	}
	//描画位置の決定
	int tempX = static_cast<int>(m_pos.x) + static_cast<int>(m_camera->m_drawOffset.x);
	int tempY = static_cast<int>(m_pos.y) + static_cast<int>(m_camera->m_drawOffset.y);
	DrawRectGraph(tempX , tempY,
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		useHandle, true, m_isDirLeft);
	//printfDx("player.pos:(%d,%d)\n", tempX, tempY);
}

float Player::GetLeft() const
{
	return (m_pos.x + kGraphWidth * 0.5f);
}

float Player::GetTop() const
{
	return m_pos.y;
}

float Player::GetRight() const
{
	return (m_pos.x + kGraphWidth);
}

float Player::GetBottom() const
{
	return (m_pos.y + kGraphHeight);
}

void Player::AddMove(Vec2 move)
{
	m_pos += move;
}

void Player::AddMoveY(float DisY)
{
	m_pos.y += DisY;
}

void Player::AddMoveLeft(float left)
{
	m_pos.x -= left;
}

void Player::AddMoveRight(float right)
{
	m_pos.x += right;
}


void Player::SetVelocity(Vec2 velocity)
{
	m_velocity = velocity;
}

void Player::OnCollideY()
{
	m_velocity.y = 0;
}

void Player::OnCollideX()
{
	m_velocity.x = 0;
}

void Player::Landing(float DisY)
{
	m_isJump = false;
	m_pos.y -= DisY;
}

Vec2 Player::GetPos() const
{
	return m_pos;
}

float Player::PlayerAirPos()
{
	return m_pos.y -= 2.0f;
}

bool Player::FallFlag()
{
	return FallFrag;
}

bool Player::IsDir()
{
	if (m_isDirLeft)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Player::GetPlayerHp()
{
	return m_hp;
}

