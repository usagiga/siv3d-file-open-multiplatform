#pragma once

#include <Server/Domain/Models/Poetry.hpp>
#include <Server/Interfaces/Repositories/Poetry.hpp>
#include <Siv3d.hpp>

namespace Server::Interfaces::Repositories::FileSystem
{
  class Poetry : Domain::Model::Poetry
  {
  public:
    Poetry(s3d::FilePath path);
    int GetOpus() override;
    s3d::String GetContent() override;
    s3d::FilePath GetFilePath();

  private:
    int opus = -1;
    bool opusLoaded = false;
    s3d::String content = L"";
    bool contentLoaded = false;
    s3d::FilePath filePath = L"";

    // ファイル名に関する形式
    //
    // 正規表現は初回のコンパイルに時間がかかるため、
    // static にすることでコンパイルを一度のみに制限する
    //
    // 形式は (作品番号)-(作品名).(拡張子)
    const static std::wregex fileNameRE;
  };

  class PoetryFileSystemRepository : Repositories::PoetryRepository
  {
    std::vector<Domain::Model::Poetry> GetPoetries();
  };
}
