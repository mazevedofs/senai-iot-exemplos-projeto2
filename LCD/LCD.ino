// Inclusão da biblioteca do sensor
// Essa biblioteca não vem por padrão com o arduino e
// precisa ser instalada pelo gerenciador de bibliotecas
#include <LiquidCrystal.h>

// Inicializa o objeto do sensor ultrasônico
// Usando as portas 12 e 13 para trigger e echo
// Ultrasonic ultrasonic(9, 10);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int TOTAL_VAGAS = 10;

void setup() {
 // Inicializa a porta Serial
 Serial.begin(9600);

 lcd.begin(16, 2);
 lcd.setCursor(0, 0);
 lcd.print("ON: ");
 lcd.setCursor(0, 1);
 lcd.print("OFF: ");

}

void loop() {
 // Lê o valor do sensor
 //  int distancia = ultrasonic.distanceRead();
 if (Serial.available() > 0) {
   String mensagem = Serial.readString();
   Serial.print("Mensagem recebida: ");
   Serial.print(mensagem);
   Serial.println();
   // Escreve o valor da distância no painel Serial
   //    lcd.setCursor(5, 0);
   //    lcd.print("           ");
   //
   //
   //    lcd.setCursor(5, 1);
   //    lcd.print("           ");


   //    lcd.setCursor(4, 0);
   //    lcd.print(mensagem);
   //    // mostrar vagas disponiveis
   //
   //    lcd.setCursor(5, 1);
   //    lcd.print(mensagem);
   //    // mostrar vagas ocupadas
   for (int i = 0; i <= TOTAL_VAGAS; i++) {
     lcd.clear();
     lcd.setCursor(5, 0);
     lcd.print(i);
   }
   delay(1000);
 }
}


//  lcd.clear();
//  for(int i = 0; i < TOTAL_VAGAS; i++){
//   // vagas[i] = 1;??????
//    //SET CURSOR 00
//clear
//    // MANDA INFO LED "LIVRES: i"
//for a--
//set cursor 0,1
//manda info LED"livres : a"

//
//for (int i = 0; TOTAL_VAGAS; i++) {
//  lcd.clear();
//  set.cursor(0 , 0;
//  lcd.print("Livres:", i);
//}
