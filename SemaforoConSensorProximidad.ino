const int LED_ROJO = 4;
const int LED_AMARILLO = 5;
const int LED_VERDE = 6;
const int TRIGGER_PIN = 7;
const int ECHO_PIN = 7;

int inches = 0;
int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
}

void loop() {
  cm = 0.01723 * readUltrasonicDistance(TRIGGER_PIN, ECHO_PIN);
  inches = cm / 2.54;
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  
  delay(100);
  
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  
  if (cm <= 80) {
    digitalWrite(LED_ROJO, HIGH);
  } else if (cm > 80 && cm <= 200) {
    digitalWrite(LED_AMARILLO, HIGH);
  } else {
    digitalWrite(LED_VERDE, HIGH);
  }
}
