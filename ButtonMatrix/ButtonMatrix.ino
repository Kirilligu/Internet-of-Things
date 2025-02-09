#define NROWS 3
#define NCOLS 3

const int row_pins[NROWS] = {2, 3, 4};
const int col_pins[NCOLS] = {5, 6, 7};
bool btn_pressed[NROWS][NCOLS] = {false};  
int buttonState = 0;
int lastButtonState = 0;
unsigned long pressStartTime[NROWS][NCOLS] = {0}; 

void setup() {
  for (int i = 0; i < NROWS; i++) {
    pinMode(row_pins[i], OUTPUT);
  }
  for (int i = 0; i < NCOLS; i++) {
    pinMode(col_pins[i], INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  update_button_state();
  delay(50);
}

void update_button_state() {
  int newState = 0;
  for (int row = 0; row < NROWS; row++) {
    for (int i = 0; i < NROWS; i++) {
      digitalWrite(row_pins[i], HIGH);
    }
    digitalWrite(row_pins[row], LOW);  
    for (int col = 0; col < NCOLS; col++) {
      bool isPressed = !digitalRead(col_pins[col]);  
      if (isPressed && !btn_pressed[row][col]) {
        pressStartTime[row][col] = millis();
      } else if (!isPressed && btn_pressed[row][col]) {
        unsigned long duration = millis() - pressStartTime[row][col];
        Serial.print("duration of the button press ");
        Serial.print(col + NCOLS * row + 1);
        Serial.print(" - ");
        Serial.print(duration);
        Serial.print(" ms, beginning in ");
        Serial.print(pressStartTime[row][col]);
        Serial.println(" ms");
      }
      btn_pressed[row][col] = isPressed;
      if (isPressed) {
        newState |= (1 << (col + NCOLS * row));
      }
    }
  }
  if (newState != lastButtonState) {  
    printButtons(newState);
    lastButtonState = newState;
  }
}
void printButtons(int state) {
  if (state == 0) {
    Serial.println("No buttons pressed");
    return;
  }
  Serial.print("The buttons are pressed: ");
  for (int i = 0; i < 9; i++) {
    if (state & (1 << i)) {
      Serial.print(i + 1);
      Serial.print(" ");
    }
  }
  Serial.println();
}
