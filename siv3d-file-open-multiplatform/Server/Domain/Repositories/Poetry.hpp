#pragma once

#include <Server/Domain/Models/Poetry.hpp>
#include <vector>

namespace Server::Domain::Repositories
{
  class GetPoetriesProps
  {
    // NOTICE: just for arguments of abstruct classes
    // define details in child classes
  };

  class PoetryRepository
  {
  public:
    virtual std::vector<Domain::Model::Poetry*>
    GetPoetries(GetPoetriesProps* props) = 0;
  };
}
