
// Troko Tiago Classic - ESP32 D0WD-V3 + GC9A01 7pines
// Equivalente al troko-wk-es...bin pero para tu placa
#include <WiFi.h>
#include <WebServer.h>
#include <Adafruit_GC9A01A.h>
#include <SPI.h>
#include <qrcode.h>

#define TFT_CS 5
#define TFT_DC 2
#define TFT_RST 4
Adafruit_GC9A01A tft(TFT_CS, TFT_DC, TFT_RST);
WebServer server(80);
QRCode qrcode;

void showQR(const char* text){
  tft.fillScreen(0x0000);
  uint8_t qData[qrcode_getBufferSize(3)];
  qrcode_initText(&qrcode, qData, 3, 0, text);
  int scale = 240 / qrcode.size;
  if(scale<2) scale=2;
  int offset = (240 - qrcode.size*scale)/2;
  for(int y=0;y<qrcode.size;y++){
    for(int x=0;x<qrcode.size;x++){
      if(qrcode_getModule(&qrcode, x, y)){
        tft.fillRect(offset + x*scale, offset + y*scale, scale, scale, 0xFFFF);
      }
    }
  }
}

void setup(){
  SPI.begin(18, -1, 23, -1);
  tft.begin();
  WiFi.softAP("Jarvis-Config");
  showQR("WIFI:T:nopass;S:Jarvis-Config;P:;;");
  server.on("/", [](){
    server.send(200, "text/html", "<h1>Jarvis Config</h1><p>IP: 192.168.4.1</p><form action='/save'>WiFi:<input name=s><br>Pass:<input name=p><br><input type=submit></form>");
  });
  server.begin();
}
void loop(){ server.handleClient(); }
