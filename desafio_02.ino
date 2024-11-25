#include <Adafruit_LiquidCrystal.h>

// Pinos
int ledPin1 = 13;
int ledPin2 = 11;
int ledPin3 = 10;
int buttonPin1 = 7;
int buttonPin2 = 6;
int potPin = A0;
int ldrPin = A1;
int tempPin = A2;
int buzzerPin = 8;

// LCD
Adafruit_LiquidCrystal lcd(0);

// Variáveis globais
int buttonState1 = 0;
int buttonState2 = 0;
int potValue = 0;
int ldrValue = 0;
int tempValue = 0;

// Funções
void setup() {
  // Inicializa os pinos
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Inicializa o LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("PT:    L1:  L2: ");
  lcd.setCursor(0, 1);
  lcd.print("TP:       LD      ");
}

void loop() {
  // Lê e calcula a temperatura
  tempValue = lerTemperatura();
  verificarBuzzer(tempValue);

  // Escreve o valor da temperatura no LCD
  exibirTemperatura(tempValue);

  // Lê o botão 1 e controla o LED no pino 13
  buttonState1 = digitalRead(buttonPin1);
  controlarLed1(buttonState1);

  // Lê o botão 2 e controla o LED no pino 11
  buttonState2 = digitalRead(buttonPin2);
  controlarLed2(buttonState2);

  // Lê o valor do LDR e exibe no LCD
  ldrValue = analogRead(ldrPin);
  exibirLdr(ldrValue);

  // Lê o valor do potenciômetro e calcula o valor do LED no pino 10
  potValue = analogRead(potPin);
  int ledBrightness = calcularPotenciometro(potValue);
  exibirPotenciometro(potValue);
  controlarLed3(ledBrightness);
}

// Função para ler a temperatura
int lerTemperatura() {
  int leitura = analogRead(tempPin);
  return map(leitura, 0, 1023, -40, 125); // Mapeia o valor para a faixa de -40 a 125 °C
}

// Função para verificar se o buzzer deve ser acionado
void verificarBuzzer(int temperatura) {
  if (temperatura > 30) {
    digitalWrite(buzzerPin, HIGH); // Ativa o buzzer se a temperatura for maior que 30°C
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}

// Função para exibir a temperatura no LCD
void exibirTemperatura(int temperatura) {
  lcd.setCursor(0, 0);
  lcd.print("TP: ");
  lcd.print(temperatura);
  lcd.print(" C");
}

// Função para controlar o LED no pino 13 com base no botão 1
void controlarLed1(int estadoBotao) {
  if (estadoBotao == HIGH) {
    digitalWrite(ledPin1, HIGH); // Liga o LED
    lcd.setCursor(0, 1);
    lcd.print("L1: ON ");
  } else {
    digitalWrite(ledPin1, LOW); // Desliga o LED
    lcd.setCursor(0, 1);
    lcd.print("L1: OFF");
  }
}

// Função para controlar o LED no pino 11 com base no botão 2
void controlarLed2(int estadoBotao) {
  if (estadoBotao == HIGH) {
    digitalWrite(ledPin2, HIGH); // Liga o LED
    lcd.setCursor(8, 1);
    lcd.print("L2: ON ");
  } else {
    digitalWrite(ledPin2, LOW); // Desliga o LED
    lcd.setCursor(8, 1);
    lcd.print("L2: OFF");
  }
}

// Função para exibir o valor do LDR no LCD
void exibirLdr(int valorLdr) {
  lcd.setCursor(0, 0);
  lcd.print("LD: ");
  lcd.print(valorLdr);
}

// Função para calcular e exibir o valor do potenciômetro
int calcularPotenciometro(int valor) {
  return map(valor, 0, 1023, 0, 255); // Mapeia o valor do potenciômetro para controlar o brilho
}

// Função para exibir o valor do potenciômetro no LCD
void exibirPotenciometro(int valor) {
  lcd.setCursor(8, 0);
  lcd.print("PT: ");
  lcd.print(valor);
}

// Função para controlar o LED no pino 10 com base no valor do potenciômetro
void controlarLed3(int brilho) {
  analogWrite(ledPin3, brilho); // Controla o brilho do LED com PWM
}
