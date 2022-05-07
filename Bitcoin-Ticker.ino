
#include <NTPClient.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino.h>
#include <M5Stack.h>
#include <ArduinoJson.h>
#include "xbm.h"
const char *ssid     = "your ssid";
const char *password = "password";
String hours;
String minuts;
String timeStamp;
String tick;
String tick2;
String tick3;
String tick4;

HTTPClient http;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");


void setup() {

  M5.begin();
  WiFi.begin(ssid, password);
  M5.Power.begin();

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 2000 );
  }
  timeClient.begin();
  timeClient.setTimeOffset(14400);
}

void loop()
{
  M5.Lcd.drawXBitmap(20, 2, logo, 50, 50, TFT_BLACK, TFT_ORANGE);
  M5.Lcd.setTextSize(3);
  
  M5.Lcd.setCursor(20, 65);
  M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
  M5.Lcd.print("USDT:");
  
  M5.Lcd.setCursor(20, 105);
  M5.Lcd.setTextColor(TFT_ORANGE, TFT_BLACK);
  M5.Lcd.print("BUSD:");
  
  M5.Lcd.setCursor(20, 145);
  M5.Lcd.setTextColor(TFT_BLUE, TFT_BLACK);
  M5.Lcd.print("USDC:");
  
  M5.Lcd.setCursor(20, 185);
  M5.Lcd.setTextColor(TFT_GREENYELLOW, TFT_BLACK);
  M5.Lcd.print("BTFX:");
  ticker1();
  ticker2();
  ticker3();
  ticker4();
  timer();
  delay(10000);


}

void timer() {
  timeClient.forceUpdate();
  hours = timeClient.getFormattedTime();
  M5.Lcd.setCursor(120, 5);
  M5.Lcd.setTextSize(5);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  timeStamp = hours.substring(0, 5);
  M5.Lcd.print(timeStamp);
}

void ticker1()
{
  http.useHTTP10(true);
  http.begin("https://api.binance.com/api/v3/ticker/price?symbol=BTCUSDT");
  http.GET();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, http.getStream());
  //Serial.println(doc["price"].as<long>());
  tick = String(doc["price"].as<long>());
  M5.Lcd.setCursor(170, 65);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
  M5.Lcd.print("");
  M5.Lcd.print(tick);
  http.end(); // Disconnect
  delay(100);
}
void ticker2()
{
  http.useHTTP10(true);
  http.begin("https://api.binance.com/api/v3/ticker/price?symbol=BTCBUSD");
  http.GET();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, http.getStream());
  //Serial.println(doc["price"].as<long>());
  tick2 = String(doc["price"].as<long>());
  M5.Lcd.setCursor(170, 105);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setTextColor(ORANGE, TFT_BLACK);
  M5.Lcd.print(tick2);
  http.end(); // Disconnect
  delay(100);
}
void ticker3()
{
  http.useHTTP10(true);
  http.begin("https://api.binance.com/api/v3/ticker/price?symbol=BTCUSDC");
  http.GET();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, http.getStream());
  //Serial.println(doc["price"].as<long>());
  tick3 = String(doc["price"].as<long>());
  M5.Lcd.setCursor(170, 145);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setTextColor(TFT_BLUE, TFT_BLACK);
  M5.Lcd.print(tick3);
  http.end(); // Disconnect
  delay(100);
}
void ticker4()
{
  http.useHTTP10(true);
  http.begin("https://api.bitfinex.com/v1/pubticker/btcusd");
  http.GET();
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, http.getStream());
  //Serial.println(doc["price"].as<long>());
  tick4 = String(doc["last_price"].as<long>());
  M5.Lcd.setCursor(170, 185);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setTextColor(TFT_GREENYELLOW, TFT_BLACK);
  M5.Lcd.print(tick4);
  http.end(); // Disconnect
  delay(100);
}
