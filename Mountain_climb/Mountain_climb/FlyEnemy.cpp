#include "FlyEnemy.h"

FlyEnemy::FlyEnemy() :
	m_animFrameCount(0),
	m_handle(-1),
	m_speed(2.0f),
	m_pos(100, 200)
{
}

FlyEnemy::~FlyEnemy()
{
}

void FlyEnemy::Init()
{
}

void FlyEnemy::End()
{
}

void FlyEnemy::Update()
{
}

void FlyEnemy::Draw(Camera* camera)
{
}

float FlyEnemy::GetLeft()
{
	return 0.0f;
}

float FlyEnemy::GetTop()
{
	return 0.0f;
}

float FlyEnemy::GetRight()
{
	return 0.0f;
}

float FlyEnemy::GetBottom()
{
	return 0.0f;
}
