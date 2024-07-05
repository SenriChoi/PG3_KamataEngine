#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "GC2A_06_ジョ_カエイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	

		///
		/// ↓更新処理ここから
		///

		GameManager* gameManager = new GameManager();

		gameManager->Run(keys, preKeys);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
	
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
