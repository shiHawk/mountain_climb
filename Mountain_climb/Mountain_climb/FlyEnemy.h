#pragma once
#include "Enemy.h"
#include "Camera.h"
#include "Vec2.h"
class FlyEnemy 
{
public:
	FlyEnemy();
	~FlyEnemy();

	void Init();
	void End();
	void Update();
	void Draw(Camera* camera);

	float GetLeft();
	float GetTop();
	float GetRight();
	float GetBottom();

private:
	int m_handle;
	int m_animFrameCount;
	Vec2 m_pos;
	Vec2 m_velocity;
	float m_speed;
};

