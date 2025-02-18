#include "EnemyData.h"
#include "Enemy.h"

void EnemyData::Init()
{
	enemyStartPos[0] = { 640, 332 };
	enemyStartPos[1] = { -100, 232 };
	enemyStartPos[2] = { 700, 132 };
	enemyStartPos[3] = { -150, 32 };
	enemyStartPos[4] = { 720, -68 };
	enemyStartPos[5] = { -200, -168 };
	enemyStartPos[6] = { 850, -268 };

	m_enemySpped[0] = 0.75f;
	m_enemySpped[1] = 2.5f;
	m_enemySpped[2] = 1.5f;
	m_enemySpped[3] = 1.75f;
	m_enemySpped[4] = 2.0f;
	m_enemySpped[5] = 1.0f;
	m_enemySpped[6] = 3.0f;

	for (int i = 0; i < kEnemyNum; i++)
	{
		m_enemy[i].Init(enemyStartPos[i],m_enemySpped[i]);
	}
}

void EnemyData::End()
{
}

void EnemyData::Update()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		m_enemy[i].Update();
	}
}

void EnemyData::Draw(Camera* camera)
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		m_enemy[i].Draw(camera);
	}
}

Enemy EnemyData::GetEnemyDate(int enemyNum)
{
	if (enemyNum >= kEnemyNum || enemyNum < 0)
	{
		return m_enemy[0];
	}
	return m_enemy[enemyNum];
}
