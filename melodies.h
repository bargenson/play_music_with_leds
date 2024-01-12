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
    NOTE_G4, 4, NOTE_G4, 4, //1
    NOTE_AS4, -4, NOTE_G4, 8, NOTE_G4, 4,
    NOTE_AS4, 4, REST, 4, NOTE_G4, 8, NOTE_AS4, 8,
    NOTE_DS5, 4, NOTE_D5, -4, NOTE_C5, 8,
    NOTE_C5, 4, NOTE_AS4, 4, NOTE_F4, 8, NOTE_G4, 8,
    NOTE_GS4, 4, NOTE_F4, 4, NOTE_F4, 8, NOTE_G4, 8,
    NOTE_GS4, 4, REST, 4, NOTE_F4, 8, NOTE_GS4, 8,
    NOTE_D5, 8, NOTE_C5, 8, NOTE_AS4, 4, NOTE_D5, 4,

    NOTE_DS5, 4, REST, 4, NOTE_DS4, 8, NOTE_DS4, 8, //8
    NOTE_DS5, 2, NOTE_C5, 8, NOTE_GS4, 8,
    NOTE_AS4, 2, NOTE_G4, 8, NOTE_DS4, 8,
    NOTE_GS4, 4, NOTE_AS4, 4, NOTE_C5, 4,
    NOTE_AS4, 2, NOTE_DS4, 8, NOTE_DS4, 8,
    NOTE_DS5, 2, NOTE_C5, 8, NOTE_GS4, 8,
    NOTE_AS4, 2, NOTE_G4, 8, NOTE_DS4, 8,
    NOTE_AS4, 4, NOTE_G4, 4, NOTE_DS4, 4,
    NOTE_DS4, 2,
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

Melody greenslevesMelody = {
  70,
  {
    NOTE_G4,8,//1
    NOTE_AS4,4, NOTE_C5,8, NOTE_D5,-8, NOTE_DS5,16, NOTE_D5,8,
    NOTE_C5,4, NOTE_A4,8, NOTE_F4,-8, NOTE_G4,16, NOTE_A4,8,
    NOTE_AS4,4, NOTE_G4,8, NOTE_G4,-8, NOTE_FS4,16, NOTE_G4,8,
    NOTE_A4,4, NOTE_FS4,8, NOTE_D4,4, NOTE_G4,8,
    
    NOTE_AS4,4, NOTE_C5,8, NOTE_D5,-8, NOTE_DS5,16, NOTE_D5,8,//6
    NOTE_C5,4, NOTE_A4,8, NOTE_F4,-8, NOTE_G4,16, NOTE_A4,8,
    NOTE_AS4,-8, NOTE_A4,16, NOTE_G4,8, NOTE_FS4,-8, NOTE_E4,16, NOTE_FS4,8, 
    NOTE_G4,-2,
    NOTE_F5,2, NOTE_E5,16, NOTE_D5,8,

    NOTE_C5,4, NOTE_A4,8, NOTE_F4,-8, NOTE_G4,16, NOTE_A4,8,//11
    NOTE_AS4,4, NOTE_G4,8, NOTE_G4,-8, NOTE_FS4,16, NOTE_G4,8,
    NOTE_A4,4, NOTE_FS4,8, NOTE_D4,04,
    NOTE_F5,2, NOTE_E5,16, NOTE_D5,8,
    NOTE_C5,4, NOTE_A4,8, NOTE_F4,-8, NOTE_G4,16, NOTE_A4,8,

    NOTE_AS4,-8, NOTE_A4,16, NOTE_G4,8, NOTE_FS4,-8, NOTE_E4,16, NOTE_FS4,8,//16
    NOTE_G4,-2,
  }
};

Melody jigglypuffMelody = {
  85,
  {
    NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
    NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
    NOTE_FS5,-4, NOTE_E5,8, NOTE_FS5,4,
    NOTE_D5,-2,
    NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
    NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
    NOTE_FS5,-1,
    NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
    NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
    
    NOTE_FS5,-4, NOTE_E5,8, NOTE_FS5,4,
    NOTE_D5,-2,
    NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
    NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
    NOTE_FS5,-1,
  }
};

Melody songOfStormMelody = {
  108,
  {
    NOTE_D4,4, NOTE_A4,4, NOTE_A4,4,
    REST,8, NOTE_E4,8, NOTE_B4,2,
    NOTE_F4,4, NOTE_C5,4, NOTE_C5,4,
    REST,8, NOTE_E4,8, NOTE_B4,2,
    NOTE_D4,4, NOTE_A4,4, NOTE_A4,4,
    REST,8, NOTE_E4,8, NOTE_B4,2,
    NOTE_F4,4, NOTE_C5,4, NOTE_C5,4,
    REST,8, NOTE_E4,8, NOTE_B4,2,
    NOTE_D4,8, NOTE_F4,8, NOTE_D5,2,
    
    NOTE_D4,8, NOTE_F4,8, NOTE_D5,2,
    NOTE_E5,-4, NOTE_F5,8, NOTE_E5,8, NOTE_E5,8,
    NOTE_E5,8, NOTE_C5,8, NOTE_A4,2,
    NOTE_A4,4, NOTE_D4,4, NOTE_F4,8, NOTE_G4,8,
    NOTE_A4,-2,
    NOTE_A4,4, NOTE_D4,4, NOTE_F4,8, NOTE_G4,8,
    NOTE_E4,-2,
    NOTE_D4,8, NOTE_F4,8, NOTE_D5,2,
    NOTE_D4,8, NOTE_F4,8, NOTE_D5,2,

    NOTE_E5,-4, NOTE_F5,8, NOTE_E5,8, NOTE_E5,8,
    NOTE_E5,8, NOTE_C5,8, NOTE_A4,2,
    NOTE_A4,4, NOTE_D4,4, NOTE_F4,8, NOTE_G4,8,
    NOTE_A4,2, NOTE_A4,4,
    NOTE_D4,1,
  }
};

const Melody melodies[] = {
  zeldaLullabyMelody,
  wiegenliedMelody,
  silentNightMelody,
  greenslevesMelody,
  jigglypuffMelody,
  songOfStormMelody,
};

#endif