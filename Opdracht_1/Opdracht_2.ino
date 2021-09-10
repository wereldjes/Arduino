const int led = 11;
const int button = 1;
int check = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{

  if(digitalRead(button) && !check) { //kijk of de knop is ingedrukt en of check op false staat
    check = 1;                        //zet de check op 1 zodat de if statement niet herhaald kan worden
    if(digitalRead(led)){             //kijk of de led al aan staat
       digitalWrite(led, LOW);        //zet de led uit
    } else {
        digitalWrite(led, HIGH);      //zet de led anders aan
    }
  }
  
  if(!digitalRead(button)) {          //kijk of de knop is uitgedrukt en zet de check weer op 0 zodat het if statement weer uitgevoerd kan worden bij een button press
    check = 0; 
  }
  
  delay(50);
}
