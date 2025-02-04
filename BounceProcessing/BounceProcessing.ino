#define BUTTON_PIN 2 
#define BOUNCE_TIME 50
#define PRESSED HIGH

volatile long int press_time = 0;
volatile bool pressed_candidate = false;
volatile long int hold_time = 0;
volatile int press_count = 0;
volatile bool report_to_user = false;
bool button_pressed = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), process_button_click, CHANGE);
}

void loop() {
  if (report_to_user) {
    Serial.print("Press count: ");
    Serial.println(press_count);
    Serial.print("Hold time: ");
    Serial.println(hold_time);
    report_to_user = false;
  }
}

void process_button_click() {
  static long int last_interrupt_time = 0;
  long int interrupt_time = millis();

  if (interrupt_time - last_interrupt_time < BOUNCE_TIME) {
    return;
  }
  last_interrupt_time = interrupt_time;

  if (digitalRead(BUTTON_PIN) == PRESSED) {
    if (!pressed_candidate) {
      press_time = interrupt_time;
      pressed_candidate = true;
    }
  } else {
    if (pressed_candidate) {
      hold_time = interrupt_time - press_time;
      press_count++;
      pressed_candidate = false;
      report_to_user = true;
    }
  }
}
