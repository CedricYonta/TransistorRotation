/*
  Titre      : TransistorRotation
  Auteur     : Cedric Yonta
  Date       : 24/02/2022
  Description: 
  Version    : 0.0.1
*/



#include <Arduino.h>


const int analogInPin = A1; 
int led = 2;
unsigned long lasttime;
unsigned long presenttime;
const int STARTTIME = 1000;
int intensite = 0;



void setup() {
  Serial.begin(9600);// vitesse d'affichage du moniteur serie

  // definition du mode des pins
    pinMode(led , OUTPUT) ;
    pinMode(analogInPin, INPUT) ;


}

void loop() {
   presenttime = millis();

if ((presenttime-lasttime)  > STARTTIME ) // temps d'activation
{
  intensite = analogRead(analogInPin); //lecture de la broche analogue

  intensite = map(intensite, 0, 1023, 0,255 );// resolution de la valaeur

  Serial.println(intensite); // affichage sur le moniteur serie

  analogWrite(led,intensite);// allumer la laide en fonction de l'intensité
 
  lasttime = millis();
}

}