void setup() {
  // put your setup code here, to run once:
  pinMode(PC13, OUTPUT);
  pinMode(PB0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blink();
  // Brightness();
  // loop_blinking();
}
void Brightness()
{
  for (int i=0; i<=255; i++)
  {
    analogWrite(PB0, i);
    delay(10);
  }
  for (int i=255; i>=0; i--)
  {
    analogWrite(PB0, i);
    delay(10);
  }
 
}
void blink()
{
  digitalWrite(PB0,HIGH);
  delay(500);
  digitalWrite(PB0,LOW);
  delay(500);
}
void loop_blinking()
{
  
  for(int i=1;i<=1000;i+=200)
  {
    digitalWrite(PC13,HIGH);
    delay(i);
    digitalWrite(PC13,LOW);
    delay(i);
  }
}

