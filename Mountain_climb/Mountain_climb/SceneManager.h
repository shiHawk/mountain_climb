#pragma once

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
		kSceneMain
	};
private:

	// ���ݎ��s���̃V�[��
	SceneKind m_kind;

	SceneMain* m_pSceneMain;
};

