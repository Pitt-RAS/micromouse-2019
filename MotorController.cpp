#include "MotorController.h"

const uint8_t MotorController::PWMA = A7;
const uint8_t MotorController::PWMB = A6;
const uint8_t MotorController::AIN1 = A8;
const uint8_t MotorController::AIN2 = A9;
const uint8_t MotorController::BIN1 = 11;
const uint8_t MotorController::BIN2 = 12;
const uint8_t MotorController::STBY = 13;

MotorController::MotorController(){
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
}

void MotorController::moveA(bool direction, uint8_t speed){
  if(direction){
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, speed);
  }else{
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, speed);
  }
}

void MotorController::moveB(bool direction, uint8_t speed){
  if(direction){
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, speed);
  }else{
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, speed);
  }
}

void MotorController::setStandby(int value){
  digitalWrite(STBY, value);
}
