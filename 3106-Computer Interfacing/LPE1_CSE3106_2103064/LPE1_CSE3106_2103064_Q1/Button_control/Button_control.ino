

// Roll-2103064
int Button=PB1;
int Red=PB0;
int Green=PB10;

void setup() {
  // put your setup code here, to run once:
  // pinMode(PC13, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Button, INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  bool val=digitalRead(Button);
  digitalWrite(Green, val);
 digitalWrite(Red,!val);
}
