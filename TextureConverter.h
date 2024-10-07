#pragma once
#include <string>
#include <Windows.h>
#include "stringapiset.h"
#include <DirectXTex.h>
class TextureConverter
{
private:
	/// <summary>
	///テクスチャファイル読み込み
	/// </summary>
	/// <param name = "filePath">ファイルパス</param>
	void LoadWICTextureFromFile(const std::string& filePath);
	/// <summary>
	///マルチバイト文字列をワイド文字列に変換
	/// </summary>
	/// <param name = "filePath">マルチバイト文字列</param>
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);
    /// <summary>
    /// フォルダパスとファイル名を分離する
    /// </summary>
	/// <param name="filePath">ファイルパス</param>
	void SeparateFilePath(const std::wstring& filePath);
private:
	//画像の情報
	DirectX::TexMetadata metadata_;
	//画像イメージのコンテナ
	DirectX::ScratchImage scratchImage_;
	//ディレクトリパス
	std::wstring directoryPath_;
	//ファイル名
	std::wstring fileName_;
	//ファイル拡張子
	std::wstring fileExt_;

public:
	/// <summary>
	///テクスチャをWICからDDSに変換する
	/// </summary>
	/// <param name = "filePath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& filePath);
};

