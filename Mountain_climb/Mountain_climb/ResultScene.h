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
	SceneManager::SceneKind Update(Stage* stage);
	void Draw(Stage* stage);
private:
	int m_score;
};

