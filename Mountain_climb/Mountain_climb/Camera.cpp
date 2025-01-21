#include "Camera.h"
#include "Player.h"

// カメラの範囲
// カメラがプレイヤーを追いかける範囲
const float CameraScopeRangeW = 320.0f;
const float CameraScopeRangeH = 96.0f;
const float CameraScopeRangeTop = 200.0f;
const float CameraScopeRangeBottom = 240.0f;

// 線形補完率
const float CameraLerpRate = 0.15f;


void Camera::Init()
{
	
}

void Camera::Update(const Player* player)
{
	// カメラの目標位置
	Vec2 aimCameraPos = m_pos;

	// 目標位置の決定
	// x座標の決定
	if (player->GetPos().x > m_pos.x + (CameraScopeRangeW * 0.5f))
	{
		aimCameraPos.x = player->GetPos().x - (CameraScopeRangeW * 0.5f);
	}
	else if (player->GetPos().x < m_pos.x - (CameraScopeRangeW * 0.5f))
	{
		aimCameraPos.x = player->GetPos().x + (CameraScopeRangeW * 0.5f);
	}
	// y座標の決定
	if (player->GetPos().y < m_pos.y - (CameraScopeRangeH * 0.5f)) // カメラを上に移動する
	{
		aimCameraPos.y = player->GetPos().y + (CameraScopeRangeH * 0.5f);
	}
	else if (player->GetPos().y > m_pos.y + (CameraScopeRangeH * 0.5f)) // カメラを下に移動する
	{
		//aimCameraPos.y = player->GetPos().y - (CameraScopeRangeH * 0.5f);
	}
	

	// 目標ポジションに、Lerpを使ってカメラポジションを近づける
	m_pos = Lerp(m_pos, aimCameraPos, CameraLerpRate);

	// ステージの幅より右端にカメラが移動しないように後で固定
	if (m_pos.x > CameraScopeRangeW)
	{
		m_pos.x = CameraScopeRangeW;
	}
	// ステージの幅より左端にカメラが移動しないように後で固定
	if (m_pos.x < 320)
	{
		m_pos.x = 320;
	}
	if (m_pos.y > CameraScopeRangeBottom)
	{
		m_pos.y = CameraScopeRangeBottom;
	}

	// Draw側に足しているcamera.pos.x/yは反転させる
	m_drawOffset.x = m_pos.x * -1;
	m_drawOffset.y = m_pos.y * -1;

	// その時、画面の中央にプレイヤーが来るようにする
	// (m_posが画面の中央になるようにする)
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

