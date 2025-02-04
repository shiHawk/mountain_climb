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
	int scrollSpeed = 1;

	// 持ち点
	constexpr int kPoints = 3000;
	// ランクの基準
	constexpr int kARankCriteria = 2250;
	constexpr int kBRankCriteria = 1500;

	// 表示するテキストの位置
	constexpr int kTextPosX = 120;
	constexpr int kTextPosY = 400;
	constexpr int kRankPosX = 330;
	constexpr int kRankPosY = 315;
	constexpr int kClearPosX = 20;
	constexpr int kClearPosY = 70;
	constexpr int kStageTextPosX = 250;
	constexpr int kStageTextPosY = 10;
	constexpr int kBlockTextPosY = 205;
	constexpr int kTimeTextPosY = 145;
	constexpr int kScoreTextPosY = 260;

	bool isFadeStart = false;
	constexpr int kFadeOutFrame = 255;
	constexpr int kGameOverFadeFrame = 60;

}

ResultScene::ResultScene():
	m_score(0),
	m_handle(-1),
	m_fontHandle(0),
	m_fontScoreHandle(0),
	m_bgHandle(0),
	m_rank(0),
	m_fontRankHandle(0),
	m_clearHandle(0),
	m_gameOverFrameCount(0)
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Init()
{
	m_fontHandle = CreateFontToHandle("Elephant", 32, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	m_fontScoreHandle = CreateFontToHandle("Elephant", 64, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	m_fontRankHandle = CreateFontToHandle("Bodoni MT Black", 64, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	m_bgHandle = LoadGraph("data/image/bg.png");
	m_clearHandle = LoadGraph("data/image/gameclear.png");
	bgX = 0;
	bgY = 0;
	isFadeStart = false;
}

void ResultScene::End()
{
	DeleteFontToHandle(m_fontHandle);
	DeleteFontToHandle(m_fontScoreHandle);
	DeleteFontToHandle(m_fontRankHandle);
	DeleteGraph(m_bgHandle);
	DeleteGraph(m_clearHandle);
}

SceneManager::SceneKind ResultScene::Update(Stage* stage)
{
	bgX -= scrollSpeed;

	if (isFadeStart)
	{
		m_gameOverFrameCount += 5;
	}
	
	if (Pad::IsTrigger(PAD_INPUT_1)|| isFadeStart)
	{
		isFadeStart = true;
		if (m_gameOverFrameCount > kFadeOutFrame)
		{
			changeScene++;
			stage->ChangeStage();
			stageNumber++;
			returnTitle = false;
			m_gameOverFrameCount = kGameOverFadeFrame;
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

	if (m_score >= kARankCriteria && m_player.IsNoDamage())
	{
		DrawFormatStringToHandle(kTextPosX, kRankPosY, 0xf0f8ff, m_fontRankHandle, "Rank");
		DrawFormatStringToHandle(kRankPosX, kRankPosY, 0xffd700, m_fontRankHandle, "S");
	}
	else if (m_score >= kARankCriteria)
	{
		DrawFormatStringToHandle(kTextPosX, kRankPosY, 0xf0f8ff, m_fontRankHandle, "Rank");
		DrawFormatStringToHandle(kRankPosX, kRankPosY, 0xdc143c, m_fontRankHandle, "A");
	}
	else if (m_score >= kBRankCriteria)
	{
		DrawFormatStringToHandle(kTextPosX, kRankPosY, 0xf0f8ff, m_fontRankHandle, "Rank");
		DrawFormatStringToHandle(kRankPosX, kRankPosY, 0x4682b4, m_fontRankHandle, "B");
	}
	else
	{
		DrawFormatStringToHandle(kTextPosX, kRankPosY, 0xf0f8ff, m_fontRankHandle, "Rank");
		DrawFormatStringToHandle(kRankPosX, kRankPosY, 0x98fb98, m_fontRankHandle, "C");
	}
	
	DrawFormatStringToHandle(kStageTextPosX, kStageTextPosY, 0xf0f8ff, m_fontHandle, "Stage %d", stageNumber);
	if (stageNumber == 3)
	{
		DrawGraph(kClearPosX, kClearPosY, m_clearHandle, true);
	}
	DrawFormatStringToHandle(kTextPosX, kTextPosY, 0xf0f8ff, m_fontHandle, "Press A Button");
	DrawFormatStringToHandle(kTextPosX, kBlockTextPosY, 0xba55d3, m_fontScoreHandle, "Block:%d",blockBonus);
	DrawFormatStringToHandle(kTextPosX, kTimeTextPosY, 0xba55d3, m_fontScoreHandle, "Time:%d", remainingTimeBounus);
	DrawFormatStringToHandle(kTextPosX, kScoreTextPosY, 0xba55d3,m_fontScoreHandle,"Score:%d",m_score);

	// フェード処理
	int fadeAlpha = m_gameOverFrameCount;
	// m_fadeFrameaCount = 0の時fadeAlpha = 255 真っ黒

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeAlpha);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
