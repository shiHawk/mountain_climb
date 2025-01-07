#include "Timer.h"
#include "DxLib.h"

Timer::Timer()
{
}

Timer::~Timer()
{
}

void Timer::Init()
{
}

void Timer::End()
{
}

void Timer::Update()
{
	int startTime;
	startTime = GetNowCount();
	if(GetNowCount() - startTime > 600000)
	{
		m_player.InstanceDeath();
	}
}

void Timer::Draw()
{
}
