#pragma once
#include "Vec2.h"
#include "Camera.h"
#include "Enemy.h"

namespace
{
	// �G�̐�
	constexpr int kEnemyNum = 7;
}
class EnemyData
{
public:
	void Init();
	void End();
	void Update();
	void Draw(Camera* camera);
	Enemy GetEnemyDate(int enemyNum);
private:
	float m_enemySpped[kEnemyNum];
	Vec2 enemyStartPos[kEnemyNum];
	Enemy m_enemy[kEnemyNum];
	Camera m_camera;
};

