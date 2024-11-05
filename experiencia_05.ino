//Sensor de temperatura usando o LM35

// #define EX_01

// 1 – Acrescente um buzzer a montagem. Modifique o programa para o led acender e o buzzer apitar.

#ifdef EX_01

int LM35 = A0;       // Define o pino que lê a saída do LM35
float temperatura;   // Variável que armazena a temperatura medida
int ledPin = 13;     // LED no pino 13
int buzzerPin = 10;   // Buzzer no pino 7

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    temperatura = (((analogRead(LM35) * 5.0) / 1023) * 1000 - 500) / 10;
    Serial.print("Temperatura: ");
    Serial.println(temperatura);

    if (temperatura >= 30) {
        digitalWrite(ledPin, HIGH);
        tone(buzzerPin, 2000); // Apita o buzzer
    } else {
        digitalWrite(ledPin, LOW);
        noTone(buzzerPin);     // Desliga o buzzer
    }

    delay(3000);
}

#endif

// #define EX_02

// 2 – Acrescente mais 2 leds a montagem. Conforme a temperatura aumenta os leds vão acendendo progressivamente. O buzzer deve apitar quando o último led acender.

#ifdef EX_02

int LM35 = A0;
float temperatura;
int ledPin1 = 13;     // Primeiro LED no pino 13
int ledPin2 = 12;     // Segundo LED no pino 12
int ledPin3 = 11;     // Terceiro LED no pino 11
int buzzerPin = 10;

void setup() {
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    temperatura = (((analogRead(LM35) * 5.0) / 1023) * 1000 - 500) / 10;
    Serial.print("Temperatura: ");
    Serial.println(temperatura);

    digitalWrite(ledPin1, temperatura >= 30 ? HIGH : LOW);
    digitalWrite(ledPin2, temperatura >= 35 ? HIGH : LOW);
    if (temperatura >= 40) {
        digitalWrite(ledPin3, HIGH);
        tone(buzzerPin, 2000);
    } else {
        digitalWrite(ledPin3, LOW);
        noTone(buzzerPin);
    }

    delay(3000);
}

#endif

// #define EX_03

// 3- Transforme a leitura do sensor de temperatura em uma função que retorna o valor lido.

#ifdef EX_03

int LM35 = A0;
float temperatura;
int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;
int buzzerPin = 10;

float lerTemperatura() {
    return (((analogRead(LM35) * 5.0) / 1023) * 1000 - 500) / 10;
}

void setup() {
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    temperatura = lerTemperatura();
    Serial.print("Temperatura: ");
    Serial.println(temperatura);

    digitalWrite(ledPin1, temperatura >= 30 ? HIGH : LOW);
    digitalWrite(ledPin2, temperatura >= 35 ? HIGH : LOW);
    if (temperatura >= 40) {
        digitalWrite(ledPin3, HIGH);
        tone(buzzerPin, 2000);
    } else {
        digitalWrite(ledPin3, LOW);
        noTone(buzzerPin);
    }

    delay(3000);
}

#endif

// #define EX_04

// 4 – Transforme o controle de cada um dos led em uma função que recebe o valor lido.

#ifdef EX_04

int LM35 = A0;
float temperatura;
int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;
int buzzerPin = 10;

float lerTemperatura() {
    return (((analogRead(LM35) * 5.0) / 1023) * 1000 - 500) / 10;
}

void controlarLED1(float temperatura) {
    digitalWrite(ledPin1, temperatura >= 30 ? HIGH : LOW);
}

void controlarLED2(float temperatura) {
    digitalWrite(ledPin2, temperatura >= 35 ? HIGH : LOW);
}

void controlarLED3(float temperatura) {
    digitalWrite(ledPin3, temperatura >= 40 ? HIGH : LOW);
}

void setup() {
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    temperatura = lerTemperatura();
    Serial.print("Temperatura: ");
    Serial.println(temperatura);

    controlarLED1(temperatura);
    controlarLED2(temperatura);
    controlarLED3(temperatura);

    if (temperatura >= 40) {
        tone(buzzerPin, 2000);
    } else {
        noTone(buzzerPin);
    }

    delay(3000);
}

#endif

#define EX_05

// 5 – Transforme o controle do buzzer em uma função que recebe o valor lido.

#ifdef EX_05

int LM35 = A0;
float temperatura;
int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;
int buzzerPin = 10;

float lerTemperatura() {
    return (((analogRead(LM35) * 5.0) / 1023) * 1000 - 500) / 10;
}

void controlarLED1(float temperatura) {
    digitalWrite(ledPin1, temperatura >= 30 ? HIGH : LOW);
}

void controlarLED2(float temperatura) {
    digitalWrite(ledPin2, temperatura >= 35 ? HIGH : LOW);
}

void controlarLED3(float temperatura) {
    digitalWrite(ledPin3, temperatura >= 40 ? HIGH : LOW);
}

void controlarBuzzer(float temperatura) {
    if (temperatura >= 40) {
        tone(buzzerPin, 2000);
    } else {
        noTone(buzzerPin);
    }
}

void setup() {
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    temperatura = lerTemperatura();
    Serial.print("Temperatura: ");
    Serial.println(temperatura);

    controlarLED1(temperatura);
    controlarLED2(temperatura);
    controlarLED3(temperatura);
    controlarBuzzer(temperatura);

    delay(3000);
}

#endif
