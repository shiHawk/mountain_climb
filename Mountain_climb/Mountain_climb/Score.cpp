#include "Score.h"

Score::Score():
	m_score(0)
{
}

Score::~Score()
{
}

void Score::Init()
{
	m_score = 0;
}

void Score::Update()
{
	m_score += 100;
}

int Score::DrawScore()
{
	return m_score;
}
