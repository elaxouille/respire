/* 
Arduino Uno / RESPIRE / projet TVS
Utilisation de la bibliothèque Stepper pour contrôler le moteur

version alpha
/!\ VERSION TEST === SURCHAUFFE /!\

### T.V.S. ###


 */

#include <Stepper.h>

int enA  = 3;  // Enable pin 1 on Motor Control Shield   
int enB  = 9;  // Enable pin 2 on Motor Control Shield   
int dirA = 2;  // Direction pin dirA on Motor Control Shield
int dirB = 8;  // Direction pin dirB on Motor Control Shield


const int stepsPerRevolution = 200;  

// Initialisation de la classe Stepper
Stepper myStepper(stepsPerRevolution, dirA, dirB);            

void setup() {
  myStepper.setSpeed(60); // 60 < n < ~120 (sinon pas assez fluide)

  // Allumage du moteur
  pinMode(enA, OUTPUT);
  digitalWrite (enA, HIGH);

  pinMode(enB, OUTPUT);
  digitalWrite (enB, HIGH);  
}

void loop() {
  
  for (int i = 0; i < 6; i++) {
    myStepper.step(stepsPerRevolution*6);
    myStepper.step(-stepsPerRevolution*6);
  }
  delay(12000);
}
