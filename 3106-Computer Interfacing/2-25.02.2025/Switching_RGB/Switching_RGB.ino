void setup() {
  // put your setup code here, to run once:
  pinMode(PC13, OUTPUT);
  pinMode(PB0,OUTPUT);
  pinMode(PB1,OUTPUT);
  pinMode(PA7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blink();
  RGB();
  
}
void blink()
{
  // digitalWrite(PC13,HIGH);
  // delay(500);
  digitalWrite(PC13,LOW);
  // delay(500);
}
void RGB()
{
  int A[3]={PB0,PB1,PA7};
  for(int i=1;i<=3;i++)
  {
    digitalWrite(A[i],HIGH);
    delay(1000);
    digitalWrite(A[i],LOW);
  }
}


