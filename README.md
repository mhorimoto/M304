# M304
UECS Controller Shield for Arduino MEGA I/F


## 1. PARTS

### 1-1. NIC

DIPタイプのW5500チップを使用したNICを使用する．

Tzt smart electronics USR-ES
https://ja.aliexpress.com/item/4000226162371.html?spm=a2g0o.productlist.0.0.108b556fFrPpIG&algo_pvid=0f65874c-7d38-4736-bc98-e0055426879e&algo_exp_id=0f65874c-7d38-4736-bc98-e0055426879e-11&pdp_ext_f=%7B%22sku_id%22%3A%2210000000891679931%22%7D&pdp_npi=2%40dis%21JPY%21%21563.0%21%21%21311.0%21%21%402101e9d116535463700423560e6ebc%2110000000891679931%21sea

### 1-2. LCD

20x4 Parallel connection (秋月コード P-10844)


## 2. Pin Assign

### 2-1. LCD (J1)

| I/O PIN | NAME | LCD PIN |
|:-------:|------|:-------:|
|         | GND  |    1    |
|         | Vdd  |    2    |
|         | Vo   |    3    |
|   37    | RS   |    4    |
|   38    | R/W  |    5    |
|   39    | ENA  |    6    |
|   40    | DB0  |    7    |
|   41    | DB1  |    8    |
|   42    | DB2  |    9    |
|   43    | DB3  |   10    |
|   44    | DB4  |   11    |
|   45    | DB5  |   12    |
|   46    | DB6  |   13    |
|   47    | DB7  |   14    |
|         | BL+  |   15    |
|         | BL-  |   16    |

データピン８ピンすべて接続してある．

### 2-2. Relay OUT (J2)
リレー制御用のポートである．アクティブロー(負論理)である．

| J2 PIN | NAME |I/O PIN |
|:------:|------|:------:|
|    1   | RLY1 |   22   |
|    2   | RLY2 |   23   |
|    3   | RLY3 |   24   |
|    4   | RLY4 |   25   |
|    5   | RLY5 |   26   |
|    6   | RLY6 |   27   |
|    7   | RLY7 |   28   |
|    8   | RLY8 |   29   |
|    9   | Vdd  |   +5V  |

リレー制御の自動・手動状態検知のための端子(STAT)はI/O PIN=31である.

|状態|D31の状態|
|:--:|:-------:|
|自動|   H     |
|手動|   L     |

### 2-3. iM920 Interface (J3)
iM920用のインタフェースで3.3V駆動です.

| J3 PIN | NAME  | I/O PIN |
|:------:|-------|:-------:|
|    1   | RESET |    D6   |
|    2   | BUSY  |    D2   |
|    3   | GND   |   GND   |
|    4   | Vcc   |   3.3V  |
|    5   | TX    | D19(Rx) |
|    6   | RX    | D18(Tx) |
|    7   | STATUS|   D5    |

### 2-4. GNSS(GPS) Interface (J4)
秋月電子通商のGNSSキット用．

| J4 PIN | NAME  | I/O PIN  |
|:------:|-------|:--------:|
|    1   | 1PPS  |    D4    |
|    2   | RX    | D14(Tx3) |
|    3   | TX    | D15(Rx3) |
|    4   | GND   |   GND    |
|    5   | Vcc   |   +5V    |



### 2-5. Arrow Switch

アクティブローである．

| I/O PIN | 表示|回路図記号|
|:-------:|:---:|:----:|
|   32    | 決定 (SW_ENTER)| SW6 |
|   33    |  ↑ (SW_A) | SW2 |
|   34    |  ↓ (SW_B) | SW3 |
|   35    |  ← (SW_C) | SW4 |
|   36    |  → (SW_D) | SW5 |

### 2-6. 選択
ADCに接続している．ロータリーエンコーダの代わりにADCの出力を得て選択する．

| I/O PIN | 表示 | 回路図記号 |
|:----:|:-------------:|:---:|
|  A15 | 選択(SELECTOR) | RV2 |

### 2-7. RESET
リセットボタンはArduino MEGAのRESETピンへ直結していると同時にNICのRESETピンにも接続されている．アクティブローである．

### 2-8. SAFEMODE Switch
UECSの初期設定を行う際に必要となるスイッチ．UARDECS_Libraryの既定値である

| I/O PIN | 表示     | 回路図記号 |
|:----:|:----------------:|:---:|
|  D3  | 初期設定(SAFEMODE) | SW7 |

### 2-9. JA pins (Analog ports)
以下のピン配置で3.3V用8ポート，5V用7ポートがある．
ソフトウェアで入出力の両用に使える．

| XH PIN | 意味               |
|:------:|:------------------|
|    1   | GND               |
|    2   | CPUのAnalog port  |
|    3   | 電源 (3.3V or 5V)  |

コネクタとADCポートの関係

| PORT名 | 電圧 | I/O PIN |
|:-----:|:----:|:-------:|
|  JA0  | 3.3V |   A0    |
|  JA1  | 3.3V |   A1    |
|  JA2  | 3.3V |   A2    |
|  JA3  | 3.3V |   A3    |
|  JA4  | 3.3V |   A4    |
|  JA5  | 3.3V |   A5    |
|  JA6  | 3.3V |   A6    |
|  JA7  | 3.3V |   A7    |
|  JA8  |  5V  |   A8    |
|  JA9  |  5V  |   A9    |
|  JA10 |  5V  |   A10   |
|  JA11 |  5V  |   A11   |
|  JA12 |  5V  |   A12   |
|  JA13 |  5V  |   A13   |
|  JA14 |  5V  |   A14   |

### 2-10. JD pins (Digital ports)
以下のピン配置で7ポートある．ソフトウェアで入出力を切り替えられる．

| XH PIN | 意味                |
|:------:|:-------------------|
|    1   | GND                |
|    2   | CPUのDigital port  |

コネクタとDIOポートの関係

| PORT名 | I/O PIN |
|:-----:|:-------:|
|  JD7  |   D7    |
|  JD8  |   D8    |
|  JD9  |   D9    |
|  JD10 |   D10   |
|  JD11 |   D11   |
|  JD12 |   D12   |
|  JD13 |   D13   |

### 2-11. UART (JX2)
外部の装置とUART接続するためのポートが準備されている．
ポート名はJX2．電圧レベルは5V．接続先の送受関係は，2ピンに対象体のRxを3ピンにTxを接続する．


| XH PIN番号 | I/O PIN   |
|:---------:|:---------:|
|     1     | GND       |
|     2     | D16 (Tx2) |
|     3     | D17 (Rx2) |

### 2-12. TEST Pad
独自にテストを行う際の独立したDIO pinのパッド．

| Pad名 | I/O PIN |
|:-----:|:-------:|
| JD30  |   D30   |
| JD48  |   D48   |
| JD49  |   D49   |




https://stackedit.io/app#


## 3.Software

### 3-1. M304_Library

M304_Libraryは，M304を使用する際に初期化やポート名を決定してくれるヘッダファイルと若干の関数がまとめられたファイル．
現状では，Arduino-IDE(arduino-cli)が使用できるディレクトリにコピーして使う．
将来的には，このディレクトリから分離されて，Arduino-IDEなどのライブラリ管理から管理できるようにする．
同時にUARDECS_MEGAとの整合も図る．
