#include "main.h"
#include "DxLib.h"
#include "Rect.h"
#include "controller/ControllerFacade.h"

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
	if (DxLib_Init() == -1) {
		return -1;
	}

	//描画先を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);


	auto center = Vector2(200, 200);
	auto size = Vector2(400, 30);
	float angle = 0;
	auto rect = Rect(center, size, angle);

	auto center2 = Vector2(500, 240);
	float angle2 = 1.5;
	auto rect2 = Rect(center2, size, angle2);


	//auto key = ControllerFacade::GetInstance();

	//メインループ
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 /*&& gpUpdateKey() == 0*/) {
		//printfDxを消去
		clsDx();

		angle += 0.03;
		angle2 += 0.01;
		rect.SetParameter(center, size, angle);
		rect2.SetParameter(center2, size, angle2);
		rect.Draw();
		rect2.Draw();
		if (rect.isCollision(rect2)) {
			printfDx("あててんのよ");
		}


		//printfDx("動作正常");
	}

	DxLib_End();

	return 0;
}