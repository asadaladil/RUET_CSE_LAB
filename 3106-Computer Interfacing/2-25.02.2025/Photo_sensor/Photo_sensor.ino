int led=PB1;
int sensor=PB0;
void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(PC13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val=analogRead(sensor);
  val = map(val, 200, 900, 255, 0);
  val = constrain(val, 0, 255);
  analogWrite(led,val);
}
