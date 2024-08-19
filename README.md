# NEZplug++
RGBA_CRT private fork of "Portable HES/KSS/NSF/GBR/GBS/AY Player library"

本ライブラリは
- Mamiya氏の製作したNEZplug 0.9.4.8
	- https://nezplug.sourceforge.net/
- RuRuRu氏が改良したNEZplug 0.9.4.8 + 2
- Offgao氏がさらに改良を加えたNEZplug 0.9.4.8 + 3 + 24.10
	- http://offgao.net/program/nezplug++.html

をRGBA_CRTがmingw-w64 / cmakeでビルドできるようにしたものです。

npnez.dllのビルドが目的で、winamp, kbmedia player向けPluginのビルドには非対応です。

オリジナル(0.9.4.8 + 3 + 24.10)のreadmeはこちら[readme.txt](doc/0.9.4.8+3+24.10/readme.txt)

# Licence
オリジナル（Ver 0.9.4.8）に従います。
- [licence.txt](src/license.txt)
- [nezplug.txt](doc/0.9.4.8/nezplug.txt)

# 改造ポイント
邪道な改造をいくつか
- 各種レジスタを外から読める関数 NSFSDK_IORead を追加
- 2A03のDPCMの読み込み位置が取得できる（NSFSDK_IORead）
- 文字コードをUTF-8に変換
- bssセクション削減のためいくつかのグローバル変数バッファをheapから取得するように
- https://wikiwiki.jp/mck/NSF%E3%83%97%E3%83%AC%E3%82%A4%E3%83%A4%E3%83%BC#x7976863 のdpcm_irq.zip/op20-13d.nsfがうまく再生されない問題を修正

# 謝辞
この場を借りて素晴らしいソフトウェアを作成・改良されたMamiya氏, RurRuRu氏, Offgao氏に敬意を表します。
