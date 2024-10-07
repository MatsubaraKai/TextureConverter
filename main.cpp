#include <cstdio>
#include <cstdlib>
#include <assert.h>
#include "TextureConverter.h"
#include <comdef.h>
enum Argument {
	kApplicationPath, //アプリケーションのパス
	kFilePath,		  //渡されたファイルのパス

	NumArgument
};
int main(int argc, char* argv[]) {
	CoInitializeEx(0, COINIT_MULTITHREADED);
	for (int i = 0; i < argc; i++) {
		printf(argv[i]);

		printf("\n");
	}
	assert(argc >= NumArgument);

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));
	//テクスチャコンバータ
	TextureConverter converter;
	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);
	//COMライブラリの終了
	CoUninitialize();

	system("pause");
	return 0;
}


