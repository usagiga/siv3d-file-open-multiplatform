#pragma once

#include <vector>
#include <Commons/GameWorker/Worker.hpp>

namespace GameWorker {
    class WorkerContainer {
    public:
        void RegisterWorker(Worker worker);
        void RunSync();
    private:
        static std::vector<Worker> workers;
    };
}
