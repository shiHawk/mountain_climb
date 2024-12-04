#pragma once
#include "Vec2.h"
#include "DxLib.h"
#include "game.h"
#include <cmath>

class Player;

class Camera
{
public:

	void Init();
	void Update(const Player* player);
	// staticメンバ変数
	// 線形補間
	static Vec2 Lerp(Vec2 start,Vec2 end,float t);
	Vec2 m_pos;// カメラの位置
	Vec2 m_drawOffset; // プレイヤーを画面の中央に捉えるためにDrawに足す値
private:
	
	
};

