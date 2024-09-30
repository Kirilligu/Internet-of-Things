#define photoresistor1 A0
#define photoresistor2 A1

#define LED1 9
#define LED2 8

int difference = 50;
unsigned long previousMillis = 0;
const long interval = 500;

bool led1State = LOW;
bool led2State = LOW;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pht1 = analogRead(photoresistor1);
  int pht2 = analogRead(photoresistor2);
  Serial.print("pht1: "); Serial.print(pht1); Serial.print(" | pht2: "); Serial.println(pht2);

  unsigned long currentMillis = millis();
  
  if (abs(pht1 - pht2) < difference) {
    digitalWrite(LED1, HIGH); 
    digitalWrite(LED2, HIGH);
  } else {
    bool isLdr1Brighter = pht1 < pht2;
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      led1State = isLdr1Brighter ? !led1State : LOW;
      led2State = !isLdr1Brighter ? !led2State : LOW;
      digitalWrite(LED1, led1State);
      digitalWrite(LED2, led2State);
    }
  }
}
