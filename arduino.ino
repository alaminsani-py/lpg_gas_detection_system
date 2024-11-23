#include "U8glib.h"

U8GLIB_SH1106_128X64 oled(U8G_I2C_OPT_NONE); 

const int gasSensorPin = A0; 
const int threshold = 10;    
const int buzzerPin1 = 12;   
const int buzzerPin2 = 8;    
bool warningBlink = false;   


void setup() {
  Serial.begin(9600);         
  pinMode(buzzerPin1, OUTPUT);
  pinMode(buzzerPin2, OUTPUT);
}

void loop() {
  
  int gasValue = analogRead(gasSensorPin); 
  int barWidth = map(gasValue, 0, 1023, 0, 100);

  
  Serial.println(gasValue); 

  
  warningBlink = !warningBlink;

  if (gasValue > threshold) {
    digitalWrite(buzzerPin1, HIGH);
    digitalWrite(buzzerPin2, HIGH);
  } else {
    digitalWrite(buzzerPin1, LOW);
    digitalWrite(buzzerPin2, LOW);
  }

  oled.firstPage();
  do {
    displayGasLevel(gasValue, barWidth);
  } while (oled.nextPage());

  delay(500); 
}

void displayGasLevel(int gasValue, int barWidth) {
  oled.setFont(u8g_font_8x13); 

  oled.setPrintPos(0, 20); 
  oled.print("Gas Level: ");
  oled.print(gasValue);

 
  int barX = 14; 
  int barY = 40; 
  int barHeight = 8; 

  oled.drawFrame(barX, barY, 100, barHeight);
  oled.drawBox(barX, barY, barWidth, barHeight);

  if (gasValue > threshold && warningBlink) {
    int iconX = 122;
    int iconY = 8;

    oled.drawLine(iconX, iconY, iconX - 5, iconY + 10);
    oled.drawLine(iconX, iconY, iconX + 5, iconY + 10);
    oled.drawLine(iconX - 5, iconY + 10, iconX + 5, iconY + 10);

    oled.drawBox(iconX, iconY + 3, 1, 5);
    oled.drawBox(iconX, iconY + 9, 1, 2);
  }
}
