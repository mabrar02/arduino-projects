#include <FastLED.h>
#define NUM_LEDS 64
#define DATA_PIN 6

CRGB leds[NUM_LEDS];
const int trigPin = 3;
const int echoPin = 2;

long duration;
int distance;


void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  distance = constrain(distance, 0, 20);
  Serial.print("Distance: ");
  Serial.println(distance);


  int colorValue = map(distance, 0, 20, 0, 255);

  for(int i = 0; i<NUM_LEDS; i++){
    leds[i] = CHSV(colorValue, 255, 255);
  }
   FastLED.show();
   delay(50);

}
