
#pragma once
// Board Tiago Classic - Adaptado de Troko/Xiaozhi para ESP32-D0WD-V3 + GC9A01 7 pines
#define BOARD_NAME "tiago-classic"
#define DISPLAY_DRIVER_GC9A01 1
#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 240
#define DISPLAY_MIRROR_X 0
#define DISPLAY_MIRROR_Y 0
#define DISPLAY_SWAP_XY 0

#define DISPLAY_PIN_SCK  18
#define DISPLAY_PIN_MOSI 23
#define DISPLAY_PIN_CS   5
#define DISPLAY_PIN_DC   2
#define DISPLAY_PIN_RST  4
#define DISPLAY_PIN_BL   -1

#define AUDIO_I2S_MIC_SCK  26
#define AUDIO_I2S_MIC_WS   27
#define AUDIO_I2S_MIC_SD   33
#define AUDIO_I2S_MIC_LR_GND 1

#define AUDIO_SPKR_DAC_PIN 25
#define AUDIO_SPKR_PAM8403 1

#define WIFI_AP_SSID "Jarvis-Config"
