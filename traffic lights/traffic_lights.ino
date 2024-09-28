int led_red = 2;
int led_yellow = 3;
int led_green = 4;

unsigned long previousMillisec = 0;
int currentState = 0;

int times[] = {10000, 2000, 1000, 7000, 1000};
int leds[][3] = {
    {LOW, LOW, HIGH},
    {LOW, LOW, HIGH},
    {LOW, HIGH, LOW},
    {HIGH, LOW, LOW},
    {LOW, HIGH, LOW}
};

enum Mode {AUTO, MANUAL_GREEN, MANUAL_RED, TRANSITION_GREEN, TRANSITION_RED};
Mode currentMode = AUTO;
unsigned long manualStartMillis = 0;

void setup() {
    pinMode(led_red, OUTPUT);
    pinMode(led_yellow, OUTPUT);
    pinMode(led_green, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    unsigned long currentMillisec = millis();
    if (currentMode != AUTO && (currentMillisec - manualStartMillis >= 60000)) {
        currentMode = AUTO;
        currentState = 0;
        previousMillisec = currentMillisec;
    }
    if (currentMode == AUTO) {
        if (currentMillisec - previousMillisec >= times[currentState]) {
            previousMillisec = currentMillisec;
            currentState = (currentState + 1) % 5;
        }
        if (currentState == 1 && (currentMillisec - previousMillisec) % 500 < 250) {
            Led(led_green, LOW);
        } else {
            Led(led_red, leds[currentState][0]);
            Led(led_yellow, leds[currentState][1]);
            Led(led_green, leds[currentState][2]);
        }
    } else if (currentMode == TRANSITION_GREEN || currentMode == TRANSITION_RED) {
        if (currentMillisec - previousMillisec < 3000) {
            Led(led_yellow, HIGH);
        } else {
            Led(led_yellow, LOW);
            if (currentMode == TRANSITION_GREEN) {
                currentMode = MANUAL_GREEN;
            } else if (currentMode == TRANSITION_RED) {
                currentMode = MANUAL_RED;
            }
            previousMillisec = currentMillisec;
        }
    } else {
        if (currentMode == MANUAL_GREEN) {
            Led(led_red, LOW);
            Led(led_yellow, LOW);
            Led(led_green, HIGH);
        } else if (currentMode == MANUAL_RED) {
            Led(led_red, HIGH);
            Led(led_yellow, LOW);
            Led(led_green, LOW);
        }
    }

    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n');
        processCommand(command);
    }
}

void processCommand(String command) {
    if (command == "manual") {
        currentMode = TRANSITION_GREEN;
        previousMillisec = millis();
    } else if (command == "red") {
        currentMode = TRANSITION_RED;
        manualStartMillis = millis();
        previousMillisec = millis();
    } else if (command == "green") {
        currentMode = TRANSITION_GREEN;
        manualStartMillis = millis();
        previousMillisec = millis();
    }
}
void Led(uint8_t pin, byte status) {
    digitalWrite(pin, status);
}
