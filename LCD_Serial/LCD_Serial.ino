
#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("Msg Recebida: ");
}

void loop() {
  if(Serial.available() > 0){
    String mensagem = Serial.readString();
    Serial.print("Mensagem recebida: ");
    Serial.print(mensagem);
    Serial.println();

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(mensagem);
  
  //delay(1000);
  }
}

