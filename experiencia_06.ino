//Potenciometro

// #define EX_01

// 1- Monte mais 1 led e modifique o programa para que os 2 leds sejam controlados pelo potenciômetro.


#ifdef EX_01

// Daremos um nome ao pino que está conectado o LED

int ledPin = 11;
int ledPin2 = 10;
int pwmPin = A0;

unsigned int valorLido;
unsigned int pwm;

//Função "setup" roda uma vez quando a placa e ligada ou resetada

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
Serial.begin(9600);
}

// Função que se repete infinitamente quando a placa é ligada

void loop()
{
valorLido = analogRead(pwmPin); // valor entre 0 e 1023
//mostra o valor lido na porta analógica
Serial.println(valorLido);
pwm = map(valorLido, 0, 1023, 0, 255); // Mudança de escala
analogWrite(ledPin,pwm);
analogWrite(ledPin2,pwm); //Escreve no led um sinal PWM proporcional ao valor Lido
}

#endif

// #define EX_02

// 2 – Modifique o programa para que os leds funcionem invertidos. Com a variação do potenciômetro 1 led vai acendendo e outro led vai apagando.


#ifdef EX_02

int ledPin = 11;
int ledPin2 = 10;
int pwmPin = A0;

unsigned int valorLido;
unsigned int pwm;

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
Serial.begin(9600);
}

void loop()
{
valorLido = analogRead(pwmPin);
Serial.println(valorLido);
pwm = map(valorLido, 0, 1023, 0, 255);
analogWrite(ledPin,pwm);
analogWrite(ledPin2, 255 - pwm);

}

#endif

// #define EX_03

// 3- Monte mais 1 led. Conforme o potenciômetro vai variando, os leds vão acendendo progressivamente.

#ifdef EX_03

int ledPin = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int pwmPin = A0;

unsigned int valorLido;
unsigned int pwm;

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
Serial.begin(9600);
}

void loop()
{
valorLido = analogRead(pwmPin);
Serial.println(valorLido);
pwm = map(valorLido, 0, 1023, 0, 255);
  
// Controle dos LEDs progressivamente
  
  if (pwm < 85) {
    
    // Acende apenas o LED 1
    
    analogWrite(ledPin, pwm * 3); // Aumenta a intensidade do LED 1
    
    analogWrite(ledPin2, 0); // Mantém o LED 2 apagado analog
    
    analogWrite(ledPin3, 0); // Mantém o LED 3 apagado

  
  } 

else if (pwm < 170)

{
  
  // Acende o LED 1 totalmente e começa a acender o LED 2
  
  analogWrite(ledPin, 255);  // LED 1 totalmente aceso 
  
  analogWrite(ledPin2, (pwm - 85) * 3); // Aumenta a intensidade do LED 2 
  
  analogWrite(ledPin3, 0); // Mantém o LED 3 apagado

}
  else
  { 
    // Acende os três LEDs progressivamente
    
    analogWrite(ledPin, 255);  // LED 1 totalmente aceso 
    
    analogWrite(ledPin2, 255); // LED 2 totalmente aceso 
    
    analogWrite(ledPin3, (pwm - 170) * 3); // Aumenta a intensidade do LED 3
  
  }

}

#endif

// #define EX_04

// 4 – Monte o buzzer e quando o último led acender apite o buzzer junto.

#ifdef EX_04

int ledPin = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int buzzerPin = 7;
int pwmPin = A0;

unsigned int valorLido;
unsigned int pwm;

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

void loop()
{
valorLido = analogRead(pwmPin);
Serial.println(valorLido);
pwm = map(valorLido, 0, 1023, 0, 255);
  
// Controle dos LEDs progressivamente
  
  if (pwm < 85) {
    
    // Acende apenas o LED 1
    
    analogWrite(ledPin, pwm * 3); // Aumenta a intensidade do LED 1
    
    analogWrite(ledPin2, 0); // Mantém o LED 2 apagado analog
    
    analogWrite(ledPin3, 0); // Mantém o LED 3 apagado

  
  } 

else if (pwm < 170)

{
  
  // Acende o LED 1 totalmente e começa a acender o LED 2
  
  analogWrite(ledPin, 255);  // LED 1 totalmente aceso 
  
  analogWrite(ledPin2, (pwm - 85) * 3); // Aumenta a intensidade do LED 2 
  
  analogWrite(ledPin3, 0); // Mantém o LED 3 apagado
  noTone(buzzerPin);

}
  else
  { 
    // Acende os três LEDs progressivamente
    
    analogWrite(ledPin, 255);  // LED 1 totalmente aceso 
    
    analogWrite(ledPin2, 255); // LED 2 totalmente aceso 
    
    analogWrite(ledPin3, (pwm - 170) * 3); // Aumenta a intensidade do LED 3
    tone(buzzerPin, 1000);
  }

}

#endif

// #define EX_05

// 5 – Transforme a leitura do potenciômetro em uma função.

#ifdef EX_05

int ledPin = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int buzzerPin = 7;
int pwmPin = A0;

unsigned int valorLido;
unsigned int pwm;

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

int lerPotenciometro()
{
  return analogRead(pwmPin);
}  

void loop()
{
valorLido = lerPotenciometro();
Serial.println(valorLido);
pwm = map(valorLido, 0, 1023, 0, 255);

// Controle dos LEDs progressivamente
  
  if (pwm < 85) {
    
    // Acende apenas o LED 1
    
    analogWrite(ledPin, pwm * 3); // Aumenta a intensidade do LED 1
    
    analogWrite(ledPin2, 0); // Mantém o LED 2 apagado analog
    
    analogWrite(ledPin3, 0); // Mantém o LED 3 apagado

  
  } 

else if (pwm < 170)

{
  
  // Acende o LED 1 totalmente e começa a acender o LED 2
  
  analogWrite(ledPin, 255);  // LED 1 totalmente aceso 
  
  analogWrite(ledPin2, (pwm - 85) * 3); // Aumenta a intensidade do LED 2 
  
  analogWrite(ledPin3, 0); // Mantém o LED 3 apagado
  noTone(buzzerPin);

}
  else
  { 
    // Acende os três LEDs progressivamente
    
    analogWrite(ledPin, 255);  // LED 1 totalmente aceso 
    
    analogWrite(ledPin2, 255); // LED 2 totalmente aceso 
    
    analogWrite(ledPin3, (pwm - 170) * 3); // Aumenta a intensidade do LED 3
    tone(buzzerPin, 1000);
  }

}

#endif

// #define EX_06

#ifdef EX_06

// 6 – Transforme a mudança de escala (cálculo) em uma função.

int ledPin = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int buzzerPin = 7;
int pwmPin = A0;

unsigned int valorLido;
unsigned int pwm;

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

int lerPotenciometro()
{
  return analogRead(pwmPin);
}

int mudancaEscala(int valorLido)
{
  return map(valorLido, 0, 1023, 0, 255);
}

void loop()
{
valorLido = lerPotenciometro();
Serial.println(valorLido);
pwm = mudancaEscala(valorLido);

// Controle dos LEDs progressivamente
  
  if (pwm < 85) {
    
    // Acende apenas o LED 1
    
    analogWrite(ledPin, pwm * 3); // Aumenta a intensidade do LED 1
    
    analogWrite(ledPin2, 0); // Mantém o LED 2 apagado analog
    
    analogWrite(ledPin3, 0); // Mantém o LED 3 apagado

  
  } 

else if (pwm < 170)

{
  
  // Acende o LED 1 totalmente e começa a acender o LED 2
  
  analogWrite(ledPin, 255);  // LED 1 totalmente aceso 
  
  analogWrite(ledPin2, (pwm - 85) * 3); // Aumenta a intensidade do LED 2 
  
  analogWrite(ledPin3, 0); // Mantém o LED 3 apagado
  noTone(buzzerPin);

}
  else
  { 
    // Acende os três LEDs progressivamente
    
    analogWrite(ledPin, 255);  // LED 1 totalmente aceso 
    
    analogWrite(ledPin2, 255); // LED 2 totalmente aceso 
    
    analogWrite(ledPin3, (pwm - 170) * 3); // Aumenta a intensidade do LED 3
    tone(buzzerPin, 1000);
  }

}

#endif

// #define EX_07

#ifdef EX_07

// 7 – Transforme o controle de cada um dos led em uma função.

int ledPin = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int buzzerPin = 7;
int pwmPin = A0;

unsigned int valorLido;
unsigned int pwm;

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

// Potenciometro e calculo

int lerPotenciometro()
{
  return analogRead(pwmPin);
}

int mudancaEscala(int valorLido)
{
  return map(valorLido, 0, 1023, 0, 255);
}

// Funções dos LEDs

void controlarLed1(int intensidade)
{
  analogWrite(ledPin, intensidade);
}

void controlarLed2(int intensidade)
{
  analogWrite(ledPin2, intensidade);
}

void controlarLed3(int intensidade)
{
  analogWrite(ledPin3, intensidade);
}
  
void loop()
{
valorLido = lerPotenciometro();
Serial.println(valorLido);
pwm = mudancaEscala(valorLido);

// Controle dos LEDs progressivamente
 
if (pwm < 85) {
  
  controlarLed1(pwm * 3); // LED 1 totalmente aceso
  controlarLed2(0); // Aumenta a intensidade do LED 2
  controlarLed3(0); // Mantém o LED 3 apagado
  noTone(buzzerPin);
  
}

else if (pwm < 170)

{
  
  controlarLed1(255); // LED 1 totalmente aceso
  controlarLed2((pwm - 85) * 3); // Aumenta a intensidade do LED 2
  controlarLed3(0); // Mantém o LED 3 apagado
  noTone(buzzerPin);
  
}

else
  { 
  controlarLed1(255); // LED 1 totalmente aceso
  controlarLed2(255); // LED 2 totalmente aceso
  controlarLed3((pwm - 170) * 3); // Aumenta a intensidade do LED 3
  tone(buzzerPin, 1000);
  
}
  
}
  
#endif

#define EX_08

#ifdef EX_08

// 8 – Transforme o controle do buzzer em uma função.

int ledPin = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int buzzerPin = 7;
int pwmPin = A0;

unsigned int valorLido;
unsigned int pwm;

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

// Potenciometro e calculo

int lerPotenciometro()
{
  return analogRead(pwmPin);
}

int mudancaEscala(int valorLido)
{
  return map(valorLido, 0, 1023, 0, 255);
}

// Funções dos LEDs

void controlarLed1(int intensidade)
{
  analogWrite(ledPin, intensidade);
}

void controlarLed2(int intensidade)
{
  analogWrite(ledPin2, intensidade);
}

void controlarLed3(int intensidade)
{
  analogWrite(ledPin3, intensidade);
}

// Função do buzzer

void controlarBuzzer(bool ligado)
{
  
  if(ligado){
tone(buzzerPin, 1000); // liga
}
  else{
noTone(buzzerPin); // desliga
}
  
}
  
void loop()
{
valorLido = lerPotenciometro();
Serial.println(valorLido);
pwm = mudancaEscala(valorLido);

// Controle dos LEDs progressivamente
 
if (pwm < 85) {
  
  controlarLed1(pwm * 3); // LED 1 totalmente aceso
  controlarLed2(0); // Aumenta a intensidade do LED 2
  controlarLed3(0); // Mantém o LED 3 apagado
  controlarBuzzer(false);
  
}

else if (pwm < 170)

{
  
  controlarLed1(255); // LED 1 totalmente aceso
  controlarLed2((pwm - 85) * 3); // Aumenta a intensidade do LED 2
  controlarLed3(0); // Mantém o LED 3 apagado
  controlarBuzzer(false);
  
}

else
  { 
  controlarLed1(255); // LED 1 totalmente aceso
  controlarLed2(255); // LED 2 totalmente aceso
  controlarLed3((pwm - 170) * 3); // Aumenta a intensidade do LED 3
  controlarBuzzer(true);
  
}
  
}

#endif

// #define EX_09

#ifdef EX_09

// 9 – Transforme a escrita no led em uma função.

int ledPin = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int buzzerPin = 7;
int pwmPin = A0;

unsigned int valorLido;
unsigned int pwm;

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

// Potenciometro e calculo

int lerPotenciometro()
{
  return analogRead(pwmPin);
}

int mudancaEscala(int valorLido)
{
  return map(valorLido, 0, 1023, 0, 255);
}

// Função para escrever no LED

void escreverNoLed(int pinoLed, int intensidade)
{
  analogWrite(pinoLed, intensidade);
}

// Função do buzzer

void controlarBuzzer(bool ligado)
{
  
  if(ligado){
tone(buzzerPin, 1000); // liga
}
  else{
noTone(buzzerPin); // desliga
}
  
}
  
void loop()
{
valorLido = lerPotenciometro();
Serial.println(valorLido);
pwm = mudancaEscala(valorLido);

// Controle dos LEDs progressivamente
 
if (pwm < 85) {
  
  escreverNoLed(ledPin, pwm * 3); // LED 1 totalmente aceso
  escreverNoLed(ledPin2 , 0); // Aumenta a intensidade do LED 2
  escreverNoLed(ledPin3 , 0); // Mantém o LED 3 apagado
  controlarBuzzer(false);
  
}

else if (pwm < 170)

{
  
  escreverNoLed(ledPin, 255); // LED 1 totalmente aceso
  escreverNoLed(ledPin2,(pwm - 85) * 3); // Aumenta a intensidade do LED 2
  escreverNoLed(ledPin3 , 0); // Mantém o LED 3 apagado
  controlarBuzzer(false);
  
}

else
  { 
  escreverNoLed(ledPin, 255); // LED 1 totalmente aceso
  escreverNoLed(ledPin2, 255); // LED 2 totalmente aceso
  escreverNoLed(ledPin3, (pwm - 170) * 3); // Aumenta a intensidade do LED 3
  controlarBuzzer(true);
  
}
  
}

#endif
