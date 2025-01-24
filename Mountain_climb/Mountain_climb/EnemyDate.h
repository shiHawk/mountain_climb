#pragma once
#include "Vec2.h"
#include "Camera.h"
class Enemy;
namespace
{
	constexpr int enemyNum = 7;
}
class EnemyDate
{
public:
	void Init();
	void End();
	void Update();
	void Draw(Camera* camera);
private:
	float enemyStartPos[enemyNum];
	Enemy m_enemy[enemyNum];
	Camera m_camera;
};

