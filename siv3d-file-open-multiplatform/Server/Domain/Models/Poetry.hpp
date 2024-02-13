#pragma once
#include <Siv3D/String.hpp>
#include <regex>
#include <string>

namespace Server::Domain::Model
{
  class Poetry
  {
  public:
    virtual int GetOpus() = 0;
    virtual s3d::String GetContent() = 0;
  };
}
