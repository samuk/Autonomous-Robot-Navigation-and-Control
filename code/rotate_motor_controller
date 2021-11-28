// Start by spinning both motors 10x rotations. This code should be run on the 'brain' ESP32, 
// corresponding code would run on the motor driver: https://github.com/simplefoc/Arduino-FOC-drivers/blob/master/src/comms/i2c/README.md#target-device-motor-driver
// These devices should be connected together on I2C pins.

#include "Arduino.h"
#include <Wire.h>
#include <SimpleFOC.h>
#include "SimpleFOCDrivers.h"
#include "comms/i2c/I2CCommanderMaster.h"

#define TARGET_I2C_ADDRESS 0x60
I2CCommanderMaster commander;

void setup() {
    
    // ...other setup code

    Wire.setClock(400000);          // use same speed on target device!
    Wire.begin();                   // initialize i2c in controller mode
    commander.addI2CMotors(TARGET_I2C_ADDRESS, 1);            // add target device, it has 1 motor
    //commander.addI2CMotors(TARGET_I2C_ADDRESS2, 1);         // you could add another target device on the same bus
    //commander.addI2CMotors(TARGET_I2C_ADDRESS, 1, &wire2);  // or on a different i2c bus
    commander.init();               // init commander
    Wire.onReceive(onReceive);      // connect the interrupt handlers
    Wire.onRequest(onRequest);

}
