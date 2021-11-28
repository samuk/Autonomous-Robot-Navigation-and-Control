//Target device (motor driver)
//The target device (motor driver) initializes and uses an instance of I2CCommander. Only one instance is needed for all attached motors: 
//The driver PCB is https://www.aliexpress.com/item/1005003311241556.html 
// PCB is documented here: https://github.com/ToanTech/Deng-s-foc-controller/tree/master/Dengs%20FOC%20V2.0/Dengs%20FOC%20V2.0%20DIY%E8%B5%84%E6%96%99
// It is controlling 2x 2205 motors https://www.aliexpress.com/item/4000784118326.html with AS5048A encoders

#include "Arduino.h"
#include <Wire.h>
#include <SimpleFOC.h>
#include "SimpleFOCDrivers.h"
#include "comms/i2c/I2CCommander.h"

// commander instance
uint8_t i2c_addr = 0x60;  // can be anything you choose
I2CCommander commander;
// interrupt callbacks
void onReceive(int numBytes) { commander.onReceive(numBytes); }
void onRequest() { commander.onRequest(); }


// ... other variables, like sensor, etc...
BLDCMotor motor = BLDCMotor(POLE_PAIRS);


void setup() {
    
    // ...other setup code

    Wire.setClock(400000);          // use same speed on controller device
    Wire.begin(i2c_addr, true);     // initialize i2c in target mode
    commander.addMotor(&motor);     // add a motor
    //commander.addMotor(&motor2);  // you could add more than one motor
    commander.init(i2c_addr);       // initialize commander
    Wire.onReceive(onReceive);      // connect the interrupt handlers
    Wire.onRequest(onRequest);

}
