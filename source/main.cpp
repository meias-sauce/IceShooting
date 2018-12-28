#include "main.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ログファイルを出さない設定
	SetOutApplicationLogValidFlag(FALSE);

	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//ウィンドウサイズ設定
	SetGraphMode(640, 480, 32);
	SetWindowSize(640, 480);

	//バックグラウンドでも動作する設定
	SetAlwaysRunFlag(true);

	//アーカイブファイルのパス設定、コード公開してるので実はガバガバ
	SetDXArchiveKeyString("atuikoori");
	//アーカイブファイルの拡張子設定
	SetDXArchiveExtension("sgp");

	//アイコンファイルの読み込み
	//SetWindowIconID(IDI_ICON2);

	//ウィンドウタイトルの設定
	SetMainWindowText("最高にアツいシューティングを頼む");


	//DxLib初期化
	if (DxLib_Init() == -1)	{
		return -1;
	}

	//描画先を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	//メインループ
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 /*&& gpUpdateKey() == 0*/) {
		//printfDxを消去
		clsDx();
		printfDx("動作正常");
	}

	DxLib_End();

	return 0;
}