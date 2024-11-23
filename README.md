#  **🚨 LPG Gas Detection System with IoT Integration** 

A compact and intelligent **LPG Gas Detection System** that combines real-time monitoring, IoT connectivity, and user-friendly alerts. Built using an **MQ-6 Gas Sensor**, **Arduino Uno**, **NodeMCU**, and a **1.3-inch OLED Display**, this system ensures safety by detecting gas leaks and sending alerts to your mobile device.  

---

## 3D Model
<a href="https://www.tinkercad.com/things/k6J3IgsM2fz-lpg-gas-detection-system?sharecode=ACuUXU9nO2Kf_RjmGzpoGDxyFrbkez9Pq1xn3k_VUe8" target="_blank">
  <img src="https://img.shields.io/badge/View%20Model-Tinkercad-blue?style=for-the-badge" alt="View Model">
</a>


## 🎯 **Features**

✔️ **Real-Time Monitoring**: Continuously detects LPG gas levels.  
✔️ **OLED Display**: Shows live gas levels with a sleek loading bar.  
✔️ **Buzzer Alert**: Audible alarm for high gas concentrations.  
✔️ **IoT Connectivity**: Sends gas data to the Blynk app for remote monitoring.  
✔️ **Efficient Power Setup**:  
   - Arduino Uno powered via **5V, 1.2A AC-to-DC adapter**.  
   - NodeMCU powered from Arduino Uno's **5V pin**.  
✔️ **Portable and Neat Design**: Housed in a custom enclosure.  

---

## 📦 **Components**

| 🔧 **Component**           | 📋 **Description**                                 |
|-----------------------------|---------------------------------------------------|
| 🛠️ **Arduino Uno R3**       | Microcontroller for processing sensor data.        |
| 🌐 **NodeMCU (ESP8266)**     | Wi-Fi module for IoT integration.                 |
| 🛑 **MQ-6 Gas Sensor**       | Detects LPG gas concentration.                    |
| 🖥️ **1.3-inch OLED**         | Displays gas levels visually.                     |
| 🔔 **Buzzer**               | Provides an audible alarm for high gas levels.    |
| 🔌 **5V Adapter**           | Powers the Arduino Uno and NodeMCU system.        |
| 🏠 **Custom Enclosure**      | Protects and organizes all components.            |

---

## ⚙️ **How It Works**

1️⃣ **Gas Detection**:  
The **MQ-6 Sensor** continuously measures LPG gas levels in the surrounding environment.  

2️⃣ **Data Processing**:  
The **Arduino Uno** reads analog data from the MQ-6 sensor and processes it. The **NodeMCU**, powered via the Arduino's 5V pin, sends this data to the cloud.  

3️⃣ **OLED Display**:  
Gas levels are displayed in real time on the **1.3-inch OLED screen** with a dynamic loading bar for visual feedback.  

4️⃣ **Buzzer Alert**:  
If the gas levels exceed a predefined safety threshold, the **buzzer** activates to provide an audible warning.  

5️⃣ **IoT Integration**:  
The **NodeMCU** sends gas level data to the **Blynk App**, enabling remote monitoring and receiving alerts.  

---

## 🔌 **Power Setup**

- **Arduino Uno**: Powered by a **5V, 1.2A AC-to-DC adapter**.  
- **NodeMCU**: Receives power from the Arduino Uno’s **5V pin**.  

---

## 📐 **Wiring Diagram**

| 🧩 **Component**       | 🔌 **Connections**              |
|------------------------|---------------------------------|
| **MQ-6 Sensor**        | VCC → 5V (Arduino), GND → GND, AOUT → A0 |
| **OLED Display**       | VCC → 3.3V (Arduino), GND → GND, SCL → A5, SDA → A4 |
| **Buzzer**             | Positive → D12 (Arduino), Negative → GND |
| **NodeMCU**            | RX → TX (Arduino), TX → RX (Arduino), 5V → 5V (Arduino), GND → GND |

---

## 🚀 **Software Setup**

### 🛠️ **Arduino Code**
1. Install these libraries in the Arduino IDE:  
   - `Adafruit_GFX`  
   - `Adafruit_SSD1306`  
2. Upload the sketch to:  
   - Process MQ-6 sensor data.  
   - Control the **OLED Display**.  
   - Trigger the **buzzer** when gas levels exceed the threshold.  

### 🌐 **NodeMCU Code**
1. Program the **NodeMCU** to send gas level data to **Blynk**.  
2. Use Virtual Pin `V1` to display data in the app.  

### 📱 **Blynk App**
1. Create a project in the **Blynk App**.  
2. Add a **Gauge Widget** or **Graph Widget**.  
3. Link it to Virtual Pin `V1`.  

---

## 🔧 **Installation Steps**

1️⃣ **Hardware Setup**: Assemble all components based on the wiring diagram and secure them in the custom enclosure.  
2️⃣ **Power Up**: Connect the **5V adapter** to the Arduino Uno.  
3️⃣ **Test**:  
   - View gas levels on the **OLED Display**.  
   - Monitor real-time data in the **Blynk App**.  
   - Listen for the buzzer alert during gas leaks.  

---

## 🛡️ **Thresholds**

| ⚠️ **Condition**             | 🎯 **Action**                     |
|------------------------------|-----------------------------------|
| **Normal Gas Levels**        | Display levels on the OLED.      |
| **High Gas Levels Detected** | Trigger buzzer and send an alert.|

---

## 📈 **Future Enhancements**

✨ Add a **rechargeable battery** for portability.  
✨ Enhance the **enclosure design** for weatherproofing.  
✨ Expand IoT features with **predictive analytics**.  

---

## 📜 **License**

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.  

---

## 🤝 **Contributing**

Contributions are welcome! If you have ideas for improvement, please open an issue or submit a pull request.  

---

## 📝 **Author**

💻 Created by **Alamin Sani**.  
If you found this project helpful, don’t forget to **⭐ star this repository**!  

