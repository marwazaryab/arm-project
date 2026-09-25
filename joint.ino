#include <Servo.h>

class joint
{
private:
    Servo motor;

    int pin;
    float current_position;
    float required_position;
    float offset;

public:
    joint(int servoPin, float servoOffset)
    {
        pin = servoPin;
        offset = servoOffset;

        current_position = 0;
        required_position = 0;
    }

    void begin()
    {
        motor.attach(pin);
        setAngle(0);
    }

    void setRequiredPosition(float angle)
    {
        required_position = angle;
    }

    void move()
    {
        setAngle(required_position);
    }

    void setAngle(float angle)
    {
        current_position = angle;

        float servo_angle = offset + angle;

        servo_angle = constrain(servo_angle, 0, 180);

        motor.write(servo_angle);
    }

    float getCurrentPosition()
    {
        return current_position;
    }

    float getRequiredPosition()
    {
        return required_position;
    }
};