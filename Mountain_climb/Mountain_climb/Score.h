#pragma once
class Score
{
public:
	 Score();
	 ~Score();
	 void Init();
	 void Update();
	 int DrawScore();
private:
	int m_score;
};

