# 🔥 GSM-Based Fire Alarm System

## 📌 Overview
This project is a GSM-based fire alarm system that detects smoke and temperature and sends SMS alerts using a GSM module.

## 🛠️ Components Used
- Arduino Uno
- MQ-2 Smoke Sensor
- Temperature Sensor (LM35 / DHT11)
- GSM Module (SIM800/SIM900)
- Buzzer
- LED
- 7805 Voltage Regulator
- 9V Battery

## 🔌 Circuit Description
- MQ-2 → Analog Pin A0
- Temperature Sensor → A1
- GSM TX → Arduino RX (Pin 0)
- GSM RX → Arduino TX (Pin 1)
- Buzzer → Pin 9
- LED → Pin 8

## ⚙️ Working
The system continuously monitors smoke and temperature levels.
If values exceed threshold:
- Buzzer and LED turn ON
- SMS alert is sent via GSM module

## 💻 Code
See `fire_alarm.ino`

## 👩‍💻 Author
Yugandhara Nikam (Team Leader)
