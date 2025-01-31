#pragma once
#include "SceneManager.h"
class TitleScene
{
public:
	TitleScene();
	~TitleScene();
	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
private:
	int m_titleHandle;
	int m_buttonHandle;
	int m_blinkCount;
	// �O���t�B�b�N�n���h��
	int m_handleIdle;
	// �A�j���[�V�����֘A
	int m_animFrame;	// �t���[�����𐔂���
	// �W�����v����
	bool m_isJump;
	float m_jumpSpeed;
	Vec2 m_velocity;
	Vec2 m_pos;
	int m_scalingX;
	int m_scalingY;
};

