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
const int servoAnglePinDown = A4;
const int servoAnglePinUp = A5;
 

Servo servo; 

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT);     
  servo.attach(servoPin);
}

void loop(){
  int buttonState = digitalRead(buttonPin);
  int val;
  digitalWrite(ledPin, buttonState);

  if (buttonState == HIGH) {     
    val = analogRead(servoAnglePinUp);            // reads the value of the potentiometer (value between 0 and 1023) 
  } 
  else {
    digitalWrite(ledPin, LOW); 
    val = analogRead(servoAnglePinDown);
  }
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  servo.write(val);
}

