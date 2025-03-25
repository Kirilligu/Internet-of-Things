#include <SoftwareSerial.h>

#define BT_TX_PIN 8
#define BT_RX_PIN 13
#define WHEEL1 7
#define SPEED1 6
#define WHEEL2 4
#define SPEED2 5

SoftwareSerial BTSerial(BT_TX_PIN, BT_RX_PIN);

void moveMotors(int dir1, int speed1, int dir2, int speed2) {
  digitalWrite(WHEEL1, dir1);
  analogWrite(SPEED1, speed1);
  digitalWrite(WHEEL2, dir2);
  analogWrite(SPEED2, speed2);
}

void stopMotors() {
  analogWrite(SPEED1, 0);
  analogWrite(SPEED2, 0);
}

void setup() {
  pinMode(WHEEL1, OUTPUT);
  pinMode(SPEED1, OUTPUT);
  pinMode(WHEEL2, OUTPUT);
  pinMode(SPEED2, OUTPUT);

  BTSerial.begin(9600);
  Serial.begin(9600);
  BTSerial.println("Bluetooth initialized!");
}

void loop() {
  if (BTSerial.available()) {
    int sig = BTSerial.read();
    Serial.println(sig);

    switch (sig) {
      case 48: stopMotors(); BTSerial.println("Stop"); break;
      case 70: moveMotors(HIGH, 200, HIGH, 200); BTSerial.println("Forward"); break;
      case 82: moveMotors(HIGH, 200, LOW, 200); BTSerial.println("Right"); break;
      case 76: moveMotors(LOW, 200, HIGH, 200); BTSerial.println("Left"); break;
      case 66: moveMotors(LOW, 200, LOW, 200); BTSerial.println("Backward"); break;
      case 83: BTSerial.println("Change params"); break;
      case 84: BTSerial.println("Save params"); break;
      case 88: BTSerial.println("Calibrate"); break;
      default: BTSerial.println("Unknown command"); break;
    }
  }
}
