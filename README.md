# Home-Automation-System-PIC18F4520
This program was designed and developed in **C language** using PIC18F4520 microchip

##How the program runs
When the system is boot up, it will prompt the user to press “A” from the keypad to key in password. There is a limit of three attempts. For every incorrect key input, it will registered as one attempt and will keep track of the number of attemps. If the attempt is used up, a buzzer will sound and it will display text on the LCD that calls is sent. 

If the user with access it will be able to armed or disarmed the system. If the system is armed,  either push button or touch sensor is activated it will sound buzzer and display text on the LCD that call is sent. If the system is not armed, it will be an energy saving system. Where the light bulb will fully be lit up when push button or touch sensor is activated and after a minute has passed shown by the seven segments as a timer. it will become dimmer.


## A schematic drawing of the connection to the microchip.
![Schema Drawing](home_automation_schema_pinout.png)
