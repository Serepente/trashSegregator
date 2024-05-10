#include <CheapStepper.h>

CheapStepper stepper (8,9,10,11);

void setup()
{
  
  stepper.setRpm(6); 
  delay(5000);
}

void loop() {

  stepper.moveDegreesCCW (10);
  delay(1000); 
  // stepper.moveDegreesCCW (90);
  // delay(5000);
}