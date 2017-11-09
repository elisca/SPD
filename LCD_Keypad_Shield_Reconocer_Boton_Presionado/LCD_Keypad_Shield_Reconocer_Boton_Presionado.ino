#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);
int entrada;

void setup() {
  lcd.begin(16,2);
}

void loop() {
  entrada=analogRead(A0);

  if(entrada>882&&entrada<=1023)
    lcd.print("En reposo");
  if(entrada>623&&entrada<=882)
    lcd.print("Select");
  if(entrada>431&&entrada<=623)
    lcd.print("Izquierda");
  if(entrada>237&&entrada<=431)
    lcd.print("Abajo");
  if(entrada>72&&entrada<=237)
    lcd.print("Arriba");
  if(entrada>=0&&entrada<=72)
    lcd.print("Derecha");
  
  delay(50);
  lcd.clear();
}
