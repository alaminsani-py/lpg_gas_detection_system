#define BLYNK_TEMPLATE_ID "*************"
#define BLYNK_TEMPLATE_NAME "LPG Gas Sensor"
#define BLYNK_AUTH_TOKEN "***************************"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN; 
char ssid[] = "********";        
char pass[] = "********"; 

BlynkTimer timer;

void setup() {
  Serial.begin(9600); 
  Blynk.begin(auth, ssid, pass); 

  timer.setInterval(1000L, sendGasData); 
}

void loop() {
  Blynk.run();
  timer.run();
}

void sendGasData() {
  if (Serial.available() > 0) {            
    int gasValue = Serial.parseInt();      
    Blynk.virtualWrite(V1, gasValue);      
  }
}
