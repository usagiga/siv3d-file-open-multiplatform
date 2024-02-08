# `Commons/GameWorker/`

GameWorker は、Siv3D のゲームループ内外で動作するコンポーネントを複数定義する機能を提供するフレームワークです。

フロントエンドとバックエンドのような、機能・役割ごとのコード分割を補助し、
ゲームに必要となるいくつかの機能をサブシステムに提供します。

- ゲームループ内での直接の処理実行
- (未実装) フレームのクロックや、フレームを利用したイベントシステムの提供
- (未実装) 非同期処理に関する機能の提供