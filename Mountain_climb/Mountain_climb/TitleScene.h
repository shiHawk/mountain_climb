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
	// �O���t�B�b�N�n���h��
	int m_characterHandle;
	int m_titleHandle;
	int m_buttonHandle;

	// �A�j���[�V�����֘A
	int m_animFrame;	// �t���[�����𐔂���
	int m_blinkCount;

	// �W�����v����
	bool  m_isJump;
	float m_jumpSpeed;

	Vec2 m_velocity;
	Vec2 m_pos;

	int m_fadeFrameCount;

	// BGM�֘A
	int m_bgmHandle;
	int m_valume;
};

