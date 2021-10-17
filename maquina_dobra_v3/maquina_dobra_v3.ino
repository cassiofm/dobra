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
}


void passo(){
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN,LOW);
  delay(100);
}

void home_barrilet() {
  while(digitalRead(sensor_barrilet) == HIGH) {
      passo();
      }
  flag_barrilet = true;
  delay(2000);
}
