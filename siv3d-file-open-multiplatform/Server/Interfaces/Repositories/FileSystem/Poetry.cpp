#include <Server/Domain/Models/Poetry.hpp>
#include <Server/Interfaces/Repositories/FileSystem/Poetry.hpp>
#include <vector>

namespace Server::Interfaces::Repositories::FileSystem
{
  //
  // Poetry
  //

  FileSystem::Poetry::Poetry(s3d::FilePath path) { this->filePath = path; }

  int Poetry::GetOpus()
  {
    // 関数の初回アクセスのみパース
    if (!this->opusLoaded)
    {
      auto fileName = s3d::FileSystem::FileName(this->GetFilePath());
      std::wsmatch opusMatch;

      auto opusFound =
          std::regex_match(fileName.str(), opusMatch, this->fileNameRE);
      if (!opusFound || opusMatch.size() < 2)
      {
        this->opus = -1;
      }
      else
      {
        auto opusStr = opusMatch[1].str();
        this->opus = std::stoi(opusStr);
      }

      this->opusLoaded = true;
    }

    return this->opus;
  }

  s3d::String Poetry::GetContent()
  {
    // 関数の初回アクセスのみパース
    if (!this->contentLoaded)
    {
      auto path = this->GetFilePath();
      auto encoding = s3d::TextEncoding::UTF8;
      auto reader = new s3d::TextReader(path, encoding);

      reader->readAll(this->content);
    }

    return this->content;
  }

  s3d::FilePath Poetry::GetFilePath() { return this->filePath; }

  // 内部のロジックでは作品番号以外とっていないので、それ以外は省略
  const std::wregex Poetry::fileNameRE(LR"(^(\d+)-.+$)");

  //
  // PoetryFileSystemRepository
  //

  std::vector<Domain::Model::Poetry> PoetryFileSystemRepository::GetPoetries()
  {
    return std::vector<Domain::Model::Poetry>();
  }
}
