#define PHOTO_PIN A7
#define SET_PHOTO_READ 'p'

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0 && Serial.read() == SET_PHOTO_READ) {
    Serial.write(analogRead(PHOTO_PIN) / 4);
  }
}
