#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <Windows.h>
#include "TextureConverter.h"

// コマンドライン引数
enum Argument {
	kApplicationPath, // アプリケーションパス
	kFilePath, // 渡されたファイルパス
	NumArgument
};

int main(int argc, char* argv[]) {

	assert(argc >= NumArgument);

	// COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// テクスチャコンバータ
	TextureConverter converter;

	// テクスチャ変換
	converter.ConverterTextureWICToDDS(argv[kFilePath]);

	// COM ライブラリの終了
	CoUninitialize();

	return 0;

}