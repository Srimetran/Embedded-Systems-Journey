int buttonState;
int lastButtonState = LOW;
bool ledState = false;

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  buttonState = digitalRead(2);

  if (buttonState == HIGH && lastButtonState == LOW)
  {
    ledState = !ledState;
  }

  if (ledState)
  {
    digitalWrite(8, HIGH);
  }
  else
  {
    digitalWrite(8, LOW);
  }

  lastButtonState = buttonState;
}
