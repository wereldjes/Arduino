const int red = 11;
const int green = 9;
const int blue = 10;
const int button = 8;
int color = 0b000;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /*een loop in een loop in een loop. 
  eerst loopen over de groene kleur
  Daarna loopen over de blauwe kleur
  Daarna loopen over de rode kleur
  Als de loop over de rode kleur klaar is (heeft de 255 bereikt) dan gaat de teller van blauw 1 omhoog totdat deze ook 255 bereikt.
  In dat geval gaat de groene kleur weer 1 omhoog.
  Dit blijft doorgaan totdat alle kleuren 255 bereikt hebben en dan begint het weer opnieuw.*/
  for (int g = 0; g < 256; g += 50) {
    for (int b = 0; b < 256; b += 25) {
      for (int r = 0; r < 256; r += 10) {
        analogWrite(green, g);
        analogWrite(blue, b);
        analogWrite(red, r);

        //Serial scherm om de kleuren tracken en zeker te weten dat de kleuren veranderen zoals het hoort.
        Serial.print("Groen: ");
        Serial.println(g);
        Serial.print("Blauw: ");
        Serial.println(b);
        Serial.print("Rood: ");
        Serial.println(r);
      }
    }
  }
}
