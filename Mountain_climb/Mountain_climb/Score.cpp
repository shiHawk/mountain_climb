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

}

void Score::AddScore()
{
	// マップチップを壊すたびにスコアを加算する
	m_score += 100;
}

int Score::FinalScore()
{
	// 最終的なスコアを返す
	return m_score;
}
