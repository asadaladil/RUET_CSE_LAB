
// Roll-2103064
const int POT = PB0;     // Potentiometer connected to A0
const int LED = PB1;
const int Green=PB10;      // LED connected to PWM pin 9

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(POT, INPUT);
}

void loop() {
  int potValue = analogRead(POT);               // Read potentiometer (0–1023)
  potValue = map(potValue, 0, 1023, 0, 255);
  potValue=constrain(potValue,0,255);   // Map to PWM range
  // analogWrite(LED, pwmValue);                   // Set LED brightness
  // delay(10);
  if(potValue<128)
  {
    analogWrite(Green,0);
    analogWrite(LED,potValue*2);
  }
  else {
    analogWrite(LED,0);
    analogWrite(Green, (255-potValue)*2);
  }
  delay(10);
}