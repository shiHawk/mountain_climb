#include "Enemy.h"
#include "DxLib.h"
#include "game.h"

Enemy::Enemy():
	m_animFrameCount(0),
	m_handle(-1),
	m_speed(0.5f)
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
	m_velocity.x += m_speed;

	m_pos += m_velocity;
}

void Enemy::Draw()
{
	DrawBox(100, 432, 133, 465, 0xffffff, true);
}

float Enemy::GetLeft()
{
	return 0.0f;
}

float Enemy::GetTop()
{
	return 0.0f;
}

float Enemy::GetRight()
{
	return 0.0f;
}

float Enemy::GetBottom()
{
	return 0.0f;
}

void Enemy::Setting()
{
}
