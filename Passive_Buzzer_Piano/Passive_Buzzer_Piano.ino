//NOTE: This only covers some notes in a keyboard since it was just for testing the serial communication and passive buzzers

const char KEYS[3][7] = {
  {'q','w','e','r','t','y','u'},
  {'a','s','d','f','g','h','j'},
  {'z','x','c','v','b','n','m'}
};

const int SEMITONES[3][7] = {
  {0, 2, 4, 5, 7, 9, 11},
  {12, 14, 16, 17, 19, 21, 23},
  {24, 26, 28, 29, 31, 33, 35}
};

// Used as reference semitone for formula
const float C4 = 261.63;

int playKey(char key, bool sharp) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 7; col++) {
      if (KEYS[row][col] == key) {
        int semitone = SEMITONES[row][col] + (sharp ? 1 : 0);
        return (int)(C4 * pow(2.0, semitone / 12.0));
      }
    }
  }
  return 0;  //key not found
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char key = Serial.read();
    bool sharp = (key >= 'A' && key <= 'Z');
    if (sharp) key += 32; //sets back to lower case, accounted for by later adding 1 in semitone calculation
    
    int freq = playKey(key, sharp);
    if (freq > 0) {
      tone(8, freq, 300);
      Serial.println(key);
      delay(300);
    }
  }
}