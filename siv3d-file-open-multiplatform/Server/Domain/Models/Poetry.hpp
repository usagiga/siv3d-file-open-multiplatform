#pragma once
#include <Siv3D/String.hpp>

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
    String content = L"";
    bool contentLoaded = false;
    FilePath filePath = L"";
  };
}
