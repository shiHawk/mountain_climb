#include "Goal.h"
#include "DxLib.h"

namespace
{
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;
	constexpr int kAnimNum = 9;
	constexpr int kSingleAnimFrame = 4;
}

Goal::Goal():
	m_speed(3.0f),
	m_pos(0,-1100),
	m_handle(-1),
	m_animFrame(0)
{
}

Goal::~Goal()
{
}

void Goal::Init()
{
	m_handle = LoadGraph("data/image/goal.png");
}

void Goal::End()
{
	DeleteGraph(m_handle);
}

void Goal::Update()
{
	m_animFrame++;
	int totalFrame = kAnimNum * kSingleAnimFrame;
	if (m_animFrame >= totalFrame)
	{
		m_animFrame = 0;
	}
	m_velocity.x = m_speed;
	m_pos += m_velocity;
}

void Goal::Draw(Camera* camera)
{
	int animNo = m_animFrame / kSingleAnimFrame;
	DrawRectGraph(m_pos.x + static_cast<int>(camera->m_drawOffset.x), 
		m_pos.y + static_cast<int>(camera->m_drawOffset.y),
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		m_handle, true, true);
	if (m_pos.x > Game::kScreenWidth)
	{
		m_pos.x = 0 - kGraphWidth;
	}
}

float Goal::GetLeft()
{
	return m_pos.x;
}

float Goal::GetTop()
{
	return m_pos.y;
}

float Goal::GetRight()
{
	return m_pos.x + kGraphWidth;
}

float Goal::GetBottom()
{
	return m_pos.y + kGraphWidth;
}
