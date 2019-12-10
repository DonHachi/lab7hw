#include <SoftwareSerial.h>
SoftwareSerial wirelessNetworkYT (10, 11);
char DAT = 0;
bool found = false;
bool on=false;
#define BUZZER_PIN 3

#define SILENCE  0
#define NOTE_B7  3951
#define NOTE_CS8 4435
#define NOTE_E8  5274

static const int notes[] = {
  NOTE_CS8, SILENCE,  NOTE_CS8, SILENCE,
  NOTE_B7,  NOTE_CS8, SILENCE,  NOTE_E8,
  SILENCE,  NOTE_CS8, SILENCE,  SILENCE
};

void setup() {
  // put your setup code here, to run once:
  wirelessNetworkYT.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
}


void loop() {
  if (not found and on) {
    //analogWrite(BUZZER_PIN,150);
    zordon();
  }
  if (wirelessNetworkYT.available()) {
    DAT = wirelessNetworkYT.read();
    if (DAT == '1') {
      found = false;
      on=true;
    }
    if (DAT == '2') {
      found = true;
      on=false;
      analogWrite(BUZZER_PIN, 0);
    }


  }
}
void zordon() {
  for (int i = 0; i < 12; i += 1) {
    if (notes[i] != SILENCE) {
      tone(BUZZER_PIN, notes[i], 102);
    }

    delay(150);
  }
  delay(500);
}
