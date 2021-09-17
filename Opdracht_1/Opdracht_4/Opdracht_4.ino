int const temp = A0;

void setup() {
    pinMode(temp, INPUT);
    //Geef het programma de mogelijkheid om het Serial scherm te gebruiken
    Serial.begin(9600);
}

void loop() {
    Serial.print("De temperatuur is: ");
    //lees de waarde uit van de analoge waarde. Zet deze waarde, tussen de 0 en 1023, om naar temperatuur tussen de 0 en 500 graden celsius.
    Serial.print(map(analogRead(temp), 0, 1023, 0, 500));
    Serial.println("°C");
    delay(1000);
}
