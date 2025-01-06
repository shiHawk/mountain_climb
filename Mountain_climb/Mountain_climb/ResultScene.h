#pragma once
#include "SceneManager.h"
#include "Score.h"
#include "Stage.h"
class ResultScene
{
public:
	ResultScene();
	~ResultScene();

	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw(Stage* stage);
	bool ChangeSatge();
private:
	Score m_score;
};

