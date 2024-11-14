#include "U8glib.h"

U8GLIB_SH1106_128X64 oled(U8G_I2C_OPT_NONE); // Initialize display with U8glib

const int gasSensorPin = A0; // MQ-6 analog output connected to A0
const int threshold = 10;    // Set a threshold for high gas level
const int buzzerPin1 = 12;   // Buzzer connected to pin 12
const int buzzerPin2 = 8;    // Buzzer connected to pin 8
bool warningBlink = false;   // Flag for blinking effect

void setup() {
  Serial.begin(9600);         // Serial communication with the NodeMCU
  pinMode(buzzerPin1, OUTPUT); // Set buzzer pins as outputs
  pinMode(buzzerPin2, OUTPUT);
}

void loop() {
  int gasValue = analogRead(gasSensorPin); // Read MQ-6 analog value
  int barWidth = map(gasValue, 0, 1023, 0, 100); // Map gas value to a 100-pixel width

  // Send gas value over Serial to NodeMCU
  Serial.println(gasValue); 

  // Toggle the warning blink state
  warningBlink = !warningBlink;

  // Check if the gas level is above the threshold
  if (gasValue > threshold) {
    digitalWrite(buzzerPin1, HIGH);
    digitalWrite(buzzerPin2, HIGH);
  } else {
    digitalWrite(buzzerPin1, LOW);
    digitalWrite(buzzerPin2, LOW);
  }

  // Display gas level and warning icon if necessary
  oled.firstPage();
  do {
    displayGasLevel(gasValue, barWidth);
  } while (oled.nextPage());

  delay(500); // Refresh rate of display
}

void displayGasLevel(int gasValue, int barWidth) {
  oled.setFont(u8g_font_8x13); // Set font for gas level text

  oled.setPrintPos(0, 20); 
  oled.print("Gas Level: ");
  oled.print(gasValue);

  // Draw loading bar
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
