#include <Server/Domain/Models/Poetry.hpp>
#include <Siv3D/String.hpp>
#include <Siv3D/TextReader.hpp>
#include <regex>

using namespace s3d;

namespace Model
{
  //
  // Poetry
  //

  // 読み込みやパースは各関数の初回アクセス時に
  // 行われるようになっているが、
  // 事前に全部メモリに載せてしまうほうがよい場合は
  // コンストラクタで読み込み・パースを行うこと

  Poetry::Poetry(FilePath path) { this->filePath = path; }

  FilePath Poetry::GetFilePath() { return this->filePath; }

  int Poetry::GetOpus()
  {
    // 関数の初回アクセスのみパース
    if (not this->opusLoaded)
    {
      auto fileName = FileSystem::FileName(this->GetFilePath());
      std::wsmatch opusMatch;

      auto opusFound =
          std::regex_match(fileName.str(), opusMatch, this->fileNameRE);
      if (not opusFound || opusMatch.size() < 2)
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

  String Poetry::GetContent()
  {
    // 関数の初回アクセスのみパース
    if (not this->contentLoaded)
    {
      auto path = this->GetFilePath();
      auto encoding = TextEncoding::UTF8;
      auto reader = new TextReader(path, encoding);

      reader->readAll(this->content);
    }

    return this->content;
  }

  // 内部のロジックでは作品番号以外とっていないので、それ以外は省略
  const std::wregex Poetry::fileNameRE(LR"(^(\d+)-.+$)");
}
