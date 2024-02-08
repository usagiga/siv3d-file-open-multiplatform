#include <Server/Domain/Models/Poetry.hpp>
#include <Siv3D/String.hpp>

using namespace s3d;

namespace Model
{
  Poetry::Poetry(FilePath path)
  {
    this->filePath = path;
    // regexp でいい感じにさばく
    this->opus = 1;
  }
}
