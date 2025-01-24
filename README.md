MSX1 Emulator for Raspberry Pi Pico
![BASIC](/pictures/screenshot00.jpg)

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
- FD (Read Only)
- Joypad

以下の機能はいまのところ実装の予定はありません。
(一部のコードは入っていますが CPU パワーが絶望的に足りないのでオフになっています。)

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
- GPIO6 VGA:Red2 (1.2K Ohm)
- GPIO7 VGA:Green0 (330 Ohm)
- GPIO8 VGA:Green1 (680 Ohm)
- GPIO9 VGA:Green2 (1.2K Ohm)
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
SCC 音源などの出力を使うには I2S DAC が必要です。(I2S DAC は PCM5102A でテストしています。)
I2S DAC との接続は以下のようになります。DAC 側の設定については使用する DAC の説明を参照してください。

GPIO14 DATA
GPIO15 BCLK
GPIO16 LRCLK

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

FDC は SONY タイプの物を実装していますので、対応する DISKBIOS を書き込む必要があります

```
ROM 本体
$ picotool load -v -x msx1.rom -t bin -o 0x10030000

DISKBIOS
$ picotool load -v -x disk.rom -t bin -o 0x10038000
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
# Joystick

DirectInput 対応のゲームパッド(1台)に対応しています。
ボタンの割り当ては、`joystick.c` で変更できます。

---
# ROM カートリッジ

2Mbit(256KiB) までの rom に対応しています。

Slot1 と Slot2 の二つがありますが、両方使う場合には 1Mbit までの ROM にしてください。
また、2Mbit の ROM は Slot1 のみ対応しています。

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
# FD

MB8877 (WD2793) を使った Sony 系ディスクドライブをエミュレートしています。
DSK 形式の 2DD のディスク(720KB)に対応しています。

DISKBASIC や MSX-DOS を使う場合には「Sony 系ディスクドライブ用」の DISKBIOS を書き込む必要があります。
uPD765A (TC8566AF) を使った「Panasonic 系ディスクドライブ」用の DISKBIOS では動作しません。

FD はライトプロテクト状態になっていますので、書き込みはできません。

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
- [pico-extras (I2S)](https://github.com/raspberrypi/pico-extras)
- [Emu2212](https://github.com/digital-sound-antiques/emu2212)
- [Emu2149](https://github.com/digital-sound-antiques/emu2149)
- [Emu2413(未使用)](https://github.com/digital-sound-antiques/emu2413)
- [C-BIOS (フォントのみ)](https://cbios.sourceforge.net/)
- [HID Parser(おそらくLUFAの改変)](https://gist.github.com/SelvinPL/99fd9af4566e759b6553e912b6a163f9)

---
# 制限事項

- FD は 2ドライブ接続されたように認識されています。MSX の 2 ドライブエミュレーション機能は無効になっています。
- Gamepad を複数接続するとうまく操作できないことがあります

---
# Gallary
![MSXDOS](/pictures/screenshot02.jpg)
![GAME1](/pictures/screenshot01.jpg)
![GAME2](/pictures/screenshot03.jpg)


