#define trig 12
#define echo 11
#define inf 0

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
void loop() {
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  if (distance >= 400 || distance <= 0) {
    distance = inf;
  }
  Serial.print("Расстояние: ");
  Serial.print(distance);
  Serial.println(" см");
  delay(500);
}
