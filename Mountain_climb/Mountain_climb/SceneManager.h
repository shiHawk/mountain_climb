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
		kTitleScene,
		kSceneMain,

		kSceneNum
	};
private:

	// ���ݎ��s���̃V�[��
	SceneKind m_kind;

	TitleScene* m_pTitleScene;
	SceneMain* m_pSceneMain;
};

