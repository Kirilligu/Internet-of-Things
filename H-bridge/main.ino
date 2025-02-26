#define pin_0 3
#define pin_1 5

void setup() {
  Serial.begin(9600);
  pinMode(pin_0, OUTPUT);
  pinMode(pin_1, OUTPUT);
  randomSeed(analogRead(0));
}

void switch_motor(bool vector = 0, int speed = 255){
  if (vector){
    analogWrite(pin_0, speed);
    analogWrite(pin_1, 0);
  }
  else {
    analogWrite(pin_0, 0);
    analogWrite(pin_1, speed);
  }
}

void loop() {
  int forward_speed = random(100, 256);
  switch_motor(1, forward_speed);
  delay(2000);

  int backward_speed = random(100, 256);
  switch_motor(0, backward_speed);
  delay(2000);
}
