#include "Camera.h"
#include "Player.h"

// �J�����͈̔�
// �J�������v���C���[��ǂ�������͈�
const float CameraScopeRangeW = 320.0f;
const float CameraScopeRangeH = 96.0f;
const float CameraScopeRangeTop = 200.0f;
const float CameraScopeRangeBottom = 240.0f;

// ���`�⊮��
const float CameraLerpRate = 0.15f;


void Camera::Init()
{
	
}

void Camera::Update(const Player* player)
{
	// �J�����̖ڕW�ʒu
	Vec2 aimCameraPos = m_pos;

	// �ڕW�ʒu�̌���
	// x���W�̌���
	if (player->GetPos().x > m_pos.x + (CameraScopeRangeW * 0.5f))
	{
		aimCameraPos.x = player->GetPos().x - (CameraScopeRangeW * 0.5f);
	}
	else if (player->GetPos().x < m_pos.x - (CameraScopeRangeW * 0.5f))
	{
		aimCameraPos.x = player->GetPos().x + (CameraScopeRangeW * 0.5f);
	}
	// y���W�̌���
	if (player->GetPos().y < m_pos.y - (CameraScopeRangeH * 0.5f)) // �J��������Ɉړ�����
	{
		aimCameraPos.y = player->GetPos().y + (CameraScopeRangeH * 0.5f);
	}
	else if (player->GetPos().y > m_pos.y + (CameraScopeRangeH * 0.5f)) // �J���������Ɉړ�����
	{
		//aimCameraPos.y = player->GetPos().y - (CameraScopeRangeH * 0.5f);
	}
	

	// �ڕW�|�W�V�����ɁALerp���g���ăJ�����|�W�V�������߂Â���
	m_pos = Lerp(m_pos, aimCameraPos, CameraLerpRate);

	// �X�e�[�W�̕����E�[�ɃJ�������ړ����Ȃ��悤�Ɍ�ŌŒ�
	if (m_pos.x > CameraScopeRangeW)
	{
		m_pos.x = CameraScopeRangeW;
	}
	// �X�e�[�W�̕���荶�[�ɃJ�������ړ����Ȃ��悤�Ɍ�ŌŒ�
	if (m_pos.x < 320)
	{
		m_pos.x = 320;
	}
	if (m_pos.y > CameraScopeRangeBottom)
	{
		m_pos.y = CameraScopeRangeBottom;
	}

	// Draw���ɑ����Ă���camera.pos.x/y�͔��]������
	m_drawOffset.x = m_pos.x * -1;
	m_drawOffset.y = m_pos.y * -1;

	// ���̎��A��ʂ̒����Ƀv���C���[������悤�ɂ���
	// (m_pos����ʂ̒����ɂȂ�悤�ɂ���)
	m_drawOffset.x = m_drawOffset.x + (Game::kScreenWidth * 0.5f);
	m_drawOffset.y = m_drawOffset.y + (Game::kScreenHeight * 0.5f);
}

Vec2 Camera::Lerp(Vec2 start, Vec2 end, float t)
{
	Vec2 ret;
	ret.x = std::lerp(start.x, end.x, t);
	ret.y = std::lerp(start.y, end.y, t);
	return ret;
}

