#pragma once
class Stage
{
public:
	Stage();
	~Stage();

	void Init();	// ������
	void End();	// �I��
	void Update();	// �X�V
	void Draw();	// �`��
private:
	// �O���t�B�b�N�n���h��
	int m_handle;
	// �O���t�B�b�N�Ɋ܂܂��`�b�v��
	int m_graphChipNumX;
	int m_graphChipNumY;
};

