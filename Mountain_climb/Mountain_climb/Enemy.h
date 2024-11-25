#pragma once
#include "Vec2.h"
class Enemy
{
public:
	Enemy();
	~Enemy();

	void Init();
	void End();
	void Update();
	void Draw();

	float GetLeft();
	float GetTop();
	float GetRight();
	float GetBottom();

	void Setting();
private:
	int m_handle;
	int m_animFrameCount;
	Vec2 m_pos;
	float m_speed;
};

