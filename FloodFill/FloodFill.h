#ifndef FLOOD_FILL_H_
#define FLOOD_FILL_H_

#include <Arduino.h>

struct cell{
    int val;    //Cells needed to get to center
    bool n;     //Wall to north
    bool s;     //Wall to south
    bool e;     //Wall to east
    bool w;     //Wall to west
    bool v;     //Cell was visited 
}

class FloodFill {
  public:
    FloodFill();
    bool* detectwall(int x, int y); //checks walls around cell at (x,y)
    update(int x, int y, bool* walls); //Updates cells at and around (x,y) with walls given in bool[]
    

  private: 
    cell map[][];
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
