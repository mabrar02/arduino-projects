#include <Servo.h>

Servo servoX; 
Servo servoY;

int joystickXPin = 0; 
int joystickYPin = 1;
int pushPin = 4;
int ledPin = 5;

int valX; 
int valY;

void setup() {
  servoX.attach(9);
  servoY.attach(8);

  pinMode(ledPin, OUTPUT);
  pinMode(pushPin, INPUT);
}

void loop() {
  // digitalWrite(ledPin, HIGH);
  valX = analogRead(joystickXPin);       
  valX = map(valX, 0, 1023, 0, 180);

  valY = analogRead(joystickYPin);       
  valY = map(valY, 0, 1023, 0, 180);
       
  servoX.write(valX);
  servoY.write(valY);

  if(digitalRead(pushPin) == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }                 
  delay(200);                         
}