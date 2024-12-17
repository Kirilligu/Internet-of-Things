int latchPin = 5;       
int clockPin = 3;       
int dataPin = 7;        

bool digits[10][8] = {
  {0, 0, 1, 0, 0, 0, 1, 0},  
  {1, 0, 1, 0, 1, 1, 1, 1},  
  {0, 0, 1, 1, 0, 0, 0, 1},  
  {0, 0, 1, 0, 0, 1, 0, 1},  
  {1, 0, 1, 0, 1, 1, 0, 0},  
  {0, 1, 0, 0, 0, 1, 0, 0},  
  {0, 1, 0, 0, 0, 0, 0, 0},  
  {0, 0, 1, 0, 1, 1, 1, 1},  
  {0, 0, 1, 0, 0, 0, 0, 0},  
  {0, 0, 1, 0, 0, 1, 0, 0}   
};

int seconds = 0;  
int currentDigit = 0;  
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

void displayDigit(int digit) {
  if (digit < 0 || digit > 9) return;
  digitalWrite(latchPin, LOW);  
  for (int i = 7; i >= 0; i--) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, digits[digit][i]);
    digitalWrite(clockPin, HIGH);
  }
  digitalWrite(latchPin, HIGH);  
}

void loop() {
  displayDigit(seconds / 10);
  delay(1000);
  displayDigit(seconds % 10);
  delay(1000);
  seconds = (seconds + 1) % 60;

  if (Serial.available() > 0) {
    char input = Serial.read();
    if (input >= '0' && input <= '9') {
      seconds = input - '0';
    }
  }
}
