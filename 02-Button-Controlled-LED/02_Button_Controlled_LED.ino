int buttonState;

void setup()
{
    pinMode(8, OUTPUT);
    pinMode(2, INPUT_PULLUP);
}

void loop()
{
    buttonState = digitalRead(2);

    if (buttonState == LOW)
    {
        digitalWrite(8, HIGH);
    }
    else
    {
        digitalWrite(8, LOW);
    }
}
