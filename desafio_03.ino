// Ronaldo Luiz Dos Santos Soares 
// Desafio 1
  
#include <Adafruit_LiquidCrystal.h>

// Pinos
int buzzerPin = 2;
int buttonPins[] = {9, 8, 7, 6, 5, 4, 3};
int ledPin = 13;
int frequencies[] = {264, 297, 330, 352, 396, 440, 495}; // Frequências das notas musicais
char* notes[] = {"DO", "RE", "MI", "FA", "SOL", "LA", "SI"}; // Nomes das notas

// LCD
Adafruit_LiquidCrystal lcd(0);

void setup() {
  // Configura os pinos
  pinMode(buzzerPin, OUTPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(ledPin, OUTPUT);
  noTone(buzzerPin);

  // Inicializa o LCD
  lcd.begin(16, 2);

  // Exibe todas as notas no LCD
  exibirNotasNoLCD();
  exibirEstadoLED(false); // Inicia com o LED desligado ("LD d")
}

void loop() {
  bool botaoPressionado = false;

  // Verifica o estado de cada botão
  for (int i = 0; i < 7; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      botaoPressionado = true;
      exibirXNaNota(i);
      tone(buzzerPin, frequencies[i], 200);
      exibirEstadoLED(true);
      led_on();
      delay(200);
      limpaXDaNota(i);
    }
  }

  // Se nenhum botão foi pressionado, mantém o LED desligado
  if (!botaoPressionado) {
    exibirEstadoLED(false);
  }
}

// Função para exibir todas as notas no LCD
void exibirNotasNoLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DO  RE  MI  FA");
  lcd.setCursor(0, 1);
  lcd.print("SOL LA  SI  LD d");
}

// Função para exibir "x" na nota correspondente
void exibirXNaNota(int noteIndex) {
  int coluna = 0;
  int linha = 0;

  // Calcula a posição do "x" com base no índice da nota
  if (noteIndex < 4) { // Notas na primeira linha (DO, RE, MI, FA)
    coluna = noteIndex * 4; // Cada nota ocupa 4 colunas
    linha = 0;
  } else { // Notas na segunda linha (SOL, LA, SI)
    coluna = (noteIndex - 4) * 4; // Cada nota ocupa 4 colunas
    linha = 1;
  }

  lcd.setCursor(coluna + 2, linha); // Posiciona o cursor ao lado do nome da nota
  lcd.print("x"); // Escreve "x" ao lado da nota
}

// Função para remover o "x" da nota correspondente
void limpaXDaNota(int noteIndex) {
  int coluna = 0;
  int linha = 0;

  // Calcula a posição do "x" com base no índice da nota
  if (noteIndex < 4) {
    coluna = noteIndex * 4;
    linha = 0;
  } else {
    coluna = (noteIndex - 4) * 4;
    linha = 1;
  }

  lcd.setCursor(coluna + 2, linha); // Posiciona o cursor ao lado do nome da nota
  lcd.print(" "); // Remove o "x" da nota
}

// Função para exibir o estado do LED
void exibirEstadoLED(bool estadoLED) {
  lcd.setCursor(12, 1); // Posiciona o cursor na posição do "LD"
  if (estadoLED) {
    lcd.print("LD l"); // LED ligado
  } else {
    lcd.print("LD d"); // LED desligado
  }
}

// Função para acender e apagar o LED
void led_on() {
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
}
