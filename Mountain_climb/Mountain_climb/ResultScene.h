#pragma once
#include "SceneManager.h"
#include "Score.h"
class ResultScene
{
public:
	ResultScene();
	~ResultScene();

	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
private:
	Score m_score;
};

