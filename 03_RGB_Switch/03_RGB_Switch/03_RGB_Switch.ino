// Init RGB-Color pins
int red = 18;
int green = 15;
int blue = 14;

int redIntensity = 0;

void rgb()
{
  analogWrite(red, redIntensity);
  analogWrite(green, 255 - redIntensity);
  analogWrite(blue, 0);

  delay(10);
  redIntensity += 1;

  if(redIntensity > 255) { 
    redIntensity = 0; 
  }
}

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT),
  pinMode(blue, OUTPUT);
}

void loop() {
  rgb();
  /*
  digitalWrite(red, HIGH);
  delay(600);
  digitalWrite(green, HIGH);
  delay(600);
  digitalWrite(blue, HIGH);
  delay(600);
  digitalWrite(red, LOW);
  delay(600);
  digitalWrite(green, LOW);
  delay(600);
  digitalWrite(blue, LOW);
  delay(600);
  */
}
