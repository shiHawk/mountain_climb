#include "DxLib.h"
#include "game.h"
#include "SceneManager.h"
#include "resource.h"


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部のDxlib関数ではDxlib_Init()の前に呼ぶ必要がある

	// フルスクリーンではなく、ウィンドウモードで開くようにする
	ChangeWindowMode(Game::kDefaultWindowMode);
	// 画面サイズを変更する
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorBitNum);
	SetWindowText("MountainClimb");
	
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager* pScene = new SceneManager();

	pScene->Init();
	
	// ゲームループ
	while (ProcessMessage() == 0)	// Windowsが行う処理を待つ必要がある
	{
		// 今回のループが始まった時間を覚えておく
		LONGLONG time = GetNowHiPerformanceCount();
		// 画面全体をクリアする
		ClearDrawScreen();

		// ここにゲームの処理を書く
		pScene->Update();
		pScene->Draw();

		// 画面の切り替わりを待つ必要がある
		ScreenFlip();		// 1/60秒経過するまで待つ
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
		// FPS60に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}
	pScene->End();

	// メモリの解放
	delete pScene;

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}