#ifndef MOTOR_CONTROLLER_H_
#define MOTOR_CONTROLLER_H_

#include <Arduino.h>

class MotorController {
  public:
    MotorController();
    void moveA(bool direction, uint8_t speed);
    void moveB(bool direction, uint8_t speed);
    void setStandby(int value);

  private: 
    // Pinouts
    static const uint8_t PWMA; //Right wheel
    static const uint8_t PWMB; //Left wheel
    static const uint8_t AIN1;
    static const uint8_t AIN2;
    static const uint8_t BIN1;
    static const uint8_t BIN2;
    static const uint8_t STBY; // LED Pin    
};

#endif
