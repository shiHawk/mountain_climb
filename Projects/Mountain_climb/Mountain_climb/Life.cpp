#include "Life.h"
#include "DxLib.h"

namespace
{
	// �O���t�B�b�N�̃T�C�Y
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 23;
	// �A�j���[�V�����̃R�}��
	constexpr int kAnimNum = 11;

	// �A�j���[�V����1�R�}�̃t���[����
	constexpr int kSingleAnimFrame = 4;
	// �\�����W�֘A
	constexpr int kBasePosX = 200;
	constexpr int kIntervalX = 120;

	constexpr int kPosY = 9;

	// �T�C�Y(�g�嗦)
	constexpr float kScale = 1.0;
}

Life::Life():
	m_handle(-1),
	m_animFrameCount(0),
	m_index(0)
{
}

Life::~Life()
{
}

void Life::Init()
{
	
}

void Life::End()
{
	DeleteGraph(m_handle);
}

void Life::Update()
{
	// �A�j���[�V�����̐i�s
	m_animFrameCount++;
	if (m_animFrameCount >= kAnimNum * kSingleAnimFrame)
	{
		m_animFrameCount = 0;
	}
}

void Life::Draw()
{
	// �O���t�B�b�N�̐؂�o���ʒu(X���W)���v�Z�ŋ��߂�
	int animNo = m_animFrameCount / kSingleAnimFrame;

	// index����\���ʒu�����肷��
	int posX = 20 + m_index * 50;

	DrawRectRotaGraph(posX, kPosY,	// ���S���W���w�肷��
		kGraphWidth * animNo, 0, kGraphWidth, kGraphHeight,	// �O���t�B�b�N�̐؂�o���ʒu
		kScale, 0.0,	// �g�嗦�A��]
		m_handle, true);
}

