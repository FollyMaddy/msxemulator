MSX1 Emulator for Raspberry Pi Pico
---
# 概要

MSX1 のエミュレータです。
以下の機能を実装しています。

- メイン RAM(64KB)
- VDP (16KB/NTSC)
- PSG
- Konami SCC (DAC 出力時のみ)
- ROM カートリッジ
- テープ

以下の機能は未実装です

- FDD
- Joypad

以下の機能は実装の予定はありません。

- FM 音源(OPLL)

---
# 配線

Pico と VGA コネクタやブザー/スピーカーなどを以下のように配線します。

- GPIO0 VGA:H-SYNC
- GPIO1 VGA:V-SYNC
- GPIO2 VGA:Blue0 (330 Ohm)
- GPIO3 VGA:Blue1 (680 Ohm)
- GPIO4 VGA:Red0 (330 Ohm)
- GPIO5 VGA:Red1 (680 Ohm)
- GPIO6 VGA:Red2
- GPIO7 VGA:Green0 (330 Ohm)
- GPIO8 VGA:Green1 (680 Ohm)
- GPIO9 VGA:Green2
- GPIO10 Audio

VGA の色信号は以下のように接続します

```
Blue0 --- 330 Ohm resister ---+
                              |
Blue1 --- 680 Ohm resister ---+---> VGA Blue

Red0  --- 330 Ohm resister ---+
                              |
Red1  --- 680 Ohm resister ---+
                              |
Red2  --- 1.2k Ohm resister --+---> VGA Red

Green0--- 330 Ohm resister ---+
                              |
Green1--- 680 Ohm resister ---+
                              |
Green2--- 1.2k Ohm resister --+---> VGA Green
```

このほかに VGA、Audio の　GND に Pico の　GND を接続してください。

---
# サウンド

デフォルトでは自前の PSG を用いて GPIO10 に PWM 出力されます。
SCC 音源などの出力を使うには I2S DAC が必要です。

---
# 使い方

`prebuild` 以下にある uf2 ファイルを Pico に書き込みます。

- msxemulator.uf2           PWM 出力(PSGのみ) 
- msxemulator_scc.uf2       I2S DAC 出力(SCC 対応)

初めて使う場合には、システム ROM の書き込みが必要です。

---
# ROM など

著作権の関係で ROM は含まれていません。

最低限 MSX1 のシステム ROM (32KiB)が必要です。
実機を持っていなくても ROM カートリッジしか使わない場合は、[C-BIOS](https://cbios.sourceforge.net/) が使えます。
C-BIOS を使う場合には、`cbios_main_msx1_jp.rom` を使ってください。

用意したファイルを [picotool](https://github.com/raspberrypi/pico-sdk-tools/releases)などで書き込みます。

~~FDC は SONY タイプの物を実装していますので、該当する DISKBIOS を書き込む必要があります~~

```
ROM 本体
$ picotool load -v -x msx1.rom -t bin -o 0x10030000
```

---
# キーボード

Pico の USB 端子に、OTG ケーブルなどを介して USB キーボードを接続します。
USB キーボードに存在しないキーは以下のように割り当てています。

- STOP   → Pause/Break
- SELECT → ScrollLock
- カナ　　→ カタカナ・ひらがな
- GRAPH　→ ALT

また F12 でメニュー画面に移ります。
ROM ファイルや テープイメージの操作ができます。

---
# ROM カートリッジ

2Mbit(256KiB) までの rom に対応しています。
rom ファイルを LittleFS 上に置いた後で、F12 のメニューからロードできます。
メガロムを使う場合は、カートリッジの Type を適切なものに設定してください。
Type は自動認識されますが、誤認識することがありますので、注意してください。

LittleFS の使い方については、
[こちらの記事](https://shippoiincho.github.io/posts/39/)をご覧ください。

---
# Tape

CAS 形式ファイルの入出力に対応しています。
LittleFS 上においてください。
---
# VGA

メモリ節約のため、今回はフレームバッファ方式ではなく、1 ラインつづ CPU を使ってリアルタイムに描画しています。
なので、フラッシュへの書き込み操作時に画面更新が止まります。

---
# ライセンスなど

このエミュレータは以下のライブラリを使用しています。

- [Z80](https://github.com/redcode/Z80/tree/master)
- [Zeta](https://github.com/redcode/Zeta)
- [VGA ライブラリ(一部改変)](https://github.com/vha3/Hunter-Adams-RP2040-Demos/tree/master/VGA_Graphics)
- [LittleFS](https://github.com/littlefs-project/littlefs)
- [vrEmuTms9918](https://github.com/visrealm/vrEmuTms9918)
- [pico-extras(I2S)](https://github.com/raspberrypi/pico-extras)
- [Emu2212](https://github.com/digital-sound-antiques/emu2212)
- [Emu2149](https://github.com/digital-sound-antiques/emu2149)

---
# Gallary
