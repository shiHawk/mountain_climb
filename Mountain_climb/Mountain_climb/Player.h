#pragma once
#include "Vec2.h"

class Player
{
public:
	Player();
	~Player();

	void Init();	// ������
	void End();	// �I��
	void Update();	// �X�V
	void Draw();	// �`��

	// �v���C���[�̏����擾����
	float GetLeft() const;
	float GetTop() const;
	float GetRight() const;
	float GetBottom() const;
	float PlayerAirPos();
	bool FallFlag();
	void AddMove(Vec2 move);
	void AddMoveY(float DisY);
	void AddMoveLeft(float left);
	void AddMoveRight(float right);
	void SetVelocity(Vec2 velocity);
	void OnCollideY();
	void OnCollideX();
	void Landing(float DisY);
	
	
private:
	// �O���t�B�b�N�n���h��
	int m_handleIdle;
	int m_handleRun;

	// �A�j���[�V�����֘A
	int m_animFrame;	// �t���[�����𐔂���
	// ���ݍĐ����̃A�j���[�V����
	// true:�����Ă���@false:�ҋ@
	bool m_isRun;

	Vec2 m_pos;
	Vec2 m_velocity;
	bool m_isDirLeft;

	// �W�����v����
	bool m_isJump;
	float m_jumpSpeed;

};

