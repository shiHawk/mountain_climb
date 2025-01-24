#include "EnemyDate.h"
#include "Enemy.h"

void EnemyDate::Init()
{
}

void EnemyDate::End()
{
}

void EnemyDate::Update()
{
	for (int i = 0; i < enemyNum; i++)
	{
		m_enemy[i].Update();
	}
}

void EnemyDate::Draw(Camera* camera)
{
	for (int i = 0; i < enemyNum; i++)
	{
		m_enemy[i].Draw(&camera);
	}
}
