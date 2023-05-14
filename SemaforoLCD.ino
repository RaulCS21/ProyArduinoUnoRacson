#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,16,2); 

int LED_ROJO = 5;
int LED_AMARILLO = 6;
int LED_VERDE = 7;
int tiempo_restante = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("SEMAFORO");
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);  
}

void loop() {
  for(int i = 0; i < 3; i++) {
    if(i == 0) {
      digitalWrite(LED_VERDE, HIGH);
      tiempo_restante = 30;
       while(tiempo_restante > 0) {
          if(tiempo_restante>=10){
            lcd.setCursor(7,1);
            lcd.print(tiempo_restante);
            delay(1000);
            tiempo_restante--;
          }else{
            lcd.clear();
            lcd.setCursor(4,0);
            lcd.print("SEMAFORO");
            lcd.setCursor(8,1);
            lcd.print(tiempo_restante);
            delay(1000);
            tiempo_restante--;
          }
     	}
   	 }
     else if(i == 1) {
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_AMARILLO, HIGH);
        tiempo_restante = 5;
        while(tiempo_restante > 0) {
          lcd.setCursor(8,1);
          lcd.print(tiempo_restante);
          delay(1000);
          tiempo_restante--;
        }
       }
        else if(i == 2) {
          digitalWrite(LED_AMARILLO, LOW);
          digitalWrite(LED_ROJO, HIGH);
          tiempo_restante = 30;
          while(tiempo_restante > 0) {
            if(tiempo_restante>=10){
              lcd.setCursor(7,1);
              lcd.print(tiempo_restante);
              delay(1000);
              tiempo_restante--;
            }else{
              lcd.clear();
              lcd.setCursor(4,0);
              lcd.print("SEMAFORO");
              lcd.setCursor(8,1);
              lcd.print(tiempo_restante);
              delay(1000);
              tiempo_restante--;
            }
          }
        }
  }
}
