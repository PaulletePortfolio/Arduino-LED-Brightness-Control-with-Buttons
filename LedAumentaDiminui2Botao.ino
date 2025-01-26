// Definição dos pinos
int BotaoAumenta = 2;
int BotaoDiminui = 3;
int Led = 9; 
int brilho = 0;
int incremento = 5;

void setup() {
  Serial.begin(9600);
  pinMode(BotaoAumenta, INPUT);
  pinMode(BotaoDiminui, INPUT);
  pinMode(Led, OUTPUT); 
}

void loop() {

  int estadoBotaoAumenta = digitalRead(BotaoAumenta);
  int estadoBotaoDiminui = digitalRead(BotaoDiminui);



  if (estadoBotaoAumenta == HIGH) { 
    brilho += incremento;
    if (brilho > 255) {
      brilho = 255;
    }
    delay(200);
  }

  if (estadoBotaoDiminui == HIGH) { 
    brilho -= incremento;
        Serial.println(estadoBotaoDiminui);
    if (brilho < 0) {
      brilho = 0;
    }
    delay(200);
  }

  analogWrite(Led, brilho);

  Serial.print("Brilho: ");
  Serial.println(brilho);
  delay(100);
}
