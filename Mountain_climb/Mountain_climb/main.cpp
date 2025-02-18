#include "DxLib.h"
#include "game.h"
#include "SceneManager.h"
#include "resource.h"


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ��Dxlib�֐��ł�Dxlib_Init()�̑O�ɌĂԕK�v������

	// �t���X�N���[���ł͂Ȃ��A�E�B���h�E���[�h�ŊJ���悤�ɂ���
	ChangeWindowMode(Game::kDefaultWindowMode);
	// ��ʃT�C�Y��ύX����
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorBitNum);
	SetWindowText("MountainClimb");
	
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager* pScene = new SceneManager();

	pScene->Init();
	
	// �Q�[�����[�v
	while (ProcessMessage() == 0)	// Windows���s��������҂K�v������
	{
		// ����̃��[�v���n�܂������Ԃ��o���Ă���
		LONGLONG time = GetNowHiPerformanceCount();
		// ��ʑS�̂��N���A����
		ClearDrawScreen();

		// �����ɃQ�[���̏���������
		pScene->Update();
		pScene->Draw();

		// ��ʂ̐؂�ւ���҂K�v������
		ScreenFlip();		// 1/60�b�o�߂���܂ő҂�
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
		// FPS60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}
	pScene->End();

	// �������̉��
	delete pScene;

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}