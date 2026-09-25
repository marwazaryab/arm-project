#include <Arduino.h>
#include <math.h>

#include "base.ino"
#include "joint.ino"
#include "claw.ino"

const int base_step_pin = 3;
const int base_dir_pin = 4;

const int shoulder_pin = 6;
const int elbow_pin = 9;
const int claw_pin = 10;

const float motor_steps = 200.0;
const float microsteps = 16.0;
const float steps_per_degree = (motor_steps * microsteps) / 360.0;

base baseMotor(base_step_pin, base_dir_pin, steps_per_degree);

joint shoulder(shoulder_pin, 90);
joint elbow(elbow_pin, 90);

claw endEffector(claw_pin, 120, 40);

float link1 = 150;
float link2 = 130;
float baseHeight = 100;

float currentX = 0;
float currentY = 0;
float currentZ = 0;

float requiredX = 0;
float requiredY = 0;
float requiredZ = 0;

float requiredBase = 0;
float requiredShoulder = 0;
float requiredElbow = 0;

bool inverseKinematics(float x, float y, float z)
{
    float r = sqrt(x * x + y * y);
    float h = z - baseHeight;

    float distance = sqrt(r * r + h * h);

    if (distance > link1 + link2)
        return false;

    if (distance < abs(link1 - link2))
        return false;

    float cosElbow =
        (r * r + h * h - link1 * link1 - link2 * link2)
        / (2 * link1 * link2);

    cosElbow = constrain(cosElbow, -1.0, 1.0);

    float elbowAngle = acos(cosElbow);

    float shoulderAngle =
        atan2(h, r) -
        atan2(
            link2 * sin(elbowAngle),
            link1 + link2 * cos(elbowAngle)
        );

    requiredBase = atan2(y, x) * 180.0 / PI;
    requiredShoulder = shoulderAngle * 180.0 / PI;
    requiredElbow = elbowAngle * 180.0 / PI;

    return true;
}

bool setPosition(float x, float y, float z)
{
    requiredX = x;
    requiredY = y;
    requiredZ = z;

    if (!inverseKinematics(x, y, z))
    {
        Serial.println("Position cannot be reached");
        return false;
    }

    baseMotor.setAngle(requiredBase);

    shoulder.setRequiredPosition(requiredShoulder);
    elbow.setRequiredPosition(requiredElbow);

    shoulder.move();
    elbow.move();

    delay(700);

    currentX = x;
    currentY = y;
    currentZ = z;

    return true;
}

void pickUp(float x, float y, float z)
{
    float approachHeight = 50;

    endEffector.open();

    if (!setPosition(x, y, z + approachHeight))
        return;

    delay(500);

    if (!setPosition(x, y, z))
        return;

    delay(500);

    endEffector.close();

    delay(500);

    setPosition(x, y, z + approachHeight);
}

void dropOff(float x, float y, float z)
{
    float approachHeight = 50;

    if (!setPosition(x, y, z + approachHeight))
        return;

    delay(500);

    if (!setPosition(x, y, z))
        return;

    delay(500);

    endEffector.open();

    delay(500);

    setPosition(x, y, z + approachHeight);
}

void zeroArm()
{
    baseMotor.zero();

    shoulder.setAngle(0);
    elbow.setAngle(0);

    endEffector.open();

    currentX = 0;
    currentY = 0;
    currentZ = 0;

    delay(1000);
}

void setup()
{
    Serial.begin(9600);

    shoulder.begin();
    elbow.begin();
    endEffector.begin();

    zeroArm();

    Serial.println("Arm initialized");

    delay(1000);

    pickUp(180, 50, 50);
}

void loop()
{

}