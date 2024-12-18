#pragma once
class Score
{
public:
	 Score();
	 ~Score();
	 void Init();
	 void AddScore();
	 int FinalScore();
private:
	int m_score;
};

