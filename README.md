# lpg_gas_sensor
This project is an LPG Gas Detection System that monitors gas levels in real-time, displays the data locally, and sends alerts online via IoT. It is built using an MQ-6 gas sensor, Arduino Uno, NodeMCU, and a 1.3-inch OLED display. The system can trigger an alarm through a buzzer when high gas concentrations are detected.

Features
Real-Time Monitoring: Continuously monitors LPG gas levels using the MQ-6 gas sensor.
OLED Display: Displays gas levels on a 1.3-inch OLED screen with a dynamic loading bar indicating intensity.
Buzzer Alert: Activates a buzzer alarm when gas levels exceed the safety threshold.
IoT Integration: Sends gas level data to the Blynk platform via the NodeMCU for remote monitoring.
Compact Design: A portable and neatly enclosed housing for practical deployment.
Components
Arduino Uno R3: Microcontroller for processing sensor data.
NodeMCU (ESP8266): Wi-Fi module to send data to the Blynk platform.
MQ-6 Gas Sensor: Detects LPG gas concentration.
1.3-inch OLED Display: Displays gas levels visually.
Buzzer: Provides an audible alarm for high gas levels.
Enclosure: A custom-built housing for all components.
How It Works
Gas Detection: The MQ-6 sensor detects the LPG concentration in the air.
Data Processing: The sensor's analog signal is read by the Arduino Uno and passed to the NodeMCU for IoT integration.
Data Display: Gas levels are displayed on the OLED in real-time, with a dynamic loading bar for visual feedback.
Buzzer Alarm: If gas levels exceed a pre-defined threshold, the buzzer is triggered.
IoT Communication: Gas level data is sent to the Blynk app, allowing remote monitoring and notifications.
Wiring Diagram
Here’s a summary of the connections:

MQ-6 Sensor:
VCC → 5V (Arduino)
GND → GND (Arduino)
AOUT → A0 (Arduino)
OLED Display:
VCC → 3.3V (Arduino)
GND → GND (Arduino)
SCL → A5 (Arduino)
SDA → A4 (Arduino)
Buzzer:
Positive → D12 (Arduino)
Negative → GND
Arduino to NodeMCU:
Arduino TX → NodeMCU RX
Arduino RX → NodeMCU TX
GND → GND
Power:
Arduino and NodeMCU powered via USB or external source.
Software Setup
Arduino IDE:

Install the required libraries:
Adafruit_GFX
Adafruit_SSD1306
Write and upload the Arduino sketch to process sensor data and control the OLED and buzzer.
NodeMCU:

Program the NodeMCU to send gas level data to the Blynk platform.
Use the Virtual Pin (e.g., V1) in the Blynk app for real-time gas level monitoring.
Blynk App:

Create a project in the Blynk app and link it to your NodeMCU.
Add a widget (e.g., Gauge or Graph) to display gas levels from Virtual Pin V1.
Installation
Assemble the components and place them in the enclosure.
Connect the power supply to the Arduino and NodeMCU.
Run the Blynk app to monitor gas levels remotely.
Usage
Power on the device.
Monitor the gas levels on the OLED display.
Check real-time gas levels on the Blynk app.
Listen for the buzzer alarm in case of high LPG concentration.
Future Improvements
Add support for additional gas sensors.
Implement a rechargeable battery for portability.
Integrate a mobile app for better user interaction.
License
This project is licensed under the MIT License. See the LICENSE file for details.

Author
Created by Alamin Sani. Contributions and feedback are welcome!

Feel free to customize this further for your project!
