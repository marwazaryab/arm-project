#include "base.ino"

int base_motor_pin1 = 3;
int base_motor_pin2 = 4;
int pwm_pin = 5;

base motor(base_motor_pin1, base_motor_pin2, pwm_pin); // intialize base

void setup() {
    Serial.begin(9600);  // Initialize serial communication 
    Serial.println("Motor control initialized."); // print message
}

void loop() {
  // put your main code here, to run repeatedly:

}

