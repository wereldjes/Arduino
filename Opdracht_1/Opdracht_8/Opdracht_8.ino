#include <IRremote.h>

const int ir = 11;                              //IR reader pin
const int led[] = {2, 4, 8, 10};                //Alle led pins
IRrecv receiver(ir);                            //IR receiver koppelen aan pin
decode_results result;                          //IR resultaat
int tempPin = 0;                                //Tijdelijke pin om aan te geven welke led geselecteerd is
int blinkTimes[] = {100, 500, 700};             //De verschillende knippertijden
unsigned long lastBlinkTime[] = {0, 0, 0};      //De tijd waarop een lamp als laatste geknipperd heeft
int ledStatus[] = {LOW, LOW, LOW};              //De Aan/Uit stand van ledlampen
int blinkLed[] = {0, 0, 0};                     //De leds die geknipperd moeten worden

void setup() {
    pinMode(led[0], OUTPUT);
    pinMode(led[1], OUTPUT);
    pinMode(led[2], OUTPUT);
    pinMode(led[3], OUTPUT);
    receiver.enableIRIn();

}

void loop() {
  blinkSpeed();                                 //blinkspeed() aanroepen zodat deze altijd in de loop staat en de leds laat knipperen
  
    if(receiver.decode(&result)) {              //Kijk of er een IR signaal gestuurd is
      if(tempPin == 0){                         //Kijk of er al een led geselecteed is
        ledBlink(result.value);                 //voer ledBlink() uit met als parameter de ingedrukte knop
      } else {
        selectSpeed(result.value, tempPin);     //Voer de selectSpeed() functie uit als er een led geselecteerd is
      }
      receiver.resume();                        //Stel de IR reader weer beschikbaar voor een nieuw signaal
    }

}

void ledBlink(int ledNumber) {                  //Parameter = geselecteerde knop op IR remote
    switch(ledNumber) {                         //Kijk welke knop er is ingedrukt en selecteer aan de hand van die knop de juiste led lamp, Zet tevens de led aan
      case 0xFF30CF:
          digitalWrite(led[0], HIGH);
          tempPin = led[0];
          break;
      case 0xFF18E7:
          digitalWrite(led[1], HIGH);
          tempPin = led[1];
          break;
      case 0xFF7A85:
          digitalWrite(led[2], HIGH);
          tempPin = led[2];
          break;
      case 0xFF10EF:
          digitalWrite(led[3], HIGH);
          tempPin = led[3];
          break;
    }
}

void selectSpeed(int blinkButton, int ledPin){  //Parameter blinkbutton: de knop die is ingedrukt om de snelheid in te stellen
  switch(blinkButton) {                         //Parameter ledPin: de pin die geselecteerd was in de ledBlink functie
    case 0xFF30CF:                              //Selecteer een snelheid aan de hand van de ingedrukte knop en zet de geselecteerde pin dan weer op 0
      blinkLed[0] = ledPin;
      tempPin = 0;
      break;
    case 0xFF18E7:
      blinkLed[1] = ledPin;
      tempPin = 0;
      break;
    case 0xFF7A85:
      blinkLed[2] = ledPin;
      tempPin = 0;
      break;
  }
}

void blinkSpeed() {                                       //Functie die aangeroepen word in de loop() om de led lampen altijd te laten knipperen
    unsigned long currentTime = millis();                 //Houd de tijd bij zolang het programma draait

    if(currentTime - lastBlinkTime[0] >= blinkTimes[0]){  //Huidige tijd - laatste knippertijd moet groter zijn of gelijk aan de geselecteerde tijd in blinkTimes list
      lastBlinkTime[0] = currentTime;                     //Laatste knippertijd gelijk zetten aan huidige tijd
      ledStatus[0] = (ledStatus[0] == LOW) ? HIGH : LOW;  //Kijk wat de status is van de Led en verander deze van aan naar uit of uit naar aan
      digitalWrite(blinkLed[0], ledStatus[0]);            //Schrijf de aan/uit waarde naar de geselecteerde ledlamp
    } 

    if(currentTime - lastBlinkTime[1] >= blinkTimes[1]){
      lastBlinkTime[1] = currentTime;
      ledStatus[1] = (ledStatus[1] == LOW) ? HIGH : LOW;
      digitalWrite(blinkLed[1], ledStatus[1]);
    }

    if(currentTime - lastBlinkTime[2] >= blinkTimes[2]){
      lastBlinkTime[2] = currentTime;
      ledStatus[2] = (ledStatus[0] == LOW) ? HIGH : LOW;
      digitalWrite(blinkLed[2], ledStatus[2]);
    } 
}
