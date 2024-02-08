#pragma once

#include <Commons/GameWorker/Worker.hpp>
#include <vector>

namespace GameWorker
{
  class WorkerContainer
  {
  public:
    void RegisterWorker(Worker worker);
    void RunSync();

  private:
    static std::vector<Worker> workers;
  };
}
