

// Roll-2103064
int Button=PB10;
int Red=PB0;
int Green=PB1;

void setup() {
  // put your setup code here, to run once:
  // pinMode(PC13, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Button, INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(Button)==LOW)
  {
    digitalWrite(Green, LOW);
    digitalWrite(Red,HIGH);
  }
  else 
  {
    digitalWrite(Red, HIGH);
    digitalWrite(Green, LOW);
  }
}
