#include "EnemyDate.h"
#include "Enemy.h"

void EnemyDate::Init()
{
	enemyStartPos[0] = { -40, 432 };
	enemyStartPos[1] = { -140, 332 };
	enemyStartPos[2] = { -240, 232 };
	enemyStartPos[3] = { -340, 132 };
	enemyStartPos[4] = { -440, 32 };
	enemyStartPos[5] = { -540, -68 };
	enemyStartPos[6] = { -640, -168 };

	for (int i = 0; i < kEnemyNum; i++)
	{
		m_enemy[i].Init(enemyStartPos[i]);
	}
}

void EnemyDate::End()
{
}

void EnemyDate::Update()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		m_enemy[i].Update();
	}
}

void EnemyDate::Draw(Camera* camera)
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		m_enemy[i].Draw(camera);
	}
}

Enemy EnemyDate::GetEnemyDate(int enemyNum)
{
	if (enemyNum >= kEnemyNum || enemyNum < 0)
	{
		return m_enemy[0];
	}
	return m_enemy[enemyNum];
}
