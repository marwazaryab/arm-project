#include <Servo.h>

class claw
{
private:
    Servo motor;

    int pin;
    int open_position;
    int closed_position;
    int current_position;

public:
    claw(int servoPin, int openPosition, int closedPosition)
    {
        pin = servoPin;
        open_position = openPosition;
        closed_position = closedPosition;
        current_position = openPosition;
    }

    void begin()
    {
        motor.attach(pin);
        open();
    }

    void open()
    {
        motor.write(open_position);
        current_position = open_position;
        delay(400);
    }

    void close()
    {
        motor.write(closed_position);
        current_position = closed_position;
        delay(400);
    }

    int getPosition()
    {
        return current_position;
    }
};