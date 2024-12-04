#pragma once

// 2次元ベクトルクラス
class Vec2
{
public:
	float x;
	float y;
	void operator+=(Vec2 vec) { x += vec.x; y += vec.y; }

public:
	Vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}
	Vec2(float _x, float _y) :
		x(_x),
		y(_y)
	{

	}
	void SetPos(float a,float b)
	{
		x = a;
		y = b;
	}
};