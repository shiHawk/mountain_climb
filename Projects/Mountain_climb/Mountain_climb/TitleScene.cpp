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
	constexpr int kAnotherOnePos = 458;

	// �t�F�[�h�֘A
	constexpr int kFadeOutFrame = 255;
	constexpr int kFadeFrame = 60;
	// �t�F�[�h���n�܂��Ă��邩
	bool isFadeStart = false;

	// �_�ŃT�C�N��
	constexpr int kBlinkFrame = 40;
	constexpr int kBlinkCycle = 60;

	// �ő剹��
	int maxVolume = 255;

	// ����
	constexpr int kIncremental = 3;
}

TitleScene::TitleScene():
	m_titleHandle(-1),
	m_buttonHandle(-1),
	m_blinkCount(0),
	m_characterHandle(-1),
	m_animFrame(0),
	m_isJump(false),
	m_jumpSpeed(0),
	m_pos(80,330),
	m_fadeFrameCount(0),
	m_bgmHandle(0),
	m_valume(0)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	m_titleHandle = LoadGraph("data/image/title.png");
	m_buttonHandle = LoadGraph("data/image/button2.png");
	m_characterHandle = LoadGraph("data/image/Idle .png");
	m_bgmHandle = LoadSoundMem("data/image/titlebgm.mp3");
	ChangeVolumeSoundMem(maxVolume - m_valume, m_bgmHandle);
	PlaySoundMem(m_bgmHandle, DX_PLAYTYPE_LOOP);
	isFadeStart = false;
}

void TitleScene::End()
{
	DeleteGraph(m_titleHandle);
	DeleteGraph(m_buttonHandle);
	DeleteGraph(m_characterHandle);
	DeleteSoundMem(m_bgmHandle);
}

SceneManager::SceneKind TitleScene::Update()
{
	ChangeVolumeSoundMem(maxVolume - m_valume, m_bgmHandle);
	m_blinkCount++;
	if (m_blinkCount > kBlinkCycle)
	{
		m_blinkCount = 0;
	}
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
		m_valume += kIncremental;
		m_fadeFrameCount += kIncremental;
		
	}

	if (Pad::IsTrigger(PAD_INPUT_1) || isFadeStart)
	{
		isFadeStart = true;
		m_blinkCount = 1;

		if (m_fadeFrameCount > kFadeOutFrame && m_valume > kFadeOutFrame)
		{
			m_fadeFrameCount = kFadeFrame;
			return SceneManager::SceneKind::kSceneMain;
		}
	}
	return SceneManager::SceneKind::kTitleScene;
}

void TitleScene::Draw()
{
	int animNo = m_animFrame / kSingleAnimFrame;
	DrawGraph(kTitlePosX, kTitlePosY, m_titleHandle,true);
	if (m_blinkCount < kBlinkFrame)
	{
		DrawGraph(kButtonPosX, kButtonPosY, m_buttonHandle, true);
	}
	DrawRectGraph(m_pos.x, m_pos.y,
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		m_characterHandle, true, false);
	DrawRectGraph(m_pos.x + kAnotherOnePos, m_pos.y,
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		m_characterHandle, true, true);

	// �t�F�[�h����
	int fadeAlpha = m_fadeFrameCount;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeAlpha);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
