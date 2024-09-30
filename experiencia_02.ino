// ronaldo luiz dos santos soares

// #define EX_O1
// #define EX_O2
// #define EX_O3
// #define EX_O4
// #define EX_O5
// #define EX_O6
// #define EX_O7
// #define EX_O8

///////////////////////

#ifdef EX_O1

// Variáveis
int buttonPin1 = 2; 
int buttonPin2 = 3;
int ledPin1 = 13;   
int ledPin2 = 12;   
int buzzerPin = 7;
int buttonState1 = 0;
int buttonState2 = 0;

void setup()
{
  pinMode(ledPin1, OUTPUT);    
  pinMode(ledPin2, OUTPUT);    
  pinMode(buttonPin1, INPUT);  
  pinMode(buttonPin2, INPUT);  
  pinMode(buzzerPin, OUTPUT); 

  noTone(buzzerPin);

  Serial.begin(9600);
}

void loop()
{

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == HIGH)
  {
    digitalWrite(ledPin1, LOW); 
  }
  else
  {
    digitalWrite(ledPin1, HIGH); 
  }

  if (buttonState2 == HIGH)
  {
    digitalWrite(ledPin2, LOW); 
  }
  else
  {
    digitalWrite(ledPin2, HIGH); 
  }

  noTone(buzzerPin);
}

#endif

//////////////////

#ifdef EX_O2

// Variáveis
int buttonPin1 = 2;
int buttonPin2 = 3;
int ledPin1 = 13;
int ledPin2 = 12;
int buzzerPin = 7;
int buttonState1 = 0;
int buttonState2 = 0;

void setup()
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == HIGH)
  {
    digitalWrite(ledPin1, LOW);
    noTone(buzzerPin);
  }
  else
  {
    digitalWrite(ledPin1, HIGH);
    tone(buzzerPin, 2000);  // Buzzer apita quando LED 1 acender
  }

  if (buttonState2 == HIGH)
  {
    digitalWrite(ledPin2, LOW);
  }
  else
  {
    digitalWrite(ledPin2, HIGH);
  }
}

#endif

///////////////////////

#ifdef EX_O3

// Variáveis
int buttonPin1 = 2;
int buttonPin2 = 3;
int ledPin1 = 13;
int ledPin2 = 12;
int buzzerPin = 7;
int buttonState1 = 0;
int buttonState2 = 0;

void setup()
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == HIGH)
  {
    digitalWrite(ledPin1, LOW);
  }
  else
  {
    digitalWrite(ledPin1, HIGH);
  }

  if (buttonState2 == HIGH)
  {
    digitalWrite(ledPin2, LOW);
    noTone(buzzerPin);
  }
  else
  {
    digitalWrite(ledPin2, HIGH);
    tone(buzzerPin, 2000);  // Buzzer apita quando LED 2 acender
  }
}

#endif

///////////////////

#ifdef EX_O4

// Variáveis
int buttonPin1 = 2;
int buttonPin2 = 3;
int ledPin1 = 13;
int ledPin2 = 12;
int buzzerPin = 7;
int buttonState1 = 0;
int buttonState2 = 0;

void setup()
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // Botão 1 controla o LED 2 e buzzer
  if (buttonState1 == HIGH)
  {
    digitalWrite(ledPin2, HIGH);
    tone(buzzerPin, 2000);
  }
  else
  {
    digitalWrite(ledPin2, LOW);
    noTone(buzzerPin);
  }

  // Botão 2 controla o LED 1 e buzzer
  if (buttonState2 == HIGH)
  {
    digitalWrite(ledPin1, HIGH);
    tone(buzzerPin, 2000);
  }
  else
  {
    digitalWrite(ledPin1, LOW);
    noTone(buzzerPin);
  }
}

#endif

///////////////////

#ifdef EX_O5

// Função para ler o estado do botão 1
bool lerBotao1() {
  return digitalRead(buttonPin1) == HIGH;
}

// Função para ler o estado do botão 2
bool lerBotao2()
{
  return digitalRead(buttonPin2) == HIGH;
}

void setup()
{
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // Chama as funções de leitura dos botões
  if (lerBotao1())
  {
    Serial.println("Botão 1 pressionado");
  }
  else
  {
    Serial.println("Botão 1 não pressionado");
  }

  if (lerBotao2())
  {
    Serial.println("Botão 2 pressionado");
  }
  else
  {
    Serial.println("Botão 2 não pressionado");
  }
}

#endif

///////////////////

#define EX_O6

#ifdef EX_O6

// Função para acender ou apagar o LED 1
void controlarLed1(bool acender)
{
  digitalWrite(ledPin1, acender ? HIGH : LOW);
}

// Função para acender ou apagar o LED 2
void controlarLed2(bool acender)
{
  digitalWrite(ledPin2, acender ? HIGH : LOW);
}

void setup()
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Controle de LED com base na lógica de acionamento
  controlarLed1(lerBotao1());
  controlarLed2(lerBotao2());
}

#endif

////////////////

#ifdef EX_O7

// Função para controlar o buzzer
void controlarBuzzer(bool apitar)
{
  if (apitar)
  {
    tone(buzzerPin, 2000);  // Frequência de 2000 Hz
  }
  else
  {
    noTone(buzzerPin);
  }
}

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Aciona o buzzer baseado na lógica dos botões
  controlarBuzzer(lerBotao1() || lerBotao2());
}

#endif

///////////////

#ifdef EX_O8

#define DO 264 
#define RE 297 
#define MI 330 
#define FA 352 
#define SOL 396 
#define LA 440 
#define SI 495 
#define D 500 
#define N 29 

int notas[][2] = {
  {SOL, D / 2}, {SOL, D / 2}, {LA, D * 2}, {SOL, D}, {DO * 2, D},
  {SI, D * 3}, {SOL, D / 2}, {SOL, D / 2}, {LA, D * 2}, {SOL, D}, {RE * 2, D}, {DO * 2, D},
  {DO * 2, D}, {0, D}, {MI * 2, D / 2}, {MI * 2, D / 2}, {SOL * 2, D * 2}, {MI * 2, D},
  {DO * 2, D}, {SI, D}, {LA, D}, {0, D}, {FA * 2, D / 2}, {FA * 2, D / 2}, {MI * 2, D * 2},
  {DO * 2, D}, {RE * 2, D}, {DO * 2, D}, {DO * 2, D * 3}
};

int duracao;
int nota;
int buzzerPin = 7;
int buttonPin1 = 2;  // Pino do botão 1
int buttonState = 0; // Variável para armazenar o estado do botão

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin1);

  if (buttonState == LOW)
  {
    tocarMusica();
  }
}

void tocarMusica() {
  for (int i = 0; i < N; i++)
  {
    nota = notas[i][0];
    duracao = notas[i][1];

    if (nota > 0)
    {
      tone(buzzerPin, nota, duracao);
    }

    delay(duracao);
  }

  noTone(buzzerPin);
}
