#pragma once
#include "Vec2.h"
#include "Camera.h"
class Enemy
{
public:
	Enemy();
	~Enemy();

	void Init();
	void End();
	void Update();
	void Draw(Camera* camera);

	float GetLeft();
	float GetTop();
	float GetRight();
	float GetBottom();

	void Setting();
private:
	int m_handle;
	int m_animFrameCount;
	Vec2 m_pos;
	Vec2 m_velocity;
	float m_speed;
};

