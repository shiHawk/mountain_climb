#pragma once
class Score
{
public:
	 Score();
	 ~Score();
	 void Init();
	 void AddScore();
	 int DrawScore();
private:
	int m_score;
};

