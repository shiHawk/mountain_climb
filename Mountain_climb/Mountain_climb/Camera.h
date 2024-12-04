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
	// static�����o�ϐ�
	// ���`���
	static Vec2 Lerp(Vec2 start,Vec2 end,float t);
	Vec2 m_pos;// �J�����̈ʒu
	Vec2 m_drawOffset; // �v���C���[����ʂ̒����ɑ����邽�߂�Draw�ɑ����l
private:
	
	
};

