#pragma once
#include"Score.h"
#include "Stage.h"

class TitleScene;
class SceneMain;
class ResultScene;
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init();
	void End();

	void Update();
	void Draw();
public:
	// �񋓌^���g�p���Č��ݎ��s���̃V�[�����Ǘ�����
	enum SceneKind
	{
		kTitleScene,
		kSceneMain,
		kResultScene,
		kSceneNum
	};
private:
	Stage m_stage;
	// ���ݎ��s���̃V�[��
	SceneKind m_kind;

	TitleScene* m_pTitleScene;
	SceneMain* m_pSceneMain;
	ResultScene* m_pResultScene;
};

