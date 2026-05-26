
int red=PB0;
int green=PB1;
int blue=PB10;
void setup() {
  // put your setup code here, to run once:
  pinMode(PC13, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Brightness(red);
  Brightness(green);
  Brightness(blue);
}

void Brightness(int x)
{
  for (int i=0; i<=255; i++)
  {
    analogWrite(x, i);
    delay(5);
  }
  delay(1000);
  for (int i=255; i>=0; i--)
  {
    analogWrite(x, i);
    delay(5);
  }
  delay(1000);
 
}