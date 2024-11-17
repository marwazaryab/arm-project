#include <Arduino.h>

class base
{

private:
    int motorPin1;
    int motorPin2;
    int pwmPin;

public:
    base(int pin1, int pin2, int pwm)
    {
        motorPin1 = pin1;
        motorPin2 = pin2;
        pwmPin = pwm;

        // Set the motor pins as outputs
        pinMode(motorPin1, OUTPUT);
        pinMode(motorPin2, OUTPUT);
        pinMode(pwmPin, OUTPUT);
    }

    void rotateClockwise(int speed) {
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        analogWrite(pwmPin, speed);  // Speed control (0 to 255)
    }

    void rotateCounterClockwise(int speed) {
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        analogWrite(pwmPin, speed);  // Speed control (0 to 255)
    }

    void stop() {
        analogWrite(pwmPin, 0);  // Stop the motor
    }


};

