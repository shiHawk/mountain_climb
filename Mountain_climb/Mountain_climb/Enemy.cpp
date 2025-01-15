#include "Enemy.h"
#include "DxLib.h"
#include "game.h"

Enemy::Enemy():
	m_animFrameCount(0),
	m_handle(-1),
	m_speed(2.0f),
	m_pos(-40, 432)
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{

}

void Enemy::End()
{
}

void Enemy::Update()
{
	m_velocity.x = m_speed;
	m_pos += m_velocity;
}

void Enemy::Draw(Camera* camera)
{
	DrawBox(m_pos.x + static_cast<int>(camera->m_drawOffset.x),
		m_pos.y + static_cast<int>(camera->m_drawOffset.y),
		m_pos.x + 33 + static_cast<int>(camera->m_drawOffset.x),
		m_pos.y + 33 + static_cast<int>(camera->m_drawOffset.y),
		0xffffff, true);
	
	if (m_pos.x > Game::kScreenWidth)
	{
		m_pos.x = 0 - 40;
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
	return m_pos.x + 33;
}

float Enemy::GetBottom()
{
	return m_pos.y + 33;
}

void Enemy::Setting()
{
}
