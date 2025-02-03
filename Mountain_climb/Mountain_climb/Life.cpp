#include "Life.h"
#include "DxLib.h"

namespace
{
	// グラフィックのサイズ
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 23;
	// アニメーションのコマ数
	constexpr int kAnimNum = 11;

	// アニメーション1コマのフレーム数
	constexpr int kSingleAnimFrame = 4;
	// 表示座標関連
	constexpr int kBasePosX = 200;
	constexpr int kIntervalX = 120;

	constexpr int kPosY = 9;

	// サイズ(拡大率)
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
	// アニメーションの進行
	m_animFrameCount++;
	if (m_animFrameCount >= kAnimNum * kSingleAnimFrame)
	{
		m_animFrameCount = 0;
	}
}

void Life::Draw()
{
	// グラフィックの切り出し位置(X座標)を計算で求める
	int animNo = m_animFrameCount / kSingleAnimFrame;

	// indexから表示位置を決定する
	int posX = 20 + m_index * 50;

	DrawRectRotaGraph(posX, kPosY,	// 中心座標を指定する
		kGraphWidth * animNo, 0, kGraphWidth, kGraphHeight,	// グラフィックの切り出し位置
		kScale, 0.0,	// 拡大率、回転
		m_handle, true);
}

