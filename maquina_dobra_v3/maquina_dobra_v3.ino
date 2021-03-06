// Programa para controle de motor de passo

#define pot A0    // potenciometro define intervalo do ciclo

//pinos de saida digital
const int pulso_m1 = 4;
const int direcao_m1 = 5;
const int pulso_m2 = 8;
const int direcao_m2 = 9;

//
// pinos de entrada digital
const int sensor_barrilet = 2;
const int botao_pausa = 3;
const int fim_curso1 = 6;
const int fim_curso2 = 7;

//variaveis do sistema
bool flag_barrilet = false;
bool flag_m1 = false;
bool flag_m2 = false;
int t;

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
  
 if(flag_barrilet == false) {home_barrilet();}
 if(flag_m1 == false){home_m1();}
 if(flag_m2 == false){home_m2();}
 else{
    for(int i=0; i<1582; i++){
      passo(230);
      }
    delay(700);

    for(int i=0; i<2418; i++){
      passo(200);
      }
    delay(1000);

    for(int k =0; k<1100; k++){
      digitalWrite(direcao_m1, LOW);
      passo_m1(900);
      digitalWrite(direcao_m2, LOW);
      passo_m2(900);
      }
delay(1000);
for(int k =0; k<1100; k++){
      digitalWrite(direcao_m1, HIGH);
      passo_m1(150);
      digitalWrite(direcao_m2, HIGH);
      passo_m2(150);
      }
      
  }  
  
 
}


int passo(int t){
  
  digitalWrite(LED_BUILTIN, HIGH);
  delayMicroseconds(t);
  digitalWrite(LED_BUILTIN,LOW);
  delayMicroseconds(t);
}

/*void passof(){
  
  digitalWrite(LED_BUILTIN, HIGH);
  delayMicroseconds(80);
  digitalWrite(LED_BUILTIN,LOW);
  delayMicroseconds(80);
}*/
void home_barrilet() {
  while(digitalRead(sensor_barrilet) == HIGH) {
      passo(100);
      }
  flag_barrilet = true;
  delay(2000);
}

void home_m1(){
  while(digitalRead(fim_curso1) == HIGH){
    digitalWrite(direcao_m1, HIGH);
    passo_m1(800);
    }
    delay(100);
    flag_m1 = true;
    digitalWrite(direcao_m1, LOW);
    for(int j=1; j<2000; j++){
      passo_m1(300);
    }
  }

  int passo_m1(int t){
  
  digitalWrite(pulso_m1, HIGH);
  delayMicroseconds(t);
  digitalWrite(pulso_m1,LOW);
  delayMicroseconds(t);
  }
  //----------------------------------------------

  void home_m2(){
  while(digitalRead(fim_curso2) == HIGH){
    digitalWrite(direcao_m2, HIGH);
    passo_m2(800);
    }
    delay(100);
    flag_m2 = true;
    digitalWrite(direcao_m2, LOW);
    for(int j=1; j<2000; j++){
      passo_m2(300);
    }
  }

  int passo_m2(int t){
  
  digitalWrite(pulso_m2, HIGH);
  delayMicroseconds(t);
  digitalWrite(pulso_m2,LOW);
  delayMicroseconds(t);
  }
  
