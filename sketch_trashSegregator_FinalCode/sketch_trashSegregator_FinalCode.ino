#include <Servo.h>
#include <CheapStepper.h>

// inductive sensor
int inductivePin=2;
// capacitive sensor
int capacitivePin=3;
// ultrasonic
// int trig=4;
int ir=6;
int irVal;
// Servo
int servoPin = 5;
Servo myServo;

CheapStepper stepper (8,9,10,11);


void setup() {
    pinMode(ir,INPUT);
    // inductive sensor
    pinMode(inductivePin, INPUT);
    // capacitive sensor
    pinMode(capacitivePin, INPUT);
    // servo
    myServo.attach(servoPin);

    stepper.setRpm(12); 
    
    Serial.begin(9600);
}
 
void loop() {
    int inductiveValue = 1;
    int capacitiveValue;

    inductiveValue = digitalRead(inductivePin);
    capacitiveValue = digitalRead(capacitivePin);

    // inductiveValue = 1;
    Serial.print("Capacitive Sensor: ");
    Serial.println(capacitiveValue);
    Serial.print("Inductive Sensor: ");
    Serial.println(inductiveValue);
    irVal=digitalRead(ir);

    if (irVal == 0){
      if(inductiveValue == 0 && capacitiveValue == 1){ 
      Serial.println("METAL DETECTED");
      // delay(500);

      stepper.moveDegreesCCW (100);
      delay(1000); 

      myServo.write(90);
      delay(3000);

      stepper.moveDegreesCW (100);
      delay(1000); 
      }
      else if(capacitiveValue == 1){
        Serial.println("PLASTIC DETECTED");

        stepper.moveDegreesCW (100);
        delay(1000); 

        myServo.write(90);
        delay(3000);

        stepper.moveDegreesCCW (100);
        delay(1000); 
      }
      else{
        Serial.println("NO METAL DETECTED / PAPER");
        // delay(500);

        stepper.moveDegreesCW (185);
        delay(1000); 

        myServo.write(90);
        delay(3000);

        stepper.moveDegreesCCW (185);
        delay(1000); 
      }
    }

  myServo.write(0);

  delay(500);
}

