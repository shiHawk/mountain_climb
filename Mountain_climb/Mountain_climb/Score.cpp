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
	// �}�b�v�`�b�v���󂷂��тɃX�R�A�����Z����
	m_score += 100;
}

int Score::FinalScore()
{
	// �ŏI�I�ȃX�R�A��Ԃ�
	return m_score;
}
