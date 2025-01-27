#pragma once
#include "Vec2.h"
#include "Camera.h"
#include "Enemy.h"

namespace
{
	// “G‚Ì”
	constexpr int kEnemyNum = 7;
}
class EnemyDate
{
public:
	void Init();
	void End();
	void Update();
	void Draw(Camera* camera);
	Enemy GetEnemyDate(int enemyNum);
private:
	Vec2 enemyStartPos[kEnemyNum];
	Enemy m_enemy[kEnemyNum];
	Camera m_camera;
};

