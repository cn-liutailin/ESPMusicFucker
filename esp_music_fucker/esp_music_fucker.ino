#include <HTTPGet.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>      //https://github.com/tzapu/WiFiManager
#include <OneButton.h>        //https://github.com/mathertel/OneButton

OneButton button(D4, true);
//OneButton设置

void click() {
//按钮单击函数
  gethttp_API("http://api.klpnb.cn/index.php?enable",80);
  Serial.println("单击");
}

void doubleclick() {
//按钮双击函数
  gethttp_API("http://api.klpnb.cn/index.php?disable",80);
  Serial.println("双击");
}

void setup() {
  Serial.begin(115200);

  WiFiManager wifiManager;
  wifiManager.setAPStaticIPConfig(IPAddress(6,6,6,6), IPAddress(6,6,6,6), IPAddress(255,255,255,0));
  wifiManager.autoConnect("EspMusicFucker");
  Serial.println("connected...yeey :)");
  //WIFIManager设置

  button.attachClick(click);
  button.attachDoubleClick(doubleclick);
}

void loop() {
  button.tick();
} 