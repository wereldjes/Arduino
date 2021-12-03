const int led[] = {4, 3, 2};
int blinkTime[] = {1000, 6000, 12000};
unsigned long int lastBlinkTime[] = {0, 0, 0};
int ledStatus[] = {LOW, LOW, LOW};
char value = 0;

void setup() {
    Serial.begin(9600);
    pinMode(led[0], OUTPUT);
    pinMode(led[1], OUTPUT);
    pinMode(led[2], OUTPUT);
}

void loop() {
  if(Serial.available()) {
    value = Serial.read();
  }

  if(value == '0') {
      off();
    } else if (value == '1') {
      on();
  }
}

void on() {
    digitalWrite(led[2], LOW);
    digitalWrite(led[0], HIGH);
    delay(12000);
    digitalWrite(led[1], HIGH);
    digitalWrite(led[0], LOW);
    delay(6000);
    digitalWrite(led[1], LOW);
    digitalWrite(led[2], HIGH);
    delay(12000);
}

void off() {
  unsigned long int currentTime = millis();
  
  if(currentTime - lastBlinkTime[1] >= blinkTime[0]) {
   lastBlinkTime[1] = currentTime;
   ledStatus[1] = (ledStatus[1] == LOW) ? HIGH : LOW;
   digitalWrite(led[1], ledStatus[1]);
  }
  
}
