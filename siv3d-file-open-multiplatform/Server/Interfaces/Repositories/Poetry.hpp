#pragma once

#include <Server/Domain/Models/Poetry.hpp>
#include <vector>

namespace Server::Interfaces::Repositories
{
  class PoetryRepository
  {
  public:
    virtual std::vector<Domain::Model::Poetry> GetPoetries();
  };
}
