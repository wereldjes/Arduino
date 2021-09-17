const int ledOne = 2;
const int ledTwo = 3;
const int ledThree = 4;
const int ledFour = 5;
const int ledFive = 6;
const int ledSix = 7;
const int ledSeven = 8;
const int pot = A5;

void setup() {
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
  pinMode(ledFour, OUTPUT);
  pinMode(ledFive, OUTPUT);
  pinMode(ledSix, OUTPUT);
  pinMode(ledSeven, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {

  switch(analogRead(pot)) {
    case 100 ... 200:
      digitalWrite(ledOne, 1);
      digitalWrite(ledTwo, 0);
      digitalWrite(ledThree, 0);
      digitalWrite(ledFour, 0);
      digitalWrite(ledFive, 0);
      digitalWrite(ledSix, 0);
      digitalWrite(ledSeven, 0);
      break;
    case 201 ... 300:
      digitalWrite(ledTwo, 1);
      digitalWrite(ledThree, 0);
      digitalWrite(ledFour, 0);
      digitalWrite(ledFive, 0);
      digitalWrite(ledSix, 0);
      digitalWrite(ledSeven, 0);
      break;
    case 301 ... 400:
      digitalWrite(ledThree, 1);
      digitalWrite(ledFour, 0);
      digitalWrite(ledFive, 0);
      digitalWrite(ledSix, 0);
      digitalWrite(ledSeven, 0);
      break;
    case 401 ... 500:
      digitalWrite(ledFour, 1);
      digitalWrite(ledFive, 0);
      digitalWrite(ledSix, 0);
      digitalWrite(ledSeven, 0);
      break;
    case 501 ... 600:
      digitalWrite(ledFive, 1);
      digitalWrite(ledSix, 0);
      digitalWrite(ledSeven, 0);
      break;
    case 601 ... 700:
      digitalWrite(ledSix, 1);
      digitalWrite(ledSeven, 0);
      break;
    case 701 ... 2000:
      digitalWrite(ledSeven, 1);
      break;
    default:
      digitalWrite(ledOne, 0);
      digitalWrite(ledTwo, 0);
      digitalWrite(ledThree, 0);
      digitalWrite(ledFour, 0);
      digitalWrite(ledFive, 0);
      digitalWrite(ledSix, 0);
      digitalWrite(ledSeven, 0);
      break;
  }
}
