#include "Player.h"
#include "DxLib.h"
#include"Pad.h"
#include "game.h"
#include <cassert>

namespace
{
	// �L�����N�^�[�O���t�B�b�N�̕��ƍ���
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;

	// �A�j���[�V�����̃R�}��
	constexpr int kIdleAnimNum = 11;
	constexpr int kRunAnimNum = 12;

	// �A�j���[�V����1�R�}�̃t���[����
	constexpr int kSingleAnimFrame = 4;

	// �L�����N�^�[�̈ړ����x
	constexpr float kSpeed = 2.0f;

	// �n�ʂ̍���
	constexpr float kFieldHeight = 480.0f - 48.0f;

	// �W�����v����
	constexpr float kJumpPower = -9.3f;	// �W�����v�̏���
	constexpr float kGravity = 0.4f;	// �d��

	// ���E�̕�
	constexpr float kLeftWall = 64.0f;
	constexpr float kRightWall = 96.0f;
}

Player::Player() :
	m_handleIdle(-1),
	m_handleRun(-1),
	m_pos(320.0f,kFieldHeight),
	m_isDirLeft(false),
	m_animFrame(0),
	m_isRun(false),
	m_isJump(false),
	m_jumpSpeed(0.0f)
{
}

Player::~Player()
{
}

void Player::Init()
{
	m_handleIdle = LoadGraph("data/image/Idle .png");
	assert(m_handleIdle != -1);

	m_handleRun = LoadGraph("data/image/run.png");
}

void Player::End()
{
	// �O���t�B�b�N�����
	DeleteGraph(m_handleIdle);
	DeleteGraph(m_handleRun);
}

void Player::Update()
{
	m_animFrame++;
	// m_animFrame
	// �ҋ@����0~65 0~71
	// m_animFrame >= 66 �̎��Ɉړ��A�j������ҋ@�A�j���ɐ؂�ւ��

	int totalFrame = kIdleAnimNum * kSingleAnimFrame;
	if (m_isRun)
	{
		totalFrame = kRunAnimNum * kSingleAnimFrame;
	}
	if (m_animFrame >= kIdleAnimNum * kSingleAnimFrame)
	{
		m_animFrame = 0;
	}
	
	// �O��̃A�j���[�V�������o���Ă���
	bool isLastRun = m_isRun;

	// ���E�ɃL�����N�^�[�𓮂���
	m_isRun = false;
	if (Pad::IsPress(KEY_INPUT_LEFT))
	{
		// ���L�[�������Ă���Ƃ��̏���
		m_pos.x -= kSpeed;
		m_isDirLeft = true;
		m_isRun = true;
	}
	if (Pad::IsPress(KEY_INPUT_RIGHT))
	{
		// �E�L�[�������Ă���Ƃ��̏���
		m_pos.x += kSpeed;
		m_isDirLeft = false;
		m_isRun = true;
	}
	// 1�{�^���ŃW�����v
	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		if (!m_isJump)
		{
			m_isJump = true;
			m_jumpSpeed = kJumpPower;
		}
	}

	// ���̕ǂɓ�����
	if (m_pos.x <= kLeftWall)
	{
		m_pos.x = kLeftWall;
	}

	// �E�̕ǂɓ�����
	if (m_pos.x >= Game::kScreenWidth - kRightWall)
	{
		m_pos.x = Game::kScreenWidth - kRightWall;
	}

	if (m_isJump)
	{
		m_pos.y += m_jumpSpeed;
		m_jumpSpeed += kGravity;
		if (m_jumpSpeed > 0)
		{
			if (m_pos.y >= kFieldHeight)
			{
				// �W�����v�I��
				m_isJump = false;
				m_jumpSpeed = 0.0f;

				// �n�ʂɂ߂荞�܂Ȃ��悤�ɂ���
				m_pos.y = kFieldHeight;
			}
		}
	}
}

void Player::Draw()
{
	int animNo = m_animFrame / kSingleAnimFrame;

	int useHandle = m_handleIdle;
	if (m_isRun)
	{
		useHandle = m_handleRun;
	}

	DrawRectGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y ),
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		useHandle, true, m_isDirLeft);
}

float Player::GetLeft() const
{
	return (m_pos.x - kGraphWidth / 2);
}

float Player::GetTop() const
{
	return (m_pos.y - kGraphHeight);
}

float Player::GetRight() const
{
	return (m_pos.x + kGraphWidth / 2);
}

float Player::GetBottom() const
{
	return m_pos.y;
}
