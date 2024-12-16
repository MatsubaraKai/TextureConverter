#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <Windows.h>
#include "TextureConverter.h"
#include <iostream>
#include <string>
#include <filesystem>

int main(int argc, char* argv[]) {
    std::string filePath;

    if (argc >= 2) {
        // ドラッグ＆ドロップされた場合
        filePath = argv[1];
    }
    else {
        // 手動入力の場合
        std::cout << "Please enter the file path: ";
        std::getline(std::cin, filePath);
    }

    // COMライブラリの初期化
    HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    if (FAILED(hr)) {
        std::cerr << "Failed to initialize COM library.\n";
        return -1;
    }

    // テクスチャコンバータ
    TextureConverter converter;

    // ファイルパスが正しいか確認
    if (filePath.empty()) {
        std::cerr << "Error: File path is empty.\n";
        return -1;
    }

    try {
        // テクスチャ変換
        converter.ConverterTextureWICToDDS(filePath);
        std::cout << "Conversion successful for: " << filePath << "\n";
    }
    catch (...) {
        std::cerr << "Error: Failed to process file: " << filePath << "\n";
    }

    // COMライブラリの終了
    CoUninitialize();

    return 0;
}