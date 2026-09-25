# 🎯 3D Printed Robotic Arm

As a summer project, we designed, manufactured, and programmed a multi-axis robotic arm capable of positioning and picking up cube objects. The project combined mechanical design, electronics, and controls to create a fully 3D-printed robotic system.

### Features

- Multi-axis movement using a NEMA 17 stepper motor and servo motors
- Inverse kinematics for Cartesian (X, Y, Z) positioning
- Automatic joint positioning based on a desired end-effector location
- Startup homing and zeroing
- Claw end effector for picking up and manipulating cube objects
- Real-time tracking of current and target joint positions

# 💻 CAD

The arm was designed from scratch using Autodesk Inventor and went through several design iterations before reaching its final version. The mechanical assembly was designed around 3D-printable components, servo-driven joints, and a stepper-driven rotating base.

![FinalArmAssem](https://github.com/user-attachments/assets/de482a99-742b-481d-852d-a92b68024cbe)

# ⚙️ Controls

The arm is controlled by providing a desired end-effector position in Cartesian coordinates:

`(x, y, z)`

The inverse kinematics system calculates the required base, shoulder, and elbow angles needed to reach the position. The controller tracks the current and required position of each joint and commands the motors to move the end effector to the target.

The rotating base is driven by a NEMA 17 stepper motor, while servo motors control the shoulder, elbow, and claw.

# 🦾 Inverse Kinematics

The arm converts a desired 3D position into individual joint angles using inverse kinematics. The base angle is calculated from the X and Y coordinates, while the shoulder and elbow angles are calculated using the geometry and link lengths of the arm.

This allows the arm to be controlled using a target position rather than manually specifying the angle of every joint.

# 🎭 Contributors

Marwa Zaryab, William Dang, and Andy Dai.