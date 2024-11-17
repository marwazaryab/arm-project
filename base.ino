#include <Arduino.h>

class base
{

private:
    int motor_pin1;
    int motor_pin2;
    int pwm_pin;

public:
    base(int pin1, int pin2, int pwm)
    {
        motor_pin1 = pin1;
        motor_pin2 = pin2;
        pwm_pin = pwm;

        // Set the motor pins as outputs
        pinMode(motor_pin1, OUTPUT);
        pinMode(motor_pin2, OUTPUT);
        pinMode(pwm_pin, OUTPUT);
    }

    void rotateClockwise(int speed) {
        digitalWrite(motor_pin1, HIGH);
        digitalWrite(motor_pin2, LOW);
        analogWrite(pwm_pin, speed);  // Speed control (0 to 255)
    }

    void rotateCounterClockwise(int speed) {
        digitalWrite(motor_pin1, LOW);
        digitalWrite(motor_pin2, HIGH);
        analogWrite(pwm_pin, speed);  // Speed control (0 to 255)
    }

    void stop() {
        analogWrite(pwm_pin, 0);  // Stop the motor
    }


};

