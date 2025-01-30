#include "Timer.h"
#include "DxLib.h"

namespace
{
	int elapsedTime = 0;
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
	DrawFormatStringToHandle(270, 10, 0x00ff00, m_fontHndle, "Time:%d", elapsedTime);
}

int Timer::RemainingTime()
{
	return elapsedTime;
}
