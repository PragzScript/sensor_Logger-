# sensor_Logger- 
# Sensor Data Logger (ESP32 + DHT22 + Light Sensor + OLED + Python Visualization)
## Live Simulation

You can view and run the project online in Wokwi:

[Open in Wokwi](https://wokwi.com/projects/44894914486044569)
[Visualization in Python](https://colab.research.google.com/drive/1oKN-e_HhK1HBuJyPRxvD5DQtWc6FrRnz?authuser=0#scrollTo=N3BUszqCOE56)

link : https://wokwi.com/projects/44894914486044569

## Overview
This project is a **real-time sensor data logger** using **ESP32**, a **DHT22 temperature & humidity sensor**, and a **light sensor**. It reads sensor values, displays them on an **OLED screen**, sends data via **UART**, and allows **visualization in Python**. Additionally, it can be extended to send data online to **IoT dashboards** like ThingSpeak.

---

## Features

- **Temperature & Humidity Logging:** Reads data from DHT22 sensor every 2 seconds.
- **Multiple Sensors:** Simultaneously logs temperature, humidity, and light values.
- **OLED Display:** Real-time sensor readings displayed on a 128x64 OLED.
- **CSV Output:** UART output formatted for easy logging and analysis.
- **Python Visualization:** Plots sensor data over time with combined and separate graphs.
- **Resume-Ready:** Demonstrates skills in embedded systems, C programming, IoT, and Python data analysis.

---

## Hardware Required

- ESP32 Development Board  
- DHT22 Temperature & Humidity Sensor  
- Light Sensor (or simulated analog input)  
- SSD1306 OLED Display (128x64)  
- Connecting wires  
- USB cable for ESP32 programming

---

## Wiring Diagram

| Sensor/Device | ESP32 Pin |
|---------------|-----------|
| DHT22 Data    | GPIO4     |
| DHT22 VCC     | 3.3V      |
| DHT22 GND     | GND       |
| OLED SDA      | GPIO21    |
| OLED SCL      | GPIO22    |
| OLED VCC      | 3.3V      |
| OLED GND      | GND       |
| Light Sensor  | GPIO34    |

> **Note:** VCC for OLED can also use 5V if supported.

---

## Software Requirements

- Arduino IDE or PlatformIO for ESP32 programming  
- Python 3.x with libraries:
  - `pandas`
  - `matplotlib`
  - `seaborn`
  - `pyserial` (for live data logging from serial)

---

## Arduino Code

- Reads DHT22 and light sensor every 2 seconds.  
- Displays readings on OLED.  
- Prints CSV-formatted output to serial (UART).  
- Optionally can send data to ThingSpeak for IoT dashboard.  

**CSV Format Example:**
