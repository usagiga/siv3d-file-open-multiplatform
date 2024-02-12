#include <Server/Domain/Models/Poetry.hpp>

namespace Server::Domain::Model
{
  int Poetry::GetOpus() { throw L"use child class"; }

  s3d::String Poetry::GetContent() { throw L"use child class"; }
}
