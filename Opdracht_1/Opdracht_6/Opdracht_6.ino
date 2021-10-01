#include <Servo.h>

Servo servo;
int positie = 0;
const int buttonOne = 2;
const int buttonTwo = 7;

void setup() {
  servo.attach(11);
  pinMode(buttonOne, INPUT);
  pinMode(buttonTwo, INPUT);
}

void loop() {
  delay(100);
  if(digitalRead(buttonOne) && digitalRead(buttonTwo)) {      //Check of knop 1 & 2 zijn ingedrukt
    turnServo(buttonOne + buttonTwo);
  } else if(digitalRead(buttonTwo)) {                         //Check of knop 2 is ingedrukt
    turnServo(buttonTwo);
  } else if(digitalRead(buttonOne)) {                         //Check of knop 1 is ingedrukt
    turnServo(buttonOne); 
  }
}

void turnServo(int i) {                                       //methode om de servo te bewegen, gebruikt de pin van de knop om te zien welke case uitgevoerd moet worden
  switch(i) {
      case 2:                                                 //Voer dit uit als knop 1 is ingedrukt
          movement(8, 0);
          break;
      case 7:                                                 //Voer dit uit als knop 2 is ingedrukt
          movement(4, 0);
          break;
        
      case 9:                                                 //Voer dit uit als knop 1 & 2 zijn ingedrukt
          movement(8, 2000);
          break;
    }
}

void  movement(int j, int x) {
    for(positie = 0; positie <= 120; positie+=1){             //Beweeg de servo naar 120 graden met een delay uit de parameter (j)
      servo.write(positie);
      delay(j);
    }

    delay(x);                                                 //Gebruik een extra delay als deze is meegegeven als parameter (x)

    for(positie = 120; positie >= 0; positie-=1) {            //beweeg de servo van 120 graden naar 0 met een delay uit de parameter (j)
      servo.write(positie);
      delay(j);
    }
}
