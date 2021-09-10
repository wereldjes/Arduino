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

  if(digitalRead(button) && !check) {
    check = 1;
    if(digitalRead(led)){
       digitalWrite(led, LOW); 
    } else {
        digitalWrite(led, HIGH);
    }
  }
  
  if(!digitalRead(button)) {
    check = 0; 
  }
  
  delay(50);
}
