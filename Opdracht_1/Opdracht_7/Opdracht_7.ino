#include <Servo.h>

const int trigger = 8;
const int echo = 7;
Servo servo;
float distance;
float time;

void setup() {
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    servo.attach(11);
}

void loop() {
    turnServoOnDistance();                          //Roep turnServoOnDistance methode aan
}

void turnServoOnDistance() {
    digitalWrite(trigger, HIGH);                    //Zet de trigger pin aan
    delay(10);                                      //Wacht 10ms
    digitalWrite(trigger, LOW);                     //Zet de trigger pin uit
  
    time = pulseIn(echo, HIGH);                     //Check hoelang de echo pin HIGH was
  
    distance = time / 58;                           //Bereken de afstand met de tijd dat de echo pin op HIGH stond
  
    if(distance < 4 || distance > 10) {             //Kijk of de afstand kleiner is dan 4cm of groter dan 10cm
      servo.write(90);                              //Reset de servo naar standaardpositie 90 graden als bovenstaande comment waar is
    } else {
      servo.write(map(distance, 4, 10, 0, 180));    //Maak een mapping aan: gebruik de afstanden tussen 4 en 10 cm en hecht daar de waardes 0 tot 180 graden aan
    }                                               //Laat de servo draaien afhankelijk van hoeveel cm er tussen de ultrasoon en het object zit
}
