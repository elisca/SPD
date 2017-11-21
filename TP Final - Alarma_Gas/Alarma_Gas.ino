//Librerias para contorl de LCD 16x2 con modulo I2C
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  //Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
                                   //Pines modulo I2C: Alimentacion: Fuente SDA A4 SCL A5
                                   //EP LCD 0x3F

const int MQ_DPIN = 2; //Pin digital deteccion gas
const int MQ_APIN = A0; //Pin analogico deteccion valores gas
const int MQ_DELAY = 500; //Retardo para actualizar si se detecta gas
 
void setup()
{
  lcd.init(); //lcd.init();

  lcd.backlight(); //Encender la luz de fondo.

  Serial.begin(9600); //Inicializa puerto serie para monitorear datos sensor
}
 
 
void loop()
{
  bool dGas= digitalRead(MQ_DPIN); //Booleano, detecta gas o no. Lectura digital MQ_DPIN
  float aGas= analogRead(MQ_APIN); //Flotante, detecta valores de gas devueltos por el sensor MQ_APIN

  lcd.clear(); //Borra el contenido de la pantalla LCD
  lcd.home(); //Situamos cursor en posicion (0,0).

  if (!dGas)//Detectado gas
  {
    Serial.println("Deteccion");
    lcd.print("GAS: POSITIVO");
  }
  else//Sin deteccion de gas
  {
    Serial.println("No detectado");
    lcd.print("GAS: NEGATIVO");
 }

  //Devuelve niveles de gas detectados en ppm

  lcd.setCursor(0,1); //Situa el cursor en el primer caracter de la fila inferior de la pantalla
  lcd.print(aGas);
  lcd.print(" ppm");

  Serial.print(aGas);
  Serial.println(" ppm");


  delay(MQ_DELAY);//Retardo aplicado para actualizar informacion del sensor
}
