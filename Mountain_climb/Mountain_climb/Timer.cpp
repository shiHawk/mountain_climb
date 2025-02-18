#include "Timer.h"
#include "DxLib.h"

namespace
{
	// Œo‰ß‚µ‚½ŽžŠÔ
	int elapsedTime = 0;
	constexpr int kTimerPosX = 270;
	constexpr int kTimerPosY = 10;
}

Timer::Timer():
	m_fontHndle(-1)
{
}

Timer::~Timer()
{
}

void Timer::Init()
{
	m_fontHndle = CreateFontToHandle("Elephant", 16, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	elapsedTime = 0;
}

void Timer::End()
{
}

void Timer::Update()
{
	elapsedTime++;
}

void Timer::Draw()
{
	DrawFormatStringToHandle(kTimerPosX, kTimerPosY, 0x98fb98, m_fontHndle, "Time:%d", elapsedTime);
}

int Timer::RemainingTime()
{
	return elapsedTime;
}
