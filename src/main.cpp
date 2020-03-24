#include <Arduino.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

DHT dht11(2, DHT11, 1);

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  // put your setup code here, to run once:
  dht11.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);

  oled.clearDisplay();
  oled.display();
}

void loop()
{
  // put your main code here, to run repeatedly:
  dht11.read();

  oled.clearDisplay();

  oled.setCursor(0, 0);
  oled.setTextColor(WHITE);
  oled.setTextSize(2);

  oled.print(F("Temp:"));
  oled.print(dht11.readTemperature(), 1);
  oled.println(F("C"));

  oled.print(F("RHum:"));
  oled.print(dht11.readHumidity(), 1);
  oled.println(F("%"));

  oled.display();

  delay(500);
}