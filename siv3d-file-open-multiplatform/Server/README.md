# `Server/`

ゲームのバックエンドです。

- フロントエンドの実装がファットになることを防ぐ
- Dedicated Server の実装を可能にする

といったことを目的とし、フロントエンドが行う描画系以外の処理すべてを実行します。

フロントエンドとの通信では、サーバインスタンスの各メンバに対して直接アクセスするようにしてください。
このとき、RPC やそれに類する技術は特に利用しません。
