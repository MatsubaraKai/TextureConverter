#pragma once
#include <string>
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
public:
	/// <summary>
	///テクスチャをWICからDDSに変換する
	/// </summary>
	/// <param name = "filePath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& filePath);
};

