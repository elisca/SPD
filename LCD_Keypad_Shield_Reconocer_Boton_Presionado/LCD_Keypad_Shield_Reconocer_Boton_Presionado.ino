#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);
int entrada,cod_puls;

void setup() {
  lcd.begin(16,2);
}

void loop() {
  switch(keypad_shield()){
    case -1:
      lcd.print("En reposo");
      break;
    case 0:
      lcd.print("Derecha");
      break;
    case 1:
      lcd.print("Arriba");
      break;
    case 2:
      lcd.print("Abajo");
      break;
    case 3:
      lcd.print("Izquierda");
      break;
    case 4:
      lcd.print("Select");
      break;
  }
  
  delay(50);
  lcd.clear();
}

int keypad_shield(){
  entrada=analogRead(A0);
  
  if(entrada>623&&entrada<=882)//Select
    return 4;
  if(entrada>431&&entrada<=623)//Izquierda
    return 3;
  if(entrada>237&&entrada<=431)//Abajo
    return 2;
  if(entrada>72&&entrada<=237)//Arriba
    return 1;
  if(entrada>=0&&entrada<=72)//Derecha
    return 0;
  
  return -1;//En reposo
}
