/*
Pen lift using extruder motor direction pin
(Extruder module configured using "5th" stepper)
extruder_module_enable                       true             # Whether to activate the extruder module at all. All configuration is ignored if false
extruder_steps_per_mm                        140              # Steps per mm for extruder stepper
extruder_default_feed_rate                   600              # Default rate ( mm/minute ) for moves where only the extruder moves
extruder_acceleration                        50               # Acceleration for the stepper motor, as of 0.6, arbitrary ratio
extruder_max_speed                           1000             # mm^3/s

extruder_step_pin                            2.8              # Pin for extruder step signal
extruder_dir_pin                             2.13             # Pin for extruder dir signal
extruder_en_pin                              4.29             # Pin for extruder enable signal
epsilon_current                              1.5              # Extruder stepper motor current

*/
#include <Servo.h> 
const int buttonPin = A0;
const int ledPin = 13; 
const int servoPin = A1;
// servo angles range from 0 through 180
//const int servoAngleDown = 150;
//const int servoAngleUp = 120;
const int servoAngleDown = 180;
const int servoAngleUp = 120;
 

Servo servo; 

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT);     
  servo.attach(servoPin);
}

void loop(){
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {     
    digitalWrite(ledPin, HIGH);
    servo.write(servoAngleDown);
  } 
  else {
    digitalWrite(ledPin, LOW); 
    servo.write(servoAngleUp);
  }
}

