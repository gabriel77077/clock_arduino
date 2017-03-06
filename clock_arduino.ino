//Feito por Gabriel França Sarmento
//gabriel77077@gmail.com
//21 de novembro de 2015




#define phrs 7 // pino do botão das horas
#define pmin 12 // pino do botão dos minutos
int bhrs = 0; //estado do botão das horas
int bmin = 0; //estado do botão dos minutos
int seg = 0; //segundos
int hrs = 0; //horas
int minu = 0; //minutos
int dias = 0; //dias
int intervalo = 1000;
void setup() {
  Serial.begin(9600);
  pinMode(phrs, INPUT);
  pinMode(pmin, INPUT);
  digitalWrite(phrs, 1); // acionar resistor de elevação interno do arduino
  digitalWrite(pmin, 1); // acionar resistor de elevação interno do arduino
}
// tempo em milisegundos em que os segundos será incrementado


void loop() {
  seg++;
  long tempo = millis();
  while ( millis() - tempo < intervalo) {
    // se os segundos chegarem a 60 os mesmos são zerados e se incrementa os minutos
    if (seg > 60) {
      minu++;
      seg = 0;
    }
    // se os minutos chegarem a 60 os mesmos são zerados e se incrementa as horas
    if (minu > 60) {
      hrs++;
      minu = 0;
    }
    // se as horas chegarem a 24 as mesmas são zeradas e se incrementa os dias
    if (hrs > 24) {
      dias++;
      hrs = 0;
    }
    //caso o botão das horas for precionado a mesma será incrementada
    bhrs = digitalRead(phrs);
    if (bhrs == 0) {
      hrs++;
      while (bhrs == 0) {
        bhrs = digitalRead(phrs);
        Serial.println("botão das horas precionado");
        Serial.println(bhrs);
        //para evitar que as horas sejam imcrementados enquanto o botão for precionado apenas uma vez
      }
    }
    //caso o botão dos minutos for precionado o mesmo será incrementado
    bmin = digitalRead(pmin);
    if (bmin == 0) {
      minu++;
      while (bmin == 0) {
        bmin = digitalRead(pmin);
        Serial.println("botão dos minutos precionado");
        Serial.println(bmin);
        //para evitar que os minutos sejam incrementados mais de uma vez enquanto o  botão for precionado apenas uma vez
      }
    }
    //escreve na serial os dias, horas, minutos e segundos
    Serial.print(" Dias: ");
    Serial.print(dias);
    Serial.print(" Horas: ");
    Serial.print(hrs);
    Serial.print(" Minutos: ");
    Serial.print(minu);
    Serial.print(" Segundos: ");
    Serial.print(seg);
    Serial.print(" Millis: ");
    Serial.println(millis());
  }

}
