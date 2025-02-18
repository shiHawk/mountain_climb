#include "ResultScene.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	// シーン番号
	int changeScene = 1;
	int stageNumber = 1;
	bool returnTitle = false;

	// 背景の位置
	int bgX = 0;
	int bgY = 0;
	// 背景の幅
	constexpr int kBgWidth = 1000;
	constexpr int kBgHeight = 1000;
	// 背景のスクロール速度
	int scrollSpeed = 1;

	// 持ち点
	constexpr int kPoints = 4000;
	// ランクの基準
	constexpr int kARankCriteria = 2000;
	constexpr int kBRankCriteria = 1500;

	// 表示するテキストの位置
	constexpr int kTextPosX = 80;
	constexpr int kTextPosY = 448;
	constexpr int kRankPosX = 300;
	constexpr int kRankPosY = 400;
	constexpr int kClearPosX = 20;
	constexpr int kClearPosY = 70;
	constexpr int kStageTextPosX = 250;
	constexpr int kStageTextPosY = 20;
	constexpr int kBlockTextPosY = 200;
	constexpr int kTimeTextPosY = 100;
	constexpr int kScoreTextPosY = 300;
	constexpr int kBlockTextStage3PosY = 160;
	constexpr int kTimeTextStage3PosY = 250;
	constexpr int kScoreTextStage3PosY = 340;

	bool isFadeStart = false;
	bool isFadeStart2 = false;
	constexpr int kFadeOutFrame = 255;
	constexpr int kFadeFrame = 60;

	// 点滅用
	constexpr int kBlinkFrame = 40;
	constexpr int kBlinkCycle = 60;

	// 増分
	constexpr int kIncremental = 5;
}

ResultScene::ResultScene():
	m_score(0),
	m_fontHandle(0),
	m_fontScoreHandle(0),
	m_bgHandle(0),
	m_rank(0),
	m_fontRankHandle(0),
	m_clearHandle(0),
	m_FadeFrameCount(0),
	m_blinkCount(0),
	m_bgmHandle(0),
	m_valume(0)
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Init()
{
	m_fontHandle = CreateFontToHandle("Elephant", 32, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	m_fontScoreHandle = CreateFontToHandle("Elephant", 48, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	m_fontRankHandle = CreateFontToHandle("Bodoni MT Black", 48, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	m_bgHandle = LoadGraph("data/image/bg.png");
	m_clearHandle = LoadGraph("data/image/gameclear.png");
	m_bgmHandle = LoadSoundMem("data/image/resultbgm.mp3");
	PlaySoundMem(m_bgmHandle, DX_PLAYTYPE_LOOP);
	bgX = 0;
	bgY = 0;
	isFadeStart = false;
	isFadeStart2 = false;
}

void ResultScene::End()
{
	DeleteFontToHandle(m_fontHandle);
	DeleteFontToHandle(m_fontScoreHandle);
	DeleteFontToHandle(m_fontRankHandle);
	DeleteGraph(m_bgHandle);
	DeleteGraph(m_clearHandle);
	DeleteSoundMem(m_bgmHandle);
}

SceneManager::SceneKind ResultScene::Update(Stage* stage)
{
	bgX -= scrollSpeed;
	m_blinkCount++;
	if (m_blinkCount > kBlinkCycle)
	{
		m_blinkCount = 0;
	}

	if (isFadeStart)
	{
		m_FadeFrameCount += kIncremental;
	}

	if (isFadeStart2)
	{
		m_FadeFrameCount += kIncremental;
	}

	if (Pad::IsTrigger(PAD_INPUT_2) || isFadeStart2)
	{
		isFadeStart2 = true;
		m_blinkCount = 1;
		if (m_FadeFrameCount > kFadeOutFrame)
		{
			stageNumber = 1;
			stage->ResetStage();
			m_FadeFrameCount = kFadeFrame;
			return SceneManager::SceneKind::kTitleScene;
		}
	}
	
	if (Pad::IsTrigger(PAD_INPUT_1)|| isFadeStart)
	{
		isFadeStart = true;
		m_blinkCount = 1;
		if (m_FadeFrameCount > kFadeOutFrame)
		{
			changeScene++;
			stage->ChangeStage();
			stageNumber++;
			returnTitle = false;
			m_FadeFrameCount = kFadeFrame;
			if (stageNumber > 3)
			{
				changeScene = 1;
				stageNumber = 1;
				return SceneManager::SceneKind::kTitleScene;
			}
			return SceneManager::SceneKind::kSceneMain;
		}
	}
	return SceneManager::SceneKind::kResultScene;
}

void ResultScene::Draw()
{
	if (bgX == -kBgWidth)
	{
		bgX = 0;
	}
	DrawGraph(bgX, bgY, m_bgHandle, true);
	DrawGraph(bgX+kBgWidth, 0, m_bgHandle, true);
	int blockBonus = m_stage.BrokenBlock();
	int remainingTimeBounus = kPoints - m_timer.RemainingTime();
	m_score = blockBonus + remainingTimeBounus;
	
	if (kPoints - m_timer.RemainingTime() < 0)
	{
		remainingTimeBounus = 0;
	}
	if (m_score < 0)
	{
		m_score = blockBonus;
	}
	if (stageNumber == 3)
	{
		DrawGraph(kClearPosX, kClearPosY, m_clearHandle, true);
		DrawFormatStringToHandle(kTextPosX, kTimeTextStage3PosY, 0xba55d3, m_fontScoreHandle, "Time  %d", remainingTimeBounus);
		DrawFormatStringToHandle(kTextPosX, kBlockTextStage3PosY, 0xba55d3, m_fontScoreHandle, "Block %04d", blockBonus);
		DrawFormatStringToHandle(kTextPosX, kScoreTextStage3PosY, 0xba55d3, m_fontScoreHandle, "Score %d", m_score);
	}
	else
	{
		DrawFormatStringToHandle(kTextPosX, kTimeTextPosY, 0xba55d3, m_fontScoreHandle, "Time  %d", remainingTimeBounus);
		DrawFormatStringToHandle(kTextPosX, kBlockTextPosY, 0xba55d3, m_fontScoreHandle, "Block %04d", blockBonus);
		DrawFormatStringToHandle(kTextPosX, kScoreTextPosY, 0xba55d3, m_fontScoreHandle, "Score %d", m_score);
	}
	DrawFormatStringToHandle(kStageTextPosX, kStageTextPosY, 0xf0f8ff, m_fontHandle, "Stage %d", stageNumber);

	if (m_score >= kARankCriteria && m_player.IsNoDamage())
	{
		DrawFormatStringToHandle(kTextPosX, kRankPosY, 0xba55d3, m_fontRankHandle, "Rank");
		DrawFormatStringToHandle(kRankPosX, kRankPosY, 0xffd700, m_fontRankHandle, "S");
	}
	else if (m_score >= kARankCriteria)
	{
		DrawFormatStringToHandle(kTextPosX, kRankPosY, 0xba55d3, m_fontRankHandle, "Rank");
		DrawFormatStringToHandle(kRankPosX, kRankPosY, 0xdc143c, m_fontRankHandle, "A");
	}
	else if (m_score >= kBRankCriteria)
	{
		DrawFormatStringToHandle(kTextPosX, kRankPosY, 0xba55d3, m_fontRankHandle, "Rank");
		DrawFormatStringToHandle(kRankPosX, kRankPosY, 0x4682b4, m_fontRankHandle, "B");
	}
	else
	{
		DrawFormatStringToHandle(kTextPosX, kRankPosY, 0xba55d3, m_fontRankHandle, "Rank");
		DrawFormatStringToHandle(kRankPosX, kRankPosY, 0x98fb98, m_fontRankHandle, "C");
	}
	
	if (m_blinkCount < kBlinkFrame && stageNumber == 3)
	{
		DrawFormatStringToHandle(kTextPosX, kTextPosY, 0xf0f8ff, m_fontHandle, "Press A Title");
		DrawFormatStringToHandle(380, kTextPosY, 0xf0f8ff, m_fontHandle, "Press B Title");
	}
	else if (m_blinkCount < kBlinkFrame)
	{
		DrawFormatStringToHandle(kTextPosX, kTextPosY, 0xf0f8ff, m_fontHandle, "Press A Next");
		DrawFormatStringToHandle(350, kTextPosY, 0xf0f8ff, m_fontHandle, "Press B Title");
	}

	// フェード処理
	int fadeAlpha = m_FadeFrameCount;
	// m_fadeFrameaCount = 0の時fadeAlpha = 255 真っ黒

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeAlpha);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
