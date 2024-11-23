int R[] = {2, 7, A5, 5, 13, A4, 12, A2};
int C[] = {6, 11, 10, 3, A3, 4, 8, 9};

const bool image1[8][8] = {
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0}
};

const bool image2[8][8] = {
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0}
};

const bool (*currentImage)[8] = image1;
const uint16_t frameDelay = 1000;
const uint8_t rowDelay = 2;
uint8_t currentRow = 0;
uint32_t imageSwitchTimer = 0;

void initPins() {
  for (int i = 0; i < 8; i++) {
    if (R[i] <= 7) DDRD |= (1 << R[i]);
    else if (R[i] <= 13) DDRB |= (1 << (R[i] - 8));
    else DDRC |= (1 << (R[i] - A0));
    if (C[i] <= 7) DDRD |= (1 << C[i]);
    else if (C[i] <= 13) DDRB |= (1 << (C[i] - 8));
    else DDRC |= (1 << (C[i] - A0));
  }
}
void setPin(uint8_t pin, bool state) {
  if (pin <= 7) {
    if (state) PORTD |= (1 << pin);
    else PORTD &= ~(1 << pin);
  } else if (pin <= 13) {
    if (state) PORTB |= (1 << (pin - 8));
    else PORTB &= ~(1 << (pin - 8));
  } else {
    if (state) PORTC |= (1 << (pin - A0));
    else PORTC &= ~(1 << (pin - A0));
  }
}
void updateRow() {
  for (int i = 0; i < 8; i++) {
    setPin(R[i], i == currentRow ? 0 : 1);
    setPin(C[i], currentImage[currentRow][i]);
  }
  currentRow = (currentRow + 1) % 8;
}
void initTimer() {
  TCCR1A = 0;
  TCCR1B = (1 << WGM12) | (1 << CS11);
  OCR1A = (F_CPU / 8 / 1000) * rowDelay;
  TIMSK1 |= (1 << OCIE1A);
}
ISR(TIMER1_COMPA_vect) {
  updateRow();
  if ((imageSwitchTimer += rowDelay) >= frameDelay) {
    currentImage = (currentImage == image1) ? image2 : image1;
    imageSwitchTimer = 0;
  }
}
void setup() {
  initPins();
  initTimer();
  sei();
}
void loop() {
  
}
