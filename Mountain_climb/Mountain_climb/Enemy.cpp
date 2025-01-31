#include "Enemy.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	constexpr int kGraphWidth = 46;
	constexpr int kGraphHeight = 30;
	constexpr int kAnimNum = 7;
	constexpr int kSingleAnimFrame = 4;
	int kTemp;
}

Enemy::Enemy():
	m_animFrameCount(0),
	m_handle(-1),
	m_speed(2.0f),
	m_isRightDir(true),
	m_adjustment(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Init(Vec2 pos, float speed)
{
	kTemp = GetRand(1);
	m_pos = pos;
	m_StartPos = pos;
	m_speed = speed;
	m_handle = LoadGraph("data/image/enemy.png");
}

void Enemy::End()
{
	DeleteGraph(m_handle);
}

void Enemy::Update()
{
	m_animFrameCount++;
	int totalFrame = kAnimNum * kSingleAnimFrame;
	if (m_animFrameCount >= totalFrame)
	{
		m_animFrameCount = 0;
	}
	m_velocity.x = m_speed;
	if (m_isRightDir)
	{
		m_pos += m_velocity;
	}
	else
	{
		m_pos -= m_velocity;
	}
}

void Enemy::Draw(Camera* camera)
{
	int animNo = m_animFrameCount / kSingleAnimFrame;

	DrawRectGraph(m_pos.x + static_cast<int>(camera->m_drawOffset.x),
		m_pos.y + static_cast<int>(camera->m_drawOffset.y),
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		m_handle, true, m_isRightDir);

	if (m_isRightDir && m_pos.x > Game::kScreenWidth)
	{
		m_pos = m_StartPos;
		m_isRightDir = false;
	}
	if (!m_isRightDir && m_pos.x < -40)
	{
		//m_pos.x = 0 - 40;
		m_pos.x = -40;
		m_isRightDir = true;
	}
}

float Enemy::GetLeft()
{
	return m_pos.x;
}

float Enemy::GetTop()
{
	return m_pos.y;
}

float Enemy::GetRight()
{
	return m_pos.x + kGraphWidth;
}

float Enemy::GetBottom()
{
	return m_pos.y + kGraphHeight;
}

