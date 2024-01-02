#ifndef MELODIES_H
#define MELODIES_H

#include <Arduino.h>
#include "pitches.h"
#include "vector"

struct Melody {
  int tempo;
  std::vector<int> notes;
};

Melody zeldaLullabyMelody = {
  108,
  {
    NOTE_E4,2, NOTE_G4,4,
    NOTE_D4,2, NOTE_C4,8, NOTE_D4,8,
    NOTE_E4,2, NOTE_G4,4,
    NOTE_D4,-2,
    NOTE_E4,2, NOTE_G4,4,
    NOTE_D5,2, NOTE_C5,4,
    NOTE_G4,2, NOTE_F4,8, NOTE_E4,8,
    NOTE_D4,-2,
    NOTE_E4,2, NOTE_G4,4,
    NOTE_D4,2, NOTE_C4,8, NOTE_D4,8,
    NOTE_E4,2, NOTE_G4,4,
    NOTE_D4,-2,
    NOTE_E4,2, NOTE_G4,4,
    NOTE_D5,2, NOTE_C5,4,
    NOTE_G4,2, NOTE_F4,8, NOTE_E4,8,
    NOTE_F4,8, NOTE_E4,8, NOTE_C4,2,
    NOTE_F4,2, NOTE_E4,8, NOTE_D4,8,
    NOTE_E4,8, NOTE_D4,8, NOTE_A3,2,
    NOTE_G4,2, NOTE_F4,8, NOTE_E4,8,
    NOTE_F4,8, NOTE_E4,8, NOTE_C4,4, NOTE_F4,4,
    NOTE_C5,-2,
  }
};

Melody wiegenliedMelody = {
  76,
  {
    NOTE_E4,2, NOTE_G4,4,
    NOTE_D4,2, NOTE_C4,8, NOTE_D4,8,
    NOTE_E4,2, NOTE_G4,4,
    NOTE_D4,-2,
    NOTE_E4,2, NOTE_G4,4,
    NOTE_D5,2, NOTE_C5,4,
    NOTE_G4,2, NOTE_F4,8, NOTE_E4,8,
    NOTE_D4,-2,
    NOTE_E4,2, NOTE_G4,4,
    NOTE_D4,2, NOTE_C4,8, NOTE_D4,8,
    NOTE_E4,2, NOTE_G4,4,
    NOTE_D4,-2,
    NOTE_E4,2, NOTE_G4,4,

    NOTE_D5,2, NOTE_C5,4,
    NOTE_G4,2, NOTE_F4,8, NOTE_E4,8,
    NOTE_F4,8, NOTE_E4,8, NOTE_C4,2,
    NOTE_F4,2, NOTE_E4,8, NOTE_D4,8,
    NOTE_E4,8, NOTE_D4,8, NOTE_A3,2,
    NOTE_G4,2, NOTE_F4,8, NOTE_E4,8,
    NOTE_F4,8, NOTE_E4,8, NOTE_C4,4, NOTE_F4,4,
    NOTE_C5,-2,
  }
};

Melody silentNightMelody = {
  140,
  {
    NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
    NOTE_E4,-2, 
    NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
    NOTE_E4,-2, 
    NOTE_D5,2, NOTE_D5,4,
    NOTE_B4,-2,
    NOTE_C5,2, NOTE_C5,4,
    NOTE_G4,-2,

    NOTE_A4,2, NOTE_A4,4,
    NOTE_C5,-4, NOTE_B4,8, NOTE_A4,4,
    NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
    NOTE_E4,-2, 
    NOTE_A4,2, NOTE_A4,4,
    NOTE_C5,-4, NOTE_B4,8, NOTE_A4,4,
    NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
    NOTE_E4,-2, 
    
    NOTE_D5,2, NOTE_D5,4,
    NOTE_F5,-4, NOTE_D5,8, NOTE_B4,4,
    NOTE_C5,-2,
    NOTE_E5,-2,
    NOTE_C5,4, NOTE_G4,4, NOTE_E4,4,
    NOTE_G4,-4, NOTE_F4,8, NOTE_D4,4,
    NOTE_C4,-2,
  }
};

const Melody melodies[] = {
  zeldaLullabyMelody,
  wiegenliedMelody,
  silentNightMelody
};

#endif