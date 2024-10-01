// #define EX_O1
// #define EX_O2
// #define EX_O3
// #define EX_O4
// #define EX_O5
// #define EX_O6

#ifdef EX_O1

// 1 - Faça os leds de cores iguais piscarem na sequência verde, amarelo e vermelho com tempo de 1 seg acesso e 1 seg apagado. 

int pino8 = 8; //verde 1 
int pino9 = 9; //amarelo 1 
int pino10 = 10; //vermelho 1 
int pino11 = 11; //verde 2 
int pino12 = 12; //amarelo 2 
int pino13 = 13; //vermelho 2

void setup() { 
 pinMode(pino8, OUTPUT); 
 pinMode(pino9, OUTPUT); 
 pinMode(pino10, OUTPUT); 
 pinMode(pino11, OUTPUT); 
 pinMode(pino12, OUTPUT); 
 pinMode(pino13, OUTPUT); 
} 
void loop() { 
 digitalWrite(pino8,HIGH); //liga verde 1 
 digitalWrite(pino11,HIGH); //liga verde 2
 delay(1000);
  
 digitalWrite(pino9,HIGH); //liga amarelo 1
 digitalWrite(pino12,HIGH); //liga amarelo 2
 delay(1000);
  
 digitalWrite(pino10,HIGH); //liga vermelho 1 
 digitalWrite(pino13,HIGH); //liga vermelho 2
 delay(1000);
 
 
 digitalWrite(pino8,LOW); //desliga verde 1 
 digitalWrite(pino11,LOW); //desliga verde 2
 delay(1000);
  
 digitalWrite(pino9,LOW); //desliga amarelo 1
 digitalWrite(pino12,LOW); //desliga amarelo 2
 delay(1000);
  
 digitalWrite(pino10,LOW); //desliga vermelho 1 
 digitalWrite(pino13,LOW); //desliga vermelho 2
 delay(1000);
 
}

#endif

//////////////////////////////////////////

#ifdef EX_O2

// 2 - Faça funcionar os 2 grupos de leds como um semáforo como num cruzamento com tempos iguais.

int pino8 = 8; //verde 1 
int pino9 = 9; //amarelo 1 
int pino10 = 10; //vermelho 1 
int pino11 = 11; //verde 2 
int pino12 = 12; //amarelo 2 
int pino13 = 13; //vermelho 2

void setup() { 
 pinMode(pino8, OUTPUT); 
 pinMode(pino9, OUTPUT); 
 pinMode(pino10, OUTPUT); 
 pinMode(pino11, OUTPUT); 
 pinMode(pino12, OUTPUT); 
 pinMode(pino13, OUTPUT); 
} 
void loop() { 
 digitalWrite(pino8,HIGH); //liga verde 1
 digitalWrite(pino13,HIGH); //liga vermelho 2
 delay(2000);
  
 digitalWrite(pino8,LOW); //desliga verde 1
 digitalWrite(pino13,LOW); //desliga vermelho 2
 delay(2000);
  
 digitalWrite(pino9,HIGH); //liga amarelo 1 
 digitalWrite(pino11,HIGH); //liga verde 2
 delay(2000);
  
 digitalWrite(pino9,LOW); //desliga amarelo 1
 digitalWrite(pino11,LOW); //desliga verde 2
 delay(2000);
  
 digitalWrite(pino10,HIGH); //liga vermelho 1
 digitalWrite(pino12,HIGH); //liga amarelo 2
 delay(2000);
  
 digitalWrite(pino10,LOW); //desliga vermelho 1
 digitalWrite(pino12,LOW); //desliga amarelo 2
 delay(2000);
 
}

#endif

/////////////////////////////////////////////

#ifdef EX_O3

// 3 - Modifique os tempos para que um dos semáforos do cruzamento fique mais tempo com verde aceso do que o outro. Verde 4 seg e 2 segs.

int pino8 = 8; //verde 1 
int pino9 = 9; //amarelo 1 
int pino10 = 10; //vermelho 1 
int pino11 = 11; //verde 2 
int pino12 = 12; //amarelo 2 
int pino13 = 13; //vermelho 2

void setup() { 
 pinMode(pino8, OUTPUT); 
 pinMode(pino9, OUTPUT); 
 pinMode(pino10, OUTPUT); 
 pinMode(pino11, OUTPUT); 
 pinMode(pino12, OUTPUT); 
 pinMode(pino13, OUTPUT); 
} 
void loop() { 
 digitalWrite(pino8,HIGH); //liga verde 1
 delay(4000);
 digitalWrite(pino13,HIGH); //liga vermelho 2
 delay(2000);
  
 digitalWrite(pino8,LOW); //desliga verde 1
 delay(2000);
 digitalWrite(pino13,LOW); //desliga vermelho 2
 delay(2000);
  
 digitalWrite(pino9,HIGH); //liga amarelo 1 
 digitalWrite(pino11,HIGH); //liga verde 2
 delay(2000);
  
 digitalWrite(pino9,LOW); //desliga amarelo 1
 digitalWrite(pino11,LOW); //desliga verde 2
 delay(2000);
  
 digitalWrite(pino10,HIGH); //liga vermelho 1
 digitalWrite(pino12,HIGH); //liga amarelo 2
 delay(2000);
  
 digitalWrite(pino10,LOW); //desliga vermelho 1
 digitalWrite(pino12,LOW); //desliga amarelo 2
 delay(2000);
 
}

#endif

////////////////////////////////////////

#ifdef EX_O4

// 4 – Acrescente um botão a montagem. Faça funcionar os semáforos para travessia de pedestres. Um será para o carro e o outro para os pedestres.

int pino8 = 8;  // Verde carros
int pino9 = 9;  // Amarelo carros
int pino10 = 10; // Vermelho carros
int pino11 = 11; // Verde pedestres
int pino12 = 12; // Amarelo pedestres
int pino13 = 13; // Vermelho pedestres

// Pino para o botão
int buttonPin = 2;
int buttonState = 0;

void setup()
{
  pinMode(pino8, OUTPUT);
  pinMode(pino9, OUTPUT);
  pinMode(pino10, OUTPUT);
  pinMode(pino11, OUTPUT);
  pinMode(pino12, OUTPUT);
  pinMode(pino13, OUTPUT);
  
  pinMode(buttonPin, INPUT);

}

void loop() {
  // Lê o estado do botão de pedestres
  buttonState = digitalRead(buttonPin);

  // Se o botão for pressionado, ativa o semáforo de pedestres
  if (buttonState == LOW)
  {
    ativarSemaforoPedestre();
  }
  else
  {
    // Funcionamento normal dos semáforos
    semaforoCarros();
  }
}

// Função para ativar o semáforo de carros
void semaforoCarros() {
  digitalWrite(pino8, HIGH);  // Liga verde carros
  digitalWrite(pino13, HIGH); // Liga vermelho pedestres
  delay(4000);

  digitalWrite(pino8, LOW);   // Desliga verde carros
  delay(2000);

  digitalWrite(pino9, HIGH);  // Liga amarelo carros
  digitalWrite(pino11, HIGH); // Liga verde pedestres
  delay(2000);  // Amarelo carros e verde pedestres por 2 segundos

  digitalWrite(pino9, LOW);   // Desliga amarelo carros
  digitalWrite(pino11, LOW);  // Desliga verde pedestres

  digitalWrite(pino10, HIGH); // Liga vermelho carros
  digitalWrite(pino12, HIGH); // Liga amarelo pedestres
  delay(2000);  // Vermelho carros e amarelo pedestres por 2 segundos

  digitalWrite(pino10, LOW);  // Desliga vermelho carros
  digitalWrite(pino12, LOW);  // Desliga amarelo pedestres
}

// Função para ativar o semáforo de pedestres
void ativarSemaforoPedestre() {

  digitalWrite(pino13, LOW);   // Desliga vermelho pedestres
  digitalWrite(pino11, HIGH);  // Liga verde pedestres
  delay(4000);  // Verde pedestres por 4 segundos

  digitalWrite(pino11, LOW);   // Desliga verde pedestres
  digitalWrite(pino12, HIGH);  // Liga amarelo pedestres
  delay(2000);  // Amarelo pedestres por 2 segundos
  
  digitalWrite(pino12, LOW);   // Desliga amarelo pedestres
  digitalWrite(pino13, HIGH);  // Liga vermelho pedestres
}


#endif

/////////////////////////////////////////

#ifdef EX_O5

// 5 – Acrescente um buzzer a montagem e quando o botão for acionado no semáforo de pedestre o buzzer deve apitar por 100ms.

int pino8 = 8;
int pino9 = 9;
int pino10 = 10;
int pino11 = 11;
int pino12 = 12;
int pino13 = 13;

// adicionado o buzzer
int buttonPin = 2;
int buttonState = 0;
int buzzerPin = 7;

void setup()
{
  pinMode(pino8, OUTPUT);
  pinMode(pino9, OUTPUT);
  pinMode(pino10, OUTPUT);
  pinMode(pino11, OUTPUT);
  pinMode(pino12, OUTPUT);
  pinMode(pino13, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW)
  {
    ativarSemaforoPedestre();
    tone(buzzerPin, 1000);  // Toca um som no buzzer
    delay(100);             // Duração de 100 ms
    noTone(buzzerPin);      // Para o som do buzzer
  }
  else
  {
    semaforoCarros();
  }
}

void semaforoCarros() {
  digitalWrite(pino8, HIGH);
  digitalWrite(pino13, HIGH);
  delay(4000);

  digitalWrite(pino8, LOW);
  delay(2000);

  digitalWrite(pino9, HIGH);
  digitalWrite(pino11, HIGH);
  delay(2000);

  digitalWrite(pino9, LOW);
  digitalWrite(pino11, LOW);

  digitalWrite(pino10, HIGH);
  digitalWrite(pino12, HIGH);
  delay(2000);

  digitalWrite(pino10, LOW);
  digitalWrite(pino12, LOW);
}

void ativarSemaforoPedestre() {

  digitalWrite(pino13, LOW);
  digitalWrite(pino11, HIGH);
  delay(4000);

  digitalWrite(pino11, LOW);
  digitalWrite(pino12, HIGH);
  delay(2000);
  
  digitalWrite(pino12, LOW);
  digitalWrite(pino13, HIGH);
}

#endif

//////////////////////////////////

#ifdef EX_O6

// 6 – Transforme o acionamento do buzzer numa função.

int pino8 = 8;
int pino9 = 9;
int pino10 = 10;
int pino11 = 11;
int pino12 = 12;
int pino13 = 13;

// adicionado o buzzer
int buttonPin = 2;
int buttonState = 0;
int buzzerPin = 7;

void setup()
{
  pinMode(pino8, OUTPUT);
  pinMode(pino9, OUTPUT);
  pinMode(pino10, OUTPUT);
  pinMode(pino11, OUTPUT);
  pinMode(pino12, OUTPUT);
  pinMode(pino13, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW)
  {
    ativarSemaforoPedestre();
    tocarBuzzer(); // Chama a função para tocar o buzzer
  }
  else
  {
    semaforoCarros();
  }
}

// Função para tocar o buzzer por 100 ms
void tocarBuzzer() {
  tone(buzzerPin, 1000);
  delay(100);
  noTone(buzzerPin);
}

void semaforoCarros() {
  digitalWrite(pino8, HIGH);
  digitalWrite(pino13, HIGH);
  delay(4000);

  digitalWrite(pino8, LOW);
  delay(2000);

  digitalWrite(pino9, HIGH);
  digitalWrite(pino11, HIGH);
  delay(2000);

  digitalWrite(pino9, LOW);
  digitalWrite(pino11, LOW);

  digitalWrite(pino10, HIGH);
  digitalWrite(pino12, HIGH);
  delay(2000);

  digitalWrite(pino10, LOW);
  digitalWrite(pino12, LOW);
}

void ativarSemaforoPedestre() {

  digitalWrite(pino13, LOW);
  digitalWrite(pino11, HIGH);
  delay(4000);

  digitalWrite(pino11, LOW);
  digitalWrite(pino12, HIGH);
  delay(2000);
  
  digitalWrite(pino12, LOW);
  digitalWrite(pino13, HIGH);
}

#endif
