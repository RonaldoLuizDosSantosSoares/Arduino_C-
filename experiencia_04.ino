// testando sensor solar

#define EX_01

// 1 – Acrescente um buzzer a montagem. Modifique o programa para o led acender e o buzzer apitar

#ifdef EX_01

int ledPin = 13;     // LED no pino 13
int buzzerPin = 7;   // Buzzer no pino 7
int ldrPin = A0;     // Sensor LDR no pino analógico A0
int ldrValor = 0;    // Variável para armazenar o valor lido do LDR

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    ldrValor = analogRead(ldrPin);
    Serial.println(ldrValor);

    if (ldrValor >=500) {
        digitalWrite(ledPin, HIGH);
        tone(buzzerPin, 2000); // Aciona o buzzer
    } else {
        digitalWrite(ledPin, LOW);
        noTone(buzzerPin);     // Desativa o buzzer
    }

    delay(100);
}

#endif

// #define EX_02

// 2 – Acrescente mais 2 leds a montagem. Conforme a luminosidade diminui os leds vão acendendo progressivamente. O buzzer deve apitar quando o último led acender.

#ifdef EX_02

int ledPin1 = 13;     // Primeiro LED no pino 13
int ledPin2 = 12;     // Segundo LED no pino 12
int ledPin3 = 11;     // Terceiro LED no pino 11
int buzzerPin = 7;    // Buzzer no pino 7
int ldrPin = A0;      // Sensor LDR no pino analógico A0
int ldrValor = 0;

void setup() {
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    ldrValor = analogRead(ldrPin);
    Serial.println(ldrValor);

    if (ldrValor < 700) digitalWrite(ledPin1, HIGH); else digitalWrite(ledPin1, LOW);
    if (ldrValor < 500) digitalWrite(ledPin2, HIGH); else digitalWrite(ledPin2, LOW);
    if (ldrValor < 300) {
        digitalWrite(ledPin3, HIGH);
        tone(buzzerPin, 2000); // Aciona o buzzer
    } else {
        digitalWrite(ledPin3, LOW);
        noTone(buzzerPin);     // Desativa o buzzer
    }

    delay(100);
}

#endif

// #define EX_03

// 3- Transforme a leitura do sensor de luminosidade em uma função que retorna o valor lido.

#ifdef EX_03

int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;
int buzzerPin = 7;
int ldrPin = A0;

int lerLDR() {
    return analogRead(ldrPin);
}

void setup() {
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int ldrValor = lerLDR();
    Serial.println(ldrValor);

    if (ldrValor < 700) digitalWrite(ledPin1, HIGH); else digitalWrite(ledPin1, LOW);
    if (ldrValor < 500) digitalWrite(ledPin2, HIGH); else digitalWrite(ledPin2, LOW);
    if (ldrValor < 300) {
        digitalWrite(ledPin3, HIGH);
        tone(buzzerPin, 2000);
    } else {
        digitalWrite(ledPin3, LOW);
        noTone(buzzerPin);
    }

    delay(100);
}

#endif

// #define EX_04

// 4 – Transforme o controle de cada um dos led em uma função que recebe o valor lido.

#ifdef EX_04

int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;
int buzzerPin = 7;
int ldrPin = A0;

int lerLDR() {
    return analogRead(ldrPin);
}

void controlarLED1(int ldrValor) {
    digitalWrite(ledPin1, ldrValor < 700 ? HIGH : LOW);
}

void controlarLED2(int ldrValor) {
    digitalWrite(ledPin2, ldrValor < 500 ? HIGH : LOW);
}

void controlarLED3(int ldrValor) {
    digitalWrite(ledPin3, ldrValor < 300 ? HIGH : LOW);
}

void setup() {
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int ldrValor = lerLDR();
    Serial.println(ldrValor);

    controlarLED1(ldrValor);
    controlarLED2(ldrValor);
    controlarLED3(ldrValor);

    if (ldrValor < 300) {
        tone(buzzerPin, 2000);
    } else {
        noTone(buzzerPin);
    }

    delay(100);
}

#endif

// #define EX_05

// 5 – Transforme o controle do buzzer em uma função que recebe o valor lido

#ifdef EX_05

int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;
int buzzerPin = 7;
int ldrPin = A0;

int lerLDR() {
    return analogRead(ldrPin);
}

void controlarLED1(int ldrValor) {
    digitalWrite(ledPin1, ldrValor < 700 ? HIGH : LOW);
}

void controlarLED2(int ldrValor) {
    digitalWrite(ledPin2, ldrValor < 500 ? HIGH : LOW);
}

void controlarLED3(int ldrValor) {
    digitalWrite(ledPin3, ldrValor < 300 ? HIGH : LOW);
}

void controlarBuzzer(int ldrValor) {
    if (ldrValor < 300) {
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
    int ldrValor = lerLDR();
    Serial.println(ldrValor);

    controlarLED1(ldrValor);
    controlarLED2(ldrValor);
    controlarLED3(ldrValor);
    controlarBuzzer(ldrValor);

    delay(100);
}

#endif
