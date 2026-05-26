
int red=PB0;
int green=PB1;
int blue=PB10;
int POT=PA7;
void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(POT,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int val=analogRead(POT);
  val=map(val,0,1023,0,255);
  if (val<=90)
  {
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
  }
  else if(val<=180)
  {
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(blue,LOW);
  }
  else
  {
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
  }

}
