#pragma once

namespace GameWorker {
    class Worker {
    public:
        virtual void Update();

        /*/// <summary>
        /// RunSync は、同期的にゲームループを実行します。
        /// 
        /// Siv3D では描画系関数は Main() と同じスレッドでしか実行できない制約があります。
        /// RunSync はそのような非同期処理上の制約の上で Worker を動作させることを想定した関数です。
        /// </summary>
        void RunSync();

        /// <summary>
        /// RunSync は、非同期的にゲームループを実行します。
        /// </summary>
        void RunAsync();*/
    };
}
