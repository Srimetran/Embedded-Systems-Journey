# 💡 Project 3 – Toggle LED with Push Button

## Objective

The objective of this project was to control an LED using a push button. Unlike the previous project where the LED only stayed on while the button was pressed, this project introduces a toggle mechanism where each button press changes the LED between ON and OFF.

This project introduces the concept of **state-based programming**, a fundamental technique used in embedded systems.

---

## Background

A push button generates two events:

- Button Press
- Button Release

To ensure the LED only changes once per press, the program detects the transition from **LOW → HIGH** using a pull-down resistor configuration. The program stores both the current and previous button states to identify a new button press.

---

## Concepts Learned

- Digital Inputs
- Digital Outputs
- External Pull-Down Resistor
- GPIO Programming
- Boolean Variables
- State Variables
- Edge Detection
- Event-Driven Programming
- State-Based Logic

---

## Hardware Used

- Arduino Uno R3
- Breadboard
- Push Button
- LED
- 220Ω Resistor (LED)
- 10kΩ Resistor (Pull-Down)
- Jumper Wires

---

## Pin Assignments

| Component | Arduino Pin |
|----------|-------------|
| Push Button | Pin 2 |
| LED | Pin 8 |

---

## Circuit Overview

```text
5V
 │
Button
 │
Pin 2
 │
10kΩ
 │
GND

Pin 8
 │
220Ω
 │
LED
 │
GND
```

---

## Program Flow

```text
Read Button
     │
     ▼
New Button Press?
     │
     ▼
Toggle LED State
     │
     ▼
Update LED
     │
     ▼
Save Button State
     │
     ▼
Repeat
```

---

## Source Code

```cpp
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
```

---

## Challenges Encountered

One challenge was understanding why the program needed to remember the previous button state. Comparing the current and previous readings allowed the program to detect a new button press instead of repeatedly toggling the LED while the button was held down.

Another challenge was wiring an external pull-down resistor correctly so the input pin always had a defined voltage when the button was not pressed.

---

## Key Takeaways

This project introduced the concept of **state** versus **events**.

Instead of asking whether the button is currently pressed, the program determines whether a **new button press** has occurred. This approach is commonly used in embedded systems for handling user input reliably.

---

## Future Improvements

- Add software debouncing.
- Convert the project into reusable functions.
- Support multiple buttons.
- Control multiple LEDs.
- Replace polling with interrupts.
