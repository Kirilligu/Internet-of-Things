#include <Wire.h>
int ADXL345 = 0x53;
int LED_PIN = 2;
float X_out, Y_out, Z_out; 

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D);
  Wire.write(8);
  Wire.endTransmission();
  delay(10);
}

void loop() {
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true);

  X_out = ( Wire.read()| Wire.read() << 8); // X-axis value
  X_out = X_out/256; //For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
  Y_out = ( Wire.read()| Wire.read() << 8); // Y-axis value
  Y_out = Y_out/256;
  Z_out = ( Wire.read()| Wire.read() << 8); // Z-axis value
  Z_out = Z_out/256;

  float zero_gravity = sqrt(X_out * X_out + Y_out * Y_out + Z_out * Z_out);
  Serial.print("Xa= "); Serial.print(X_out);
  Serial.print("   Ya= "); Serial.print(Y_out);
  Serial.print("   Za= "); Serial.print(Z_out);
  Serial.println(zero_gravity);
  if (zero_gravity < 0.1) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  
  delay(100);
}
