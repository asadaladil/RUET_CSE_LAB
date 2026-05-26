const int LED=PB0; 
const int BUTTON=PB1;
const int LED2=PB10; 
boolean lastButton = LOW; 

boolean currentButton = LOW; 

boolean ledOn = false;

void setup()
{
  pinMode (LED, OUTPUT);
  pinMode (LED2, OUTPUT); 
  pinMode (BUTTON, INPUT); 
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON); 
  if (last != current) 
  {
    current = digitalRead(BUTTON); 
  }
  return current; 
  }
void loop()
{
  currentButton = debounce(lastButton); 
  if (lastButton == LOW && currentButton == HIGH) 
  {
    ledOn = !ledOn; 
  }
  lastButton = currentButton; 
  digitalWrite(LED, ledOn); 
  digitalWrite(LED2, !ledOn); 
}