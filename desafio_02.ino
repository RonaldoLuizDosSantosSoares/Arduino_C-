#include <Adafruit_LiquidCrystal.h>

// Pinos
int ledPin1 = 13;
int ledPin2 = 11;
int ledPin3 = 10;
int buttonPin1 = 7;
int buttonPin2 = 6;
int potPin = A2;  // Potenciômetro no pino A2
int tempPin = A1; // Sensor de temperatura no pino A1
int buzzerPin = 8; // Buzzer no pino 8

// LCD
Adafruit_LiquidCrystal lcd(0);

// Variáveis globais
int buttonState1 = 0;
int buttonState2 = 0;
int potValue = 0;
int tempValue = 0;
int ldrValue = 0; // Valor do LDR

// Funções
void setup() {
  // Inicializa os pinos
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);  // Ativa o resistor de pull-up interno
  pinMode(buttonPin2, INPUT_PULLUP);  // Ativa o resistor de pull-up interno
  pinMode(buzzerPin, OUTPUT);

  // Inicializa o LCD
  lcd.begin(16, 2);  // LCD de 16 colunas por 2 linhas
}

void loop() {
  // Lê e calcula a temperatura
  tempValue = lerTemperatura();
  verificarBuzzer(tempValue);  // Decide se o buzzer deve ser ligado

  // Lê o valor do LDR
  ldrValue = analogRead(A0); // LDR no pino A0
  ldrValue = map(ldrValue, 0, 1023, 0, 100); // Mapeia para uma faixa de 0 a 100

  // Escreve o valor do LCD na primeira linha
  exibirValoresLCD();

  // Lê o botão 1 e controla o LED no pino 13
  buttonState1 = digitalRead(buttonPin1);
  controlarLed1(buttonState1);

  // Lê o botão 2 e controla o LED no pino 11
  buttonState2 = digitalRead(buttonPin2);
  controlarLed2(buttonState2);

  // Lê o valor do potenciômetro e calcula o valor do LED no pino 10
  potValue = analogRead(potPin);
  int ledBrightness = calcularPotenciometro(potValue);
  exibirPotenciometro(potValue);
  controlarLed3(ledBrightness);
}

// Função para ler a temperatura (Agora no pino A1)
int lerTemperatura() {
  int leitura = analogRead(tempPin);
  return map(leitura, 0, 1023, -40, 125); // Mapeia o valor para a faixa de -40 a 125 °C
}

// Função para verificar se o buzzer deve ser acionado
void verificarBuzzer(int temperatura) {
  if (temperatura < 5) { // Ativa o buzzer se a temperatura for menor que 5°C
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW); // Desliga o buzzer se a temperatura for maior que 5°C
  }
}

// Função para exibir os valores no LCD
void exibirValoresLCD() {
  lcd.setCursor(0, 0);  // Primeira linha
  lcd.print("PT:");  // Exibe o valor do potenciômetro
  lcd.print(potValue);
  lcd.print(" L1:");  // Exibe o estado do LED 1 com A para Aceso e D para Desligado
  lcd.print(digitalRead(ledPin1) == HIGH ? "A" : "D");
  lcd.print(" L2:");  // Exibe o estado do LED 2 com A para Aceso e D para Desligado
  lcd.print(digitalRead(ledPin2) == HIGH ? "A" : "D");

  lcd.setCursor(0, 1);  // Segunda linha
  lcd.print("TP:");  // Exibe a temperatura
  lcd.print(tempValue);
  lcd.print("C"); // Adiciona espaço para limpar a tela
  lcd.print(" LD");  // Exibe o valor do LDR
  lcd.print(ldrValue);
}

// Função para controlar o LED no pino 13 com base no botão 1
void controlarLed1(int estadoBotao) {
  if (estadoBotao == LOW) {  // Botão pressionado
    digitalWrite(ledPin1, HIGH); // Liga o LED
  } else {
    digitalWrite(ledPin1, LOW); // Desliga o LED
  }
}

// Função para controlar o LED no pino 11 com base no botão 2
void controlarLed2(int estadoBotao) {
  if (estadoBotao == LOW) {  // Botão pressionado
    digitalWrite(ledPin2, HIGH); // Liga o LED
  } else {
    digitalWrite(ledPin2, LOW); // Desliga o LED
  }
}

// Função para calcular e exibir o valor do potenciômetro
int calcularPotenciometro(int valor) {
  return map(valor, 0, 1023, 0, 255); // Mapeia o valor do potenciômetro para controlar o brilho
}

// Função para exibir o valor do potenciômetro no LCD
void exibirPotenciometro(int valor) {
  analogWrite(ledPin3, calcularPotenciometro(valor)); // Controla o brilho do LED com PWM
}

// Função para controlar o LED no pino 10 com base no valor do potenciômetro
void controlarLed3(int brilho) {
  analogWrite(ledPin3, brilho); // Controla o brilho do LED com PWM
}

