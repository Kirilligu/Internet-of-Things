//Подключение светодиодов к UNO:
//A1 и A2 - передние фары(front lights)
//A3 и A4 - задние фары(rear lights)
const int FL1 = A1;
const int FL2 = A2;
const int RL1 = A3;
const int RL2 = A4;
void setup() {
  pinMode(FL1, OUTPUT);
  pinMode(FL2, OUTPUT);
  pinMode(RL1, OUTPUT);
  pinMode(RL2, OUTPUT);
  digitalWrite(FL1, HIGH);
  digitalWrite(FL2, HIGH);
  digitalWrite(RL1, HIGH);
  digitalWrite(RL2, HIGH);
}

void loop() {
}
