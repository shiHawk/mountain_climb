#include "TitleScene.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	// �L�����N�^�[�O���t�B�b�N�̕��ƍ���
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;

	// �A�j���[�V�����̃R�}��
	constexpr int kIdleAnimNum = 11;
	// �A�j���[�V����1�R�}�̃t���[����
	constexpr int kSingleAnimFrame = 2;
	// �W�����v����
	constexpr float kJumpPower = -7.6f;	// �W�����v�̏���
	// �d��
	float kJumpGravity = 0.2f;
	float kGravity = 0.3f;
	// �����̌��E
	constexpr int kJumpLimit = 315;

	// �^�C�g���ƃ{�^���̈ʒu
	constexpr int kTitlePosX = -130;
	constexpr int kTitlePosY = -20;
	constexpr int kButtonPosX = 180;
	constexpr int kButtonPosY = 380;

	// 2�̖ڂ̃L�����̈ʒu
	constexpr int KAnotherOnePos = 458;

	constexpr int kFadeOutFrame = 255;
	constexpr int kGameoverFadeFrame = 60;

	bool isFadeStart = false;
}

TitleScene::TitleScene():
	m_titleHandle(-1),
	m_buttonHandle(-1),
	m_blinkCount(0),
	m_handleIdle(-1),
	m_animFrame(0),
	m_isJump(false),
	m_jumpSpeed(0),
	m_pos(80,330),
	m_scalingX(281),
	m_scalingY(77),
	m_gameoverFrameCount(0)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	m_titleHandle = LoadGraph("data/image/title.png");
	m_buttonHandle = LoadGraph("data/image/button2.png");
	m_handleIdle = LoadGraph("data/image/Idle .png");
	isFadeStart = false;
}

void TitleScene::End()
{
	DeleteGraph(m_titleHandle);
	DeleteGraph(m_buttonHandle);
	DeleteGraph(m_handleIdle);
}

SceneManager::SceneKind TitleScene::Update()
{
	m_animFrame++;
	int totalFrame = kIdleAnimNum * kSingleAnimFrame;
	if (m_animFrame >= totalFrame)
	{
		m_animFrame = 0;
	}

	if (!m_isJump)
	{
		m_velocity.y += kGravity;
	}

	if (!m_isJump)
	{
		m_isJump = true;
		m_velocity.y = kJumpPower;
	}

	if (m_isJump)
	{
		m_velocity.y += kJumpGravity;
	}

	if (m_pos.y > kJumpLimit)
	{
		m_isJump = false;
	}

	m_pos += m_velocity;
	if (isFadeStart)
	{
		m_gameoverFrameCount += 2;
	}

	if (Pad::IsTrigger(PAD_INPUT_1) || isFadeStart)
	{
		isFadeStart = true;
		if (m_gameoverFrameCount > kFadeOutFrame)
		{
			m_gameoverFrameCount = kGameoverFadeFrame;
			return SceneManager::SceneKind::kSceneMain;
		}
	}
	return SceneManager::SceneKind::kTitleScene;
}

void TitleScene::Draw()
{
	int animNo = m_animFrame / kSingleAnimFrame;
	DrawGraph(kTitlePosX, kTitlePosY, m_titleHandle,true);
	DrawGraph(kButtonPosX, kButtonPosY, m_buttonHandle, true);
	DrawRectGraph(m_pos.x, m_pos.y,
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		m_handleIdle, true, false);
	DrawRectGraph(m_pos.x + KAnotherOnePos, m_pos.y,
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		m_handleIdle, true, true);

	// �t�F�[�h����
	int fadeAlpha = m_gameoverFrameCount;
	// m_fadeFrameaCount = 0�̎�fadeAlpha = 255 �^����

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeAlpha);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
