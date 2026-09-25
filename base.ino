#include <Arduino.h>

class base
{
private:
    int step_pin;
    int dir_pin;

    long current_steps;
    float steps_per_degree;

public:
    base(int stepPin, int dirPin, float stepsPerDegree)
    {
        step_pin = stepPin;
        dir_pin = dirPin;
        steps_per_degree = stepsPerDegree;
        current_steps = 0;

        pinMode(step_pin, OUTPUT);
        pinMode(dir_pin, OUTPUT);
    }

    void setAngle(float angle)
    {
        long target_steps = angle * steps_per_degree;
        long difference = target_steps - current_steps;

        if (difference >= 0)
            digitalWrite(dir_pin, HIGH);
        else
            digitalWrite(dir_pin, LOW);

        long steps = abs(difference);

        for (long i = 0; i < steps; i++)
        {
            digitalWrite(step_pin, HIGH);
            delayMicroseconds(800);
            digitalWrite(step_pin, LOW);
            delayMicroseconds(800);
        }

        current_steps = target_steps;
    }

    void zero()
    {
        current_steps = 0;
    }

    float getAngle()
    {
        return current_steps / steps_per_degree;
    }
};