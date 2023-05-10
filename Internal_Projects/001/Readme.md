# Internal Project 001 aka CarProto

In order to showcase what our team or department can offer, we will be creating a project that will serve as the representation of our team’s strength and skills.

## Project Output

A car prototype that will have sensors and motor control functionalities. The ECU’s will communicate via CAN and there will be one Main Controller that will handle the data queries.  There will be an ECU that will handle the motor control for the direction and speed while another ECU will handle the control of the sensors and light signals of the car prototype.

## Sytems

* **Main Controller** : 
    Serve as the main control of the system.
* **Sub-system 1** : 
    Handles the accelerometer
    * Ultrasonic sensor
    * Airbag
    * LEDs (signal lights)
* **Sub-system 2** : 
    Handles the motor control of the system
    * Servo
    * Stepper/DC

## Directory Structure

* Root repo dir
    * Internal_Projects
        * 001
            * ecu_m : Main ECU related codes
            * ecu_1 : ECU 1 related codes
            * ecu_2 : ECU 2 related codes
            * ecu_3 : extra
            * include : **ALL** include files in ECU 1. 2 and 3 (either extrnal or internal or opensource)
            * doc : **ALL** document files in ECU 1, 2 amd 3 (schematics, datasheet, research output, doxygen output)
