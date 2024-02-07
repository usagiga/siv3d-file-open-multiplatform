# include <Siv3D.hpp>
# include <Commons/GameWorker/Worker.hpp>
# include <Commons/GameWorker/WorkerContainer.hpp>

namespace GameWorker {
    void WorkerContainer::RegisterWorker(Worker worker)
    {
        this->workers.push_back(worker);
    }

    void WorkerContainer::RunSync()
    {
        while (System::Update())
        {
            for (auto worker : this->workers)
            {
                worker.Update();
            }
        }
    }
}
