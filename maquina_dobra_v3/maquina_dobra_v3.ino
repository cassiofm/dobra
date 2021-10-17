// Programa para controle de motor de passo

#define pot A0    // potenciometro define intervalo do ciclo

//pinos de saida digital
const int pulso_m1 = 4;
const int direcao_m1 = 12;
const int pulso_m2 = 8;
const int direcao_m2 = 9;

//
// pinos de entrada digital
const int sensor_barrilet = 2;
const int botao_pausa = 3;
const int fim_curso1 = 7;
const int fim_curso2 = 6;

//variaveis do sistema
bool flag_barrilet = false;
bool flag_m1 = false;
bool flag_m2 = false;

void setup() {
  // put your setup code here, to run once:

pinMode(LED_BUILTIN, OUTPUT);
pinMode(sensor_barrilet, INPUT);
pinMode(pulso_m1, OUTPUT);
pinMode(direcao_m1, OUTPUT);
pinMode(pulso_m2, OUTPUT);
pinMode(direcao_m2, OUTPUT);
pinMode(fim_curso1, INPUT_PULLUP);
pinMode(fim_curso2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
 /*if(flag_barrilet == false) {home_barrilet();}

 else{
    for(int i=0; i<1580; i++){
      passo();
      }
    delay(500);

    for(int i=0; i<2420; i++){
      passof();
      }
    delay(2000);
  }  */
 // if(flag_m1 == false){home_m1();}
 home_m1();
}


void passo(){
  
  digitalWrite(LED_BUILTIN, HIGH);
  delayMicroseconds(150);
  digitalWrite(LED_BUILTIN,LOW);
  delayMicroseconds(150);
}

void passof(){
  
  digitalWrite(LED_BUILTIN, HIGH);
  delayMicroseconds(80);
  digitalWrite(LED_BUILTIN,LOW);
  delayMicroseconds(80);
}
void home_barrilet() {
  while(digitalRead(sensor_barrilet) == HIGH) {
      passo();
      }
  flag_barrilet = true;
  delay(2000);
}

void home_m1(){
  while(digitalRead(fim_curso1) == HIGH){
    digitalWrite(direcao_m1, HIGH);
    passo_m1();
    }
    flag_m1 = true;
  }

  void passo_m1(){
  
  digitalWrite(pulso_m1, HIGH);
  delayMicroseconds(3000);
  digitalWrite(pulso_m1,LOW);
  delayMicroseconds(3000);
  }
  
