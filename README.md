# Autonomous-Robot-Navigation-and-Control


## Table of Contents

- [Description](#description)
- [Overview](#overview)
    - [Tasks](#tasks)
    - [System Description](#system-description)


## Description
In this project, I copy and adapt a robot navigate autonomously through a series of tasks, using Arduino, motors, encoders and distance sensors.<br>


This is an adaptation of a project [documented in this post](https://yaelbenshalom.github.io/mechatronics/index.html) for more information about the project.


## Overview

### Tasks
1. Navigating through a maze
2. Driving through changing-slope way, keeping constant roll
3. Following curved wall, keeping constant distance
4. Driving on slope with changing gradient, keeping constant speed
5. Locating and reaching the finish line flag

### Proposed System Description
I propose several components to control the robot motion:
1. Arduino running on - [ESP32 Dev C board](https://www.olimex.com/Products/IoT/ESP32/ESP32-DevKit-LiPo/open-source-hardware) for 'brain'
2. Motors & encoders:
    - [2205 BLDC motor and encoder](https://www.aliexpress.com/item/4000784118326.html) - One on each rear wheel to activate and control the motion
    - [Deng Driver board](https://www.aliexpress.com/item/1005003311241556.html) running [this I2C code](https://github.com/simplefoc/Arduino-FOC-drivers/tree/master/src/comms/i2c#target-device-motor-driver)
    - Servo motor - Located on the front of the vehicle and used to rotate the TOF sensor to desired scanning angle
3. Sensors
    - IR sensor - One on each side of the vehicle to measure side distance
    - TOF (Time of Flight) sensor - Assembled on the servo motor to scan the surrounding space
    - US (ultrasonik) sensor - Located on the top of the vehicle to measure distance from objects above the vehicle
    - IMU 9250 (9 DOF) - Measures orientation (Gyroscope) and acceleration (Accelerometer). Compass is not in use
4. Led matrix - Indicates mission number and mission success/fail

The system components:
    Diagram TBD

Arduino pin usage:
    Diagram TBD
    
The autonomous vehicle:
Similar to 
    <p align="center">
        <img align="center" src="https://github.com/YaelBenShalom/Autonomous-Robot-Navigation-and-Control/blob/main/images/vehicle.jpg" width="60%">
    </p>
