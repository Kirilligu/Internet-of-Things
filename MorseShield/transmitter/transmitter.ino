
const int buttonPin = 2;     
String morseInput = "";      
String decodedWord = "";     
unsigned long lastPressTime = 0;  
unsigned long pressDuration = 0;   
unsigned long lastActionTime = 0;  
const unsigned long TU = 1000;   

      //паузы между символами буквами словами
const unsigned long pauseBetweenSymbols = TU; 
const unsigned long pauseBetweenLetters = 3 * TU; 
const unsigned long pauseBetweenWords = 7 * TU; 


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);   // внутренний подтягивающий резистор
  Serial.begin(9600);    
  Serial.println("Для ввода кода Морзе нажимайте кнопку");
}

void loop() {
  int buttonState = digitalRead(buttonPin);   // считывается состояние кнокпи

  if (buttonState == LOW) {
    if (lastPressTime == 0) {
        lastPressTime = millis(); /
    }
  } else {

    if (lastPressTime != 0) {
        pressDuration = millis() - lastPressTime;

        if (pressDuration >= TU && pressDuration < 1.5 * TU) {
            morseInput += ".";
            Serial.print(".");
        } else if (pressDuration >= 1.5 * TU) {
            morseInput += "-";
            Serial.print("-");
        }
       lastPressTime = 0; 
       lastActionTime = millis(); 
    }
  }


  // проверка времени с последнего декодирования 
  if(millis() - lastActionTime > pauseBetweenLetters && morseInput.length() > 0)
  {
    char decodedLetter = decodeMorse(morseInput);
      if (decodedLetter != '\0') {
          Serial.print(" Буква: ");
          Serial.println(decodedLetter);
          decodedWord += decodedLetter;
        }
        morseInput = "";
      lastActionTime = millis(); 

    }


  if(millis() - lastActionTime > pauseBetweenWords && decodedWord.length() > 0)
  {
    Serial.print(" Слово завершено: ");
    Serial.println(decodedWord);
    decodedWord = "";
    lastActionTime=millis(); 
  }

}

char decodeMorse(String morse) {
    const char *morseCodes[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
    const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 26; i++) {
        if (morse.equals(morseCodes[i])) {
            return letters[i];
        }
    }
    return '\0';
}
