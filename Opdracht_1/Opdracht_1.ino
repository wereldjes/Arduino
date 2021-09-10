const int ledPinOne = 1;
const int ledPinTwo = 2;
const int ledPinThree = 3;
const int ledPinFour = 4;
const int ledPinFive = 5;
const int ledPinSix = 6;
const int ledPinSeven = 7;
const int ledPinEight = 8;

void setup()
{
  pinMode(ledPinOne, OUTPUT);
  pinMode(ledPinTwo, OUTPUT);
  pinMode(ledPinThree, OUTPUT);
  pinMode(ledPinFour, OUTPUT);
  pinMode(ledPinFive, OUTPUT);
  pinMode(ledPinSix, OUTPUT);
  pinMode(ledPinSeven, OUTPUT);
  pinMode(ledPinEight, OUTPUT);
}

//In de loop wordt de light methode aangesproken voor elke LED. Deze loopt op naar 8 en daarna weer af naar 1
void loop()
{
  light(ledPinOne);
  light(ledPinTwo);
  light(ledPinThree);
  light(ledPinFour);
  light(ledPinFive);
  light(ledPinSix);
  light(ledPinSeven);
  light(ledPinEight);
  light(ledPinSeven);
  light(ledPinSix);
  light(ledPinFive);
  light(ledPinFour);
  light(ledPinThree);
  light(ledPinTwo);
  
}

//Deze methode zet de LED aan en weer uit met een delay van 0.1 seconde
void light(int pin) {
  digitalWrite(pin, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(pin, LOW);
  delay(100); // Wait for 1000 millisecond(s)
}
