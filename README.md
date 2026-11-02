
# Troko - Board Tiago Classic (ESP32 Clasico + GC9A01 7 pines)

Base: https://github.com/78/xiaozhi-esp32
Adaptado para ESP32-D0WD-V3 (no S3) + GC9A01 RST CS DC SDA SCL GND VCC

CAMBIOS:
- Sin PSRAM (CONFIG_SPIRAM=n)
- Display GC9A01 240x240 driver
- Pines: SCK 18, MOSI 23, CS 5, DC 2, RST 4
- Mic INMP441 SCK 26 WS 27 SD 33 L/R GND
- Speaker PAM8403 DAC GPIO25

COMPILAR:
idf.py set-target esp32
idf.py menuconfig -> Board -> tiago-classic
idf.py build
idf.py -p COMX flash

Para web flasher esptool-js:
0x1000 bootloader.bin
0x8000 partitions.bin
0x10000 xiaozhi.bin (este build)
