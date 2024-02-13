#include <Server/Domain/Models/Poetry.hpp>
#include <Server/Domain/Repositories/Poetry.hpp>
#include <Server/Interfaces/Repositories/FileSystem/Poetry.hpp>
#include <Siv3d/FileSystem.hpp>
#include <Siv3d/String.hpp>
#include <Siv3d/TextReader.hpp>
#include <regex>
#include <vector>

namespace Server::Interfaces::Repositories::FileSystem
{
  //
  // Poetry
  //

  int Poetry::GetOpus() { return this->opus; }

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

  Poetry* Poetry::New(s3d::FilePath path)
  {
    auto poetry = new Poetry();

    // filePath
    poetry->filePath = path;

    // opus
    std::wsmatch opusMatch;

    auto opusFound =
        std::regex_match(path.str(), opusMatch, Poetry::fileNameRE);
    if (!opusFound || opusMatch.size() < 2)
    {
      return nullptr;
    }
    auto opusStr = opusMatch[1].str();
    poetry->opus = std::stoi(opusStr);

    return poetry;
  }

  // 内部のロジックでは作品番号以外とっていないので、それ以外は省略
  const std::wregex Poetry::fileNameRE(LR"(^(\d+)-.+$)");

  //
  // GetPoetriesFileSystemProps
  //

  s3d::FilePath FileSystem::GetPoetriesFileSystemProps::GetTargetDirectory()
  {
    return this->targetDirectory;
  }
  void
  FileSystem::GetPoetriesFileSystemProps::SetTargetDirectory(s3d::FilePath dir)
  {
    if (s3d::FileSystem::IsDirectory(dir))
    {
      throw LR"(argument "dir" must point directory)";
    }

    this->targetDirectory = dir;
  }

  //
  // PoetryFileSystemRepository
  //

  std::vector<Domain::Model::Poetry*> PoetryFileSystemRepository::GetPoetries(
      Domain::Repositories::GetPoetriesProps* props)
  {
    std::vector<Domain::Model::Poetry*> result;
    auto propsParsed = static_cast<GetPoetriesFileSystemProps*>(props);
    auto targetDir = propsParsed->GetTargetDirectory();

    auto filePaths = s3d::FileSystem::DirectoryContents(targetDir);
    for (auto filePath : filePaths)
    {
      auto p = Poetry::New(filePath);

      // もし Poetry でないパスが渡されていた場合、そのパスは処理をしない
      if (p == nullptr)
        continue;

      result.push_back(p);
    }

    return result;
  }
}
