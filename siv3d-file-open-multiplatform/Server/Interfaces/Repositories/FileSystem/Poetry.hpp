#pragma once

#include <Server/Domain/Models/Poetry.hpp>
#include <Server/Domain/Repositories/Poetry.hpp>
#include <Siv3d/String.hpp>

namespace Server::Interfaces::Repositories::FileSystem
{
  class Poetry : public Domain::Model::Poetry
  {
  public:
    int GetOpus() override;
    s3d::String GetContent() override;
    s3d::FilePath GetFilePath();

    static Poetry* New(s3d::FilePath path);

  private:
    int opus = -1;
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

  class GetPoetriesFileSystemProps
      : public Domain::Repositories::GetPoetriesProps
  {
  public:
    s3d::FilePath GetTargetDirectory();
    void SetTargetDirectory(s3d::FilePath dir);

  private:
    s3d::FilePath targetDirectory = L"";
  };

  class PoetryFileSystemRepository : Domain::Repositories::PoetryRepository
  {
    std::vector<Domain::Model::Poetry*>
    GetPoetries(Domain::Repositories::GetPoetriesProps* props) override;
  };
}
