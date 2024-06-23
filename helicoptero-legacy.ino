#include <Keypad.h>

const int PINO_RELE          = 7;
const int PINO_LED_VERMELHO  = 6;
const int PINO_LED_AZUL      = 5;
const int PINO_LED_VERDE     = 4;
const int PINO_LED_BRANCO    = 3;
const int PINO_BUZZER        = 2;

const byte ROWS              = 4;
const byte COLS              = 4;

const int QTD_PISCADAS_LED  = 5;
const int QTD_TOQUE_POLICIA = 3;

int estadoMotor = LOW;

char hexaKeys[ROWS][COLS] = {
                              {'1','2','3'},
                              {'4','5','6'},
                              {'7','8','9'},
                              {'*','0','#'}
                            };

byte rowPins[ROWS] = {13, 12, 11};
byte colPins[COLS] = {10, 9, 8};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  Serial.begin(9600);

  pinMode(PINO_RELE        , OUTPUT);
  pinMode(PINO_LED_VERMELHO, OUTPUT);
  pinMode(PINO_LED_AZUL    , OUTPUT);
  pinMode(PINO_LED_VERDE   , OUTPUT);
  pinMode(PINO_LED_BRANCO  , OUTPUT);
  pinMode(PINO_BUZZER      , OUTPUT);
  
}

void piscarLeds1()
{

  Serial.println("Piscando os Leds na Sequencia 1");

  for (int i=0; i<=QTD_PISCADAS_LED; i++)
  {
    digitalWrite(PINO_LED_VERMELHO, HIGH);
    delay(100);
    digitalWrite(PINO_LED_AZUL    , HIGH);
    delay(100);
    digitalWrite(PINO_LED_VERDE   , HIGH);
    delay(100);
    digitalWrite(PINO_LED_BRANCO  , HIGH);    
    delay(100);
    digitalWrite(PINO_LED_BRANCO  , LOW);
    delay(100);
    digitalWrite(PINO_LED_VERDE   , LOW);
    delay(100);
    digitalWrite(PINO_LED_AZUL    , LOW);
    delay(100);    
    digitalWrite(PINO_LED_VERMELHO, LOW);
    delay(100);       
  }
}

void piscarLeds2()
{
  Serial.println("Piscando os Leds na Sequencia 2");

  for (int i=0; i<=QTD_PISCADAS_LED; i++)
  {
    digitalWrite(PINO_LED_BRANCO  , HIGH);  
    delay(100);  
    digitalWrite(PINO_LED_VERDE   , HIGH);
    delay(100); 
    digitalWrite(PINO_LED_AZUL    , HIGH);    
    delay(100); 
    digitalWrite(PINO_LED_VERMELHO, HIGH);
    delay(100); 

    digitalWrite(PINO_LED_BRANCO  , LOW);   
    delay(100); 
    digitalWrite(PINO_LED_VERDE   , LOW);
    delay(100); 
    digitalWrite(PINO_LED_AZUL    , LOW);    
    delay(100); 
    digitalWrite(PINO_LED_VERMELHO, LOW);    
    delay(100);
  } 
}

void piscarLeds3()
{
  Serial.println("Piscando os Leds na Sequencia 3");

  for (int i=0; i<=QTD_PISCADAS_LED; i++)
  {
    digitalWrite(PINO_LED_BRANCO  , HIGH);  
    delay(100);  
    digitalWrite(PINO_LED_AZUL    , HIGH);    
    delay(100);      
    digitalWrite(PINO_LED_VERDE   , HIGH);
    delay(100); 
    digitalWrite(PINO_LED_VERMELHO, HIGH);
    delay(100);      

    digitalWrite(PINO_LED_VERMELHO, LOW);
    delay(100);      
    digitalWrite(PINO_LED_VERDE   , LOW);
    delay(100);          
    digitalWrite(PINO_LED_AZUL    , LOW);  
    delay(100);            
    digitalWrite(PINO_LED_BRANCO  , LOW);  
    delay(100);         
  }  
}

void acenderLeds()
{
  Serial.println("Acendendo os Leds");

  digitalWrite(PINO_LED_VERMELHO, HIGH);
  digitalWrite(PINO_LED_VERDE   , HIGH);
  digitalWrite(PINO_LED_AZUL    , HIGH);
  digitalWrite(PINO_LED_BRANCO  , HIGH);  
}

void apagarLeds()
{
  Serial.println("Apagando os Leds");
  digitalWrite(PINO_LED_VERMELHO, LOW);
  digitalWrite(PINO_LED_VERDE   , LOW);
  digitalWrite(PINO_LED_AZUL    , LOW);
  digitalWrite(PINO_LED_BRANCO  , LOW); 
}

void tocarTecla()
{
  tone(PINO_BUZZER, 261, 250);
  delay(250);
  noTone(PINO_BUZZER);
}
  

void tocarDoReMiFa()
{
    tone(PINO_BUZZER,262,200); //DO
    delay(200);
    tone(PINO_BUZZER,294,300); //RE
    delay(200);
    tone(PINO_BUZZER,330,300); //MI
    delay(200);
    tone(PINO_BUZZER,349,300); //FA
    delay(300);
    tone(PINO_BUZZER,349,300); //FA
    delay(300);
    tone(PINO_BUZZER,349,300); //FA
    delay(300);
    tone(PINO_BUZZER,262,100); //DO
    delay(200);
    tone(PINO_BUZZER,294,300); //RE
    delay(200);   
    tone(PINO_BUZZER,262,100); //DO
    delay(200);
    tone(PINO_BUZZER,294,300); //RE
    delay(300);
    tone(PINO_BUZZER,294,300); //RE
    delay(300);
    tone(PINO_BUZZER,294,300); //RE
    delay(300);
    tone(PINO_BUZZER,262,200); //DO
    delay(200);
    tone(PINO_BUZZER,392,200); //SOL
    delay(200);
    tone(PINO_BUZZER,349,200); //FA
    delay(200);
    tone(PINO_BUZZER,330,300); //MI
    delay(300);
    tone(PINO_BUZZER,330,300); //MI
    delay(300);
    tone(PINO_BUZZER,330,300); //MI
    delay(300);
    tone(PINO_BUZZER,262,200); //DO
    delay(200);
    tone(PINO_BUZZER,294,300); //RE
    delay(200);
    tone(PINO_BUZZER,330,300); //MI
    delay(200);
    tone(PINO_BUZZER,349,300); //FA
    delay(300);
    tone(PINO_BUZZER,349,300); //FA
    delay(300);
    tone(PINO_BUZZER,349,300); //FA
    delay(300);
}

void tocarPolicia()
{
  int tempo = 10;
  int frequencia = 0;

  for (frequencia = 150; frequencia < 1800; frequencia += 1) 
  {
    tone(PINO_BUZZER, frequencia, tempo); 
    delay(1);
  }
  for (frequencia = 1800; frequencia > 150; frequencia -= 1) 
  {
    tone(PINO_BUZZER, frequencia, tempo); 
    delay(1);
  }  
}

void loop()
{
  char customKey = customKeypad.getKey();
 
  if (customKey)
  {
    Serial.println("Foi pressionado a Tecla");
    Serial.println(customKey);

    if(customKey == '1')
    {
      tocarTecla();
      piscarLeds1();
    }
    else if(customKey == '2')
    {
      tocarTecla();
      piscarLeds2();
    }
    else if(customKey == '3')
    {
      tocarTecla();
      piscarLeds3();
    }
    else if(customKey == '4')
    {
      tocarTecla();
      acenderLeds();
    }    
    else if(customKey == '5')
    {
      tocarTecla();
      apagarLeds();
    }
    else if(customKey == '6')
    {
      if ( estadoMotor == HIGH)
      {
        Serial.println("Definindo estado do motor para");
        Serial.println(LOW);
        estadoMotor = LOW;
      }else{
        Serial.println("Definindo estado do motor para");
        Serial.println(HIGH);        
        estadoMotor = HIGH;
      }
      tocarTecla();
      digitalWrite(PINO_RELE, estadoMotor);   
    }   
    else if(customKey == '7')
    {
      Serial.println("Tocando a policia");
      tocarPolicia();

    } 
    else if(customKey == '8')
    {
      Serial.println("Tocando do-re-mi-fa");
      tocarTecla();
      acenderLeds();
      delay(250);
      tocarDoReMiFa();
      delay(250);
      apagarLeds();

    }  
    else if(customKey == '9')
    {
      Serial.println("Fazendo tudao");
      tocarTecla();
      digitalWrite(PINO_RELE, HIGH); 
      acenderLeds();
      delay(250);

      for (int i=0; i<QTD_TOQUE_POLICIA; i++)
      {
        tocarPolicia();
      }

      delay(250);
      apagarLeds();   
      digitalWrite(PINO_RELE, LOW);    
    }          

  }
}
