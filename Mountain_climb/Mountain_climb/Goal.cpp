#include "Goal.h"
#include "DxLib.h"

Goal::Goal():
	m_speed(3.0f),
	m_pos(0,-1100)
{
}

Goal::~Goal()
{
}

void Goal::Init()
{
}

void Goal::End()
{
}

void Goal::Update()
{
	m_velocity.x = m_speed;
	m_pos += m_velocity;
}

void Goal::Draw(Camera* camera)
{
	DrawBox(m_pos.x + static_cast<int>(camera->m_drawOffset.x),
		m_pos.y + static_cast<int>(camera->m_drawOffset.y),
		m_pos.x + 30 + static_cast<int>(camera->m_drawOffset.x),
		m_pos.y + 30 + static_cast<int>(camera->m_drawOffset.y), 0x000000, true);
	if (m_pos.x > Game::kScreenWidth)
	{
		m_pos.x = 0 - 30;
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
	return m_pos.x + 30;
}

float Goal::GetBottom()
{
	return m_pos.y + 30;
}
