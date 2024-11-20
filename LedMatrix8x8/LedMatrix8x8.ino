int R[] = {2, 7, A5, 5, 13, A4, 12, A2};
int C[] = {6, 11, 10, 3, A3, 4, 8, 9};
const bool image[8][8] = {
  {0,0,1,1,1,1,0,0},
  {0,1,0,0,0,0,1,0},
  {1,0,1,0,0,1,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,1,0,0,1,0,1},
  {1,0,0,1,1,0,0,1},
  {0,1,0,0,0,0,1,0},
  {0,0,1,1,1,1,0,0}
};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(R[i], OUTPUT);
    pinMode(C[i], OUTPUT);
  }
}
void loop() {
  for (int row = 0; row < 8; row++) {
    digitalWrite(R[row], LOW);
    for (int col = 0; col < 8; col++) {
      digitalWrite(C[col], image[row][col] ? HIGH : LOW);
    }
    delay(2);
    digitalWrite(R[row], HIGH);
  }
}
