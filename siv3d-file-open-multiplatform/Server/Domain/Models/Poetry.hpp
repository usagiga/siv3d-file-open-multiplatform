#pragma once
#include <Siv3D/String.hpp>
#include <regex>
#include <string>

using namespace s3d;

namespace Model
{
  class Poetry
  {
  public:
    Poetry(FilePath path);

    int GetOpus();
    String GetContent();
    FilePath GetFilePath();

  private:
    int opus = -1;
    bool opusLoaded = false;
    String content = L"";
    bool contentLoaded = false;
    FilePath filePath = L"";

    // ファイル名に関する形式
    //
    // 正規表現は初回のコンパイルに時間がかかるため、
    // static にすることでコンパイルを一度のみに制限する
    //
    // 形式は (作品番号)-(作品名).(拡張子)
    const static std::wregex fileNameRE;
  };
}
