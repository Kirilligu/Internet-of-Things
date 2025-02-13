#define NROWS 3
#define NCOLS 3
#define SCAN_INTERVAL 10  

const int row_pins[NROWS] = {2, 3, 4};  
const int col_pins[NCOLS] = {5, 6, 7};  
bool btn_pressed[NROWS][NCOLS] = {false};  
unsigned long pressStartTime[NROWS][NCOLS] = {0};  

volatile int current_row = 0; 

bool btn_state[NROWS][NCOLS] = {false};  

int pressed_buttons[NCOLS * NROWS];  
int pressed_buttons_count = 0;  
bool buttons_changed = false;  

void setup() {
  for (int i = 0; i < NROWS; i++) {
    pinMode(row_pins[i], OUTPUT);
    digitalWrite(row_pins[i], HIGH);  
  }

  for (int i = 0; i < NCOLS; i++) {
    pinMode(col_pins[i], INPUT_PULLUP);
  }

  Serial.begin(9600);
  setupTimer();  
}

void loop() {
  delay(50);  

  if (buttons_changed) {
    print_pressed_buttons();
    buttons_changed = false;  
  }
}


void setupTimer() {
  cli();  

  TCCR1A = 0;  
  TCCR1B = 0;

  TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10);  
  OCR1A = (F_CPU / 64 / 1000) * SCAN_INTERVAL - 1;  

  TIMSK1 |= (1 << OCIE1A);  
  sei();  
}

ISR(TIMER1_COMPA_vect) {
  scanRow();
}

void scanRow() {
  for (int i = 0; i < NROWS; i++) {
    PORTD |= (1 << row_pins[i]);
  }
  
  PORTD &= ~(1 << row_pins[current_row]);
  update_button_state();  
  current_row = (current_row + 1) % NROWS;
}

void update_button_state() {
  uint8_t colState = PIND;  

  for (int col = 0; col < NCOLS; col++) {
    bool isPressed = !(colState & (1 << col_pins[col]));  

    if (isPressed && !btn_pressed[current_row][col]) {
      btn_pressed[current_row][col] = true;
      pressStartTime[current_row][col] = millis();
      btn_state[current_row][col] = true;  
      add_pressed_button(current_row, col);  
      buttons_changed = true;  
      Serial.print("Button ");
      Serial.print(current_row * NCOLS + col + 1);
      Serial.print(" pressed at ");
      Serial.print(pressStartTime[current_row][col]);
      Serial.println(" ms");
    } 
    else if (!isPressed && btn_pressed[current_row][col]) {
      btn_pressed[current_row][col] = false;
      unsigned long duration = millis() - pressStartTime[current_row][col];
      btn_state[current_row][col] = false;   
      remove_pressed_button(current_row, col);  
      buttons_changed = true;  
      Serial.print("Button ");
      Serial.print(current_row * NCOLS + col + 1);
      Serial.print(" held for ");
      Serial.print(duration);
      Serial.println(" ms");
    }
  }
}

void add_pressed_button(int row, int col) {
  if (pressed_buttons_count < NROWS * NCOLS) {
    int button_index = row * NCOLS + col;
    pressed_buttons[pressed_buttons_count] = button_index;  
    pressed_buttons_count++;  
  }
}

void remove_pressed_button(int row, int col) {
  int button_index = row * NCOLS + col;
  for (int i = 0; i < pressed_buttons_count; i++) {
    if (pressed_buttons[i] == button_index) {
      for (int j = i; j < pressed_buttons_count - 1; j++) {
        pressed_buttons[j] = pressed_buttons[j + 1];
      }
      pressed_buttons_count--;  
      break;
    }
  }
}

void print_pressed_buttons() {
  Serial.print("Pressed buttons: ");
  if (pressed_buttons_count == 0) {
    Serial.println("None");
  } else {
    for (int i = 0; i < pressed_buttons_count; i++) {
      Serial.print(pressed_buttons[i] + 1);  
      if (i < pressed_buttons_count - 1) {
        Serial.print(", ");
      }
    }
    Serial.println();
  }
}
