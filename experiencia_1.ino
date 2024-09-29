// ronaldo luiz dos santos soares

// #define EX_O1
// #define EX_O2
// #define EX_O3
// #define EX_O4
// #define EX_O5
// #define EX_O6
// #define EX_O7

///////////////////////

#ifdef EX_O1
// 1 - faça os leds piscarem a cada 4 seg.

int LED = 13;
int LED_2 = 12;
int LED_3 = 11;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop()
{
  digitalWrite(LED, HIGH);
  delay(100); // esperar por 1 segundos
  digitalWrite(LED, LOW);
  delay(4000); // esperar por 4 segundos
  
  digitalWrite(LED_2, HIGH);
  delay(100);
  digitalWrite(LED_2, LOW);
  delay(4000);
  
  digitalWrite(LED_3, HIGH);
  delay(100);
  digitalWrite(LED_3, LOW);
  delay(4000);
}

#endif

#ifdef EX_O2
// 2 - faça os leds ficarem acesos por 2 seg e apagados por 4 seg.

int LED = 13;
int LED_2 = 12;
int LED_3 = 11;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop()
{
  digitalWrite(LED, HIGH);
  delay(2000); // esperar por 2 segundos
  digitalWrite(LED, LOW);
  delay(4000); // esperar por 4 segundos
  
  digitalWrite(LED_2, HIGH);
  delay(2000);
  digitalWrite(LED_2, LOW);
  delay(4000);
  
  digitalWrite(LED_3, HIGH);
  delay(2000);
  digitalWrite(LED_3, LOW);
  delay(4000);
}

////////////////////////////////////////////

#endif

#ifdef EX_O3
// 3 - faça os leds ficarem acesos por 2 seg e apagados por 4 seg e em seguida, acesos por 3 seg e apagados por 5 seg

int LED = 13;
int LED_2 = 12;
int LED_3 = 11;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop()
{
  digitalWrite(LED, HIGH);
  delay(2000); // esperar por 2 segundos
  digitalWrite(LED_2, HIGH);
  delay(2000);
  digitalWrite(LED_3, HIGH);
  delay(2000);
  
  digitalWrite(LED, LOW);
  delay(4000); // esperar por 4 segundos
  digitalWrite(LED_2, LOW);
  delay(4000);
  digitalWrite(LED_3, LOW);
  delay(4000);
  
  digitalWrite(LED, HIGH);
  delay(3000); // esperar por 3 segundos
  digitalWrite(LED_2, HIGH);
  delay(3000);
  digitalWrite(LED_3, HIGH);
  delay(3000);
  
  digitalWrite(LED, LOW);
  delay(5000); // esperar por 5 segundos
  digitalWrite(LED_2, LOW);
  delay(5000);
  digitalWrite(LED_3, LOW);
  delay(5000);
  
}

#endif

//////////////////////////////////

#ifdef EX_O4
// 4 - troque na montagem a ligação do pino 13 para 12. faça o led da placa piscar ao mesmo tempo que o led externo com o tempo 1 seg.

int LED = 13;
int LED_2 = 12;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LED_2, OUTPUT);

}

void loop()
{
  digitalWrite(LED, HIGH);
  delay(1000); // esperar 1 segundo
  digitalWrite(LED_2, HIGH);
  delay(1000);

  
  digitalWrite(LED, LOW);
  delay(1000); // esperar 1 segundo
  digitalWrite(LED_2, LOW);
  delay(1000);

  
}

#endif

////////////////////////////////////

#ifdef EX_O5
// 5 - faça o led da placa piscar com um tempo de 2 seg. e o led externo piscar com um tempo de 3 seg. em sequencia.

int LED = 13;
int LED_2 = 12;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LED_2, OUTPUT);

}

void loop()
{
  digitalWrite(LED, HIGH);
  delay(2000); // esperar por 2 segundos
  digitalWrite(LED_2, HIGH);
  delay(3000); // esperar por 3 segundos

  
  digitalWrite(LED, LOW);
  delay(1000); 
  digitalWrite(LED_2, LOW);
  delay(1000);

  
}

#endif

////////////////////////////////////

#ifdef EX_O6
// 6 - faça o led externo ficar aceso por 3 seg e apagado por 5 e o led da placa aceso por 2,5 seg e apagado por 4,5.

int LED = 13;
int LED_2 = 12;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LED_2, OUTPUT);

}

void loop()
{
  digitalWrite(LED, HIGH);
  delay(2500); // esperar por 3 segundos
  digitalWrite(LED_2, HIGH);
  delay(3000); // esperar por 5 segundos

  
  digitalWrite(LED, LOW);
  delay(4500); 
  digitalWrite(LED_2, LOW);
  delay(5000);

}

#endif

/////////////////////////////

#ifdef EX_O7
// 7 - faça o led da placa piscar alternadamente em relação ao led externo com o tempo de 1 seg.

int LED = 13;
int LED_2 = 12;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LED_2, OUTPUT);

}

void loop()
{
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(200); 
  digitalWrite(LED_2, HIGH);
  delay(1000); 
  digitalWrite(LED_2, LOW);
  delay(400);

}

#endif