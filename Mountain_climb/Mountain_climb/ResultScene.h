#pragma once
#include "SceneManager.h"
class ResultScene
{
public:
	ResultScene();
	~ResultScene();

	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
};

