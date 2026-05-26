void setup() {
  // put your setup code here, to run once:
  pinMode(PC13, OUTPUT);
  pinMode(PB0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<256;i++)
  {
    analogWrite(PB0,i);
    delay(5);
  }
  delay(1000);
  for(int i=255;i>=0;i--)
  {
    analogWrite(PB0,i);
    delay(5);
  }
  delay(1000);
}
