// Sets the PWM pins to be used on board
#define BLUE 3
#define GREEN 5
#define RED 6


void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

//define variables for brightness of each colour
int redVal;
int greenVal;
int blueVal;

void loop() {
  #define delayTime 10 //Time for fade between each colour

  redVal = 255;
  greenVal = 0;
  blueVal = 0;

  for (int i = 0; i < 255; i++) {
    redVal -= 1;
    greenVal += 1;

    analogWrite(RED, redVal);
    analogWrite(GREEN, greenVal);
    delay(delayTime);
  }

  for (int i = 0; i < 255; i++) {
    greenVal -= 1;
    blueVal += 1;

    analogWrite(GREEN, greenVal);
    analogWrite(BLUE, blueVal);
    delay(delayTime);
  }

  for (int i = 0; i < 255; i++) {
    blueVal -= 1;
    redVal += 1;

    analogWrite(BLUE, blueVal);
    analogWrite(RED, redVal);
    delay(delayTime);
  }


}
