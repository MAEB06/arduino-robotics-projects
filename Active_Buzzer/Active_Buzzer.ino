int buzzer = 12; //initialize the pin for buzzer

void setup() {
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600); //Sets the communication/baud rate for serial communication
}

void loop() {
  if (Serial.available() > 0) { //Checks if data is available
    char input = Serial.read(); //Reads input to serial
  
    //Very simple - if B is the input, buzz for 5 seconds and then stop
    if (input == 'B') {
      digitalWrite(buzzer,HIGH);
      delay(500);
      digitalWrite(buzzer,LOW);
    }
  }
//Simple code to loop through two different intervals of buzzing
  /*for (byte i=0;i<20;i++) {
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100); 

    Serial.print(i);
  }

  for(byte i=0;i<70;i++) {
    digitalWrite(buzzer,HIGH);
    delay(300);
    digitalWrite(buzzer,LOW);
    delay(300); 
    Serial.print(i);
  }*/


}
