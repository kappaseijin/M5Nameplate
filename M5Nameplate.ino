#include <M5Stack.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t boxMargin = 10;
uint16_t bgColor = BLACK;
uint16_t textColor = WHITE;

uint16_t isChanged = true;

void setup() {
  M5.begin();

  initScreen();
}

void loop() {
  M5.update();

  if (M5.BtnA.wasReleased()) {
    isChanged = true;
    M5.Lcd.print('A');
    switchColor();
  }

  if (!isChanged) {
    return;
  }

  initScreen();
  drawQr();
  drawName();
  drawAbstract();

  isChanged = false;
}

void switchColor() {
  if (bgColor == WHITE) {
    bgColor = BLACK;
    textColor = WHITE;
  } else {
    bgColor = WHITE;
    textColor = BLACK;
  }
}

void initScreen() {
  M5.Lcd.fillScreen(bgColor);
  M5.Lcd.setTextColor(textColor);
}

void drawQr() {
  uint8_t qrWidth  = (240 / 2) - (boxMargin * 2);
  uint16_t qrPosX = (320 - qrWidth - boxMargin);
  uint16_t qrPosY = boxMargin;
  const char* msg = "https://twitter.com/@kappaseijin";
  
  M5.Lcd.qrcode(msg, qrPosX, qrPosY, qrWidth);
}

void drawName() {
  uint8_t fontSize = 2;
  const char* msg = "@kappaseijin";
  uint16_t posX = boxMargin + (8 * fontSize * strlen(msg) / 2);
  uint16_t posY = boxMargin + (8 * fontSize * 1 / 2);

  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.drawCentreString(msg, posX, posY, fontSize);
}

void drawAbstract() {
  uint8_t fontSize = 2;
  const char* msg = "I'm Engineer of Server Side, Embedded and VR.";
  uint16_t posX = boxMargin;
  uint16_t posY = boxMargin + (240 * 4 / 6);

  M5.Lcd.setTextSize(fontSize);
  M5.Lcd.setCursor(posX, posY);
  M5.Lcd.println(msg);
}
