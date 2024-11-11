#pragma once

class TitleScene;
class SceneMain;
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
		kSceneMain,
		kTitleScene
	};
private:

	// ���ݎ��s���̃V�[��
	SceneKind m_kind;

	SceneMain* m_pSceneMain;
	TitleScene* m_pTitleScene;
};

