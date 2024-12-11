#pragma once
#include "Vec2.h"
#include "Camera.h"
class Goal
{
public:
	Goal();
	~Goal();

	void Init();
	void End();
	void Update();
	void Draw(Camera* camera);

	float GetLeft();
	float GetTop();
	float GetRight();
	float GetBottom();
private:
	Vec2 m_pos;
	Vec2 m_velocity;
	float m_speed;
};

