int LED_ROJO 		    = 5;
int LED_AMARILLO     = 6;
int LED_VERDE		    = 7;

void setup() {
   	pinMode(LED_ROJO, OUTPUT);
   	pinMode(LED_AMARILLO, OUTPUT);
   	pinMode(LED_VERDE, OUTPUT);
}

void loop() {
   for(int i = 0; i < 3; i++) {
       	if(i == 0) {
          digitalWrite(LED_VERDE, HIGH);
          delay(30000);
      	}
     	else if(i == 1) {
          digitalWrite(LED_VERDE, LOW);
          digitalWrite(LED_AMARILLO, HIGH);
          delay(5000);
      	}
      	else if(i == 2) {
          digitalWrite(LED_AMARILLO, LOW);
          digitalWrite(LED_ROJO, HIGH);
          delay(30000);
      	}
    }
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_AMARILLO, HIGH);
    delay(5000);
  }
