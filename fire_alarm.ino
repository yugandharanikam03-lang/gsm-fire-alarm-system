#include <SoftwareSerial.h>

SoftwareSerial gsm(7, 8); // RX, TX

int smokePin = A0;
int tempPin = A1;
int buzzer = 9;
int led = 10;

int smokeThreshold = 300;
int tempThreshold = 50;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
  gsm.begin(9600);

  delay(1000);
}

void loop() {
  int smokeValue = analogRead(smokePin);
  int tempValue = analogRead(tempPin);

  float temperature = tempValue * (5.0 / 1023.0) * 100;

  Serial.print("Smoke: ");
  Serial.print(smokeValue);
  Serial.print(" Temp: ");
  Serial.println(temperature);

  if (smokeValue > smokeThreshold || temperature > tempThreshold) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);

    sendSMS();
    delay(10000);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
  }

  delay(1000);
}

void sendSMS() {
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+91XXXXXXXXXX\""); // your number
  delay(1000);
  gsm.println("Fire Alert! Smoke or High Temperature Detected.");
  delay(100);
  gsm.write(26);
}
