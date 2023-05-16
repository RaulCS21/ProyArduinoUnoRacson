#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_C6  1047

int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5,
  NOTE_E5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_C5,
  NOTE_D5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5,
  NOTE_E5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_C5,
  NOTE_D5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5,
  NOTE_E5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_C5,
  NOTE_D5, NOTE_E5, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_A5,
  NOTE_G5, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5,
  NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_C5
};

int noteDurations[] = {
  4, 4, 4, 2, 4, 4, 2,
  4, 4, 4, 2, 4, 4,
  4, 4, 2, 4, 4, 2,
  4, 4, 4, 2, 4, 4,
  4, 4, 2, 4, 4, 2,
  4, 4, 4, 2, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 2, 4
};

void setup() {
  
}

void loop() {
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(8, melody[i], noteDuration);
    delay(noteDuration);
    noTone(8);
    delay(noteDuration / 2);
  }
}
