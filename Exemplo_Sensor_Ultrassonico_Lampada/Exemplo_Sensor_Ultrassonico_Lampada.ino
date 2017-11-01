// Inclusão da biblioteca do sensor
// Essa biblioteca não vem por padrão com o arduino e
// precisa ser instalada pelo gerenciador de bibliotecas
#include <Ultrasonic.h>

// Inicializa o objeto do sensor ultrasônico
// Usando as portas 12 e 13 para trigger e echo
Ultrasonic ultrasonic(12, 13);
int ledVerde = 11;
int ledRed = 10;
int buzzer = 9;

void setup() {
  // Inicializa a porta Serial
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  // Lê o valor do sensor
  int distancia = ultrasonic.distanceRead();


  // Escreve o valor da distância no painel Serial
  Serial.print("Distance in CM: ");
  Serial.println(distancia);

  delay(1000);

  if (distancia < 10  && distancia > 8) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRed, LOW);
    noTone(buzzer);

    //Serial.println("Led Acendeu");
  }
  else if (distancia < 8  && distancia > 6) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRed, HIGH);
    noTone(buzzer);
  }
  else if (distancia < 6) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRed, LOW);
    tone(buzzer, 2000);
  }
  else
  { digitalWrite(ledVerde, LOW);
    digitalWrite(ledRed, LOW);
    noTone(buzzer);
  }
}
