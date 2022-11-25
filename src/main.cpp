/*
  Titre      : TransistorRotation
  Auteur     : Cedric Yonta
  Date       : 24/02/2022
  Description: 
  Version    : 0.0.1
*/



/*#include <Arduino.h>


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

}*/

#include <Arduino.h>
const int BOUTTON_LED_PIN = 5;
const int RELAIS = 6;
int ETAT_LED;

void allume()
{
    ETAT_LED = !ETAT_LED;
}

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(BOUTTON_LED_PIN, INPUT);
    pinMode(RELAIS, OUTPUT);

    attachInterrupt(digitalPinToInterrupt(BOUTTON_LED_PIN), allume, CHANGE);
}

void loop()
{

    digitalWrite(RELAIS, ETAT_LED);
}