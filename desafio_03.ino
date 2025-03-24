// Ronaldo Luiz Dos Santos Soares
// Desafio 1

#include <Adafruit_LiquidCrystal.h>

int buzzerPin = 2;
int buttonPins[] = {9, 8, 7, 6, 5, 4, 3};
int ledPin = 13;
int frequencies[] = {264, 297, 330, 352, 396, 440, 495};
char* notes[] = {"DO", "RE", "MI", "FA", "SOL", "LA", "SI"};

Adafruit_LiquidCrystal lcd(0);

void setup() {
  pinMode(buzzerPin, OUTPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(ledPin, OUTPUT);
  noTone(buzzerPin);

  lcd.begin(16, 2);
  limpa();
}

void loop() {
  bool botaoPressionado = false;

  for (int i = 0; i < 7; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      botaoPressionado = true;
      led_on(i);
    }
  }

  if (!botaoPressionado) {
    lcd.setCursor(15, 1);
    lcd.print("d");
  }
}

// Função que limpa e gerencia todo o display
void limpa() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DO  RE  MI  FA");
  lcd.setCursor(0, 1);
  lcd.print("SOL LA  SI  LD ");
}

// Função que acende o LED e gerencia todas as ações do botão pressionado
void led_on(int noteIndex) {
  int coluna = (noteIndex < 4) ? noteIndex * 4 : (noteIndex - 4) * 4;
  int linha = (noteIndex < 4) ? 0 : 1;
  lcd.setCursor(coluna + 2, linha);
  lcd.print("x");

  lcd.setCursor(15, 1);
  lcd.print("l");

  tone(buzzerPin, frequencies[noteIndex], 200);
  digitalWrite(ledPin, HIGH);
  delay(200);

  lcd.setCursor(coluna + 2, linha);
  lcd.print(" ");
  digitalWrite(ledPin, LOW);
}
