#pragma once
#include "SceneManager.h"
class TitleScene
{
public:
	TitleScene();
	~TitleScene();
	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
private:
	int m_titleHandle;
	int m_buttonHandle;
	int m_blinkCount;
};

