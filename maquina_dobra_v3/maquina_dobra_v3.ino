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
const int fim_curso1 = 7;
const int fim_curso2 = 6;

//variaveis do sistema
bool flag_barrilet = false;

void setup() {
  // put your setup code here, to run once:

pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 if(flag_barrilet == false) {home_barrilet();}

 else{
    for(int i=0; i<1580; i++){
      passo();
      }
    delay(500);

    for(int i=0; i<2420; i++){
      passof();
      }
    delay(2000);
  }
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
