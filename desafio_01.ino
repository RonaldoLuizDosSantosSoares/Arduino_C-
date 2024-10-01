// desafio do rui

// carro 1
int verdeCarro1 = 13;
int amareloCarro1 = 12;
int vermelhoCarro1 = 11;

// pedestre 1
int verdePedestre1 = 10;
int vermelhoPedestre1 = 9;

// carro 2
int verdeCarro2 = 7;
int amareloCarro2 = 6;
int vermelhoCarro2 = 5;

// pedestre 2
int verdePedestre2 = 4;
int vermelhoPedestre2 = 3;

int botao = 2;  // Botão de pedestre

void setup()
{
  pinMode(verdeCarro1, OUTPUT);
  pinMode(amareloCarro1, OUTPUT);
  pinMode(vermelhoCarro1, OUTPUT);
  pinMode(verdePedestre1, OUTPUT);
  pinMode(vermelhoPedestre1, OUTPUT);

  pinMode(verdeCarro2, OUTPUT);
  pinMode(amareloCarro2, OUTPUT);
  pinMode(vermelhoCarro2, OUTPUT);
  pinMode(verdePedestre2, OUTPUT);
  pinMode(vermelhoPedestre2, OUTPUT);

  pinMode(botao, INPUT_PULLUP);  // Botão com pull-up interno

  Serial.begin(9600);
}

void loop()
{
  // Passo 1: Acender o vermelho dos pedestres
  acender_red_pedestres();
  
  // Passo 2: Apagar o vermelho do carro 1 e o amarelo do carro 2
  apagar_red_carro1();
  apagar_amarelo_carro2();
  
  // Passo 3: Acender o verde do carro 1 e o vermelho do carro 2
  acender_verde_carro1();
  acender_red_carro2();
  delay(3000);
  
  // Passo 4: Apagar o verde do carro 1 e acender o amarelo do carro 1
  apagar_verde_carro1();
  acender_amarelo_carro1();
  delay(3000);
  
  // Passo 5: Apagar o amarelo do carro 1 e acender o vermelho do carro 1
  apagar_amarelo_carro1();
  acender_red_carro1();
  
  int estadoBotao = digitalRead(botao);
  
  if (estadoBotao == LOW)
  {
    apagar_red_pedestres();
    acender_verde_pedestres();
    delay(3000);
    
    acender_red_pedestres();
    apagar_verde_pedestres();
  }
  
  // Passo 6: Apagar o vermelho do carro 2 e acender o verde do carro 2
  apagar_red_carro2();
  acender_verde_carro2();
  delay(3000);
  
  // Passo 7: Apagar o verde do carro 2 e acender o amarelo do carro 2
  apagar_verde_carro2();
  acender_amarelo_carro2();
  delay(3000);
}



// Funções de controle dos semáforos e pedestres
void acender_red_pedestres()
{
  digitalWrite(vermelhoPedestre1, HIGH);
  digitalWrite(vermelhoPedestre2, HIGH);
  Serial.println("R -> Acende vermelho pedestres 1 e 2");
}

void apagar_red_pedestres()
{
  digitalWrite(vermelhoPedestre1, LOW);
  digitalWrite(vermelhoPedestre2, LOW);
  Serial.println("R -> Apaga vermelho pedestres 1 e 2");
}

void acender_verde_pedestres()
{
  digitalWrite(verdePedestre1, HIGH);
  digitalWrite(verdePedestre2, HIGH);
  Serial.println("V -> Acende verde pedestres 1 e 2");
}

void apagar_verde_pedestres()
{
  digitalWrite(verdePedestre1, LOW);
  digitalWrite(verdePedestre2, LOW);
  Serial.println("V -> Apaga verde pedestres 1 e 2");
}

void acender_verde_carro1()
{
  digitalWrite(verdeCarro1, HIGH);
  Serial.println("V -> Acende verde carro 1");
}

void apagar_verde_carro1()
{
  digitalWrite(verdeCarro1, LOW);
  Serial.println("V -> Apaga verde carro 1");
}

void acender_amarelo_carro1()
{
  digitalWrite(amareloCarro1, HIGH);
  Serial.println("A -> Acende amarelo carro 1");
}

void apagar_amarelo_carro1()
{
  digitalWrite(amareloCarro1, LOW);
  Serial.println("A -> Apaga amarelo carro 1");
}

void acender_red_carro1()
{
  digitalWrite(vermelhoCarro1, HIGH);
  Serial.println("R -> Acende vermelho carro 1");
}

void apagar_red_carro1()
{
  digitalWrite(vermelhoCarro1, LOW);
  Serial.println("R -> Apaga vermelho carro 1");
}

void acender_verde_carro2()
{
  digitalWrite(verdeCarro2, HIGH);
  Serial.println("V -> Acende verde carro 2");
}

void apagar_verde_carro2()
{
  digitalWrite(verdeCarro2, LOW);
  Serial.println("V -> Apaga verde carro 2");
}

void acender_amarelo_carro2()
{
  digitalWrite(amareloCarro2, HIGH);
  Serial.println("A -> Acende amarelo carro 2");
}

void apagar_amarelo_carro2()
{
  digitalWrite(amareloCarro2, LOW);
  Serial.println("A -> Apaga amarelo carro 2");
}

void acender_red_carro2()
{
  digitalWrite(vermelhoCarro2, HIGH);
  Serial.println("R -> Acende vermelho carro 2");
}

void apagar_red_carro2()
{
  digitalWrite(vermelhoCarro2, LOW);
  Serial.println("R -> Apaga vermelho carro 2");
}
