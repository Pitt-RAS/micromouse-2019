#ifndef FLOOD_FILL_H_
#define FLOOD_FILL_H_

#include <Arduino.h>

class FloodFill {
  public:
    FloodFill();
    uint8_t detectwall(int x, int y); //checks walls around cell at (x,y)
    update(int x, int y, uint8_t wall); //Updates cells at and around (x,y) with walls given in bool[]
    

  private: 
    int map[][];
    uint8_t walls;
    // Pinouts
    // static const uint8_t PWMA; //Right wheel
    // static const uint8_t PWMB; //Left wheel
    // static const uint8_t AIN1;
    // static const uint8_t AIN2;
    // static const uint8_t BIN1;
    // static const uint8_t BIN2;
    // static const uint8_t STBY; // LED Pin    
};

#endif
