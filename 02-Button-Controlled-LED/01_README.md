# 🔘 Project 2 – Button Controlled LED

## Objective

The objective of this project was to introduce digital inputs by controlling an LED using a push button. This project expanded on the previous Blink LED project by allowing user interaction with the microcontroller and introduced conditional logic within an embedded system.

---

## Background

Embedded systems continuously monitor inputs from sensors, switches, and other hardware devices before making decisions and controlling outputs.

In this project, a push button is connected to one of the Arduino's digital input pins using the Arduino's internal pull-up resistor (`INPUT_PULLUP`). The Arduino continuously checks whether the button is pressed and controls an external LED accordingly.

This project introduces the concept of reading digital inputs and making decisions based on hardware events.

---

## Concepts Learned

- Embedded C/C++
- Digital Inputs
- GPIO Input
- GPIO Output
- `digitalRead()`
- `digitalWrite()`
- `pinMode()`
- `INPUT_PULLUP`
- Pull-up Resistors
- Conditional Statements (`if / else`)
- Variables
- Digital Logic (HIGH vs LOW)
- Breadboard Wiring
- Basic Hardware Debugging

---

## Hardware Used

- Arduino Uno R3
- Breadboard
- Push Button
- LED
- 220Ω Resistor
- Jumper Wires

---

## Circuit Overview

```
Pin 8 ──► 220Ω Resistor ──► LED ──► GND

Pin 2 ──► Push Button ──► GND
```

The Arduino's internal pull-up resistor keeps Pin 2 HIGH until the button is pressed.

---

## Program Flow

```
Power On
    │
    ▼
Run setup()
    │
    ▼
Configure Pin 8 as OUTPUT
Configure Pin 2 as INPUT_PULLUP
    │
    ▼
Run loop()
    │
    ▼
Read Button State
    │
    ▼
Button Pressed?
    │
 ┌──┴──┐
 │     │
YES    NO
 │      │
 ▼      ▼
LED ON LED OFF
 │
 ▼
Repeat Forever
```

---

## Source Code

```cpp
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
```

---

## Challenges Encountered

While building this project, several debugging challenges were encountered:

- Initially misunderstood how the internal pull-up resistor worked.
- Accidentally connected the push button incorrectly, causing the button state to remain LOW.
- Used the Serial Monitor to verify the value returned by `digitalRead()`.
- Learned that with `INPUT_PULLUP`, pressing the button connects the input pin to GND, causing the input to read LOW instead of HIGH.

These debugging steps reinforced the importance of verifying both hardware and software when troubleshooting embedded systems.

---

## Key Takeaways

This project introduced the fundamental concept of digital inputs and demonstrated how embedded systems continuously read hardware, make decisions, and control outputs.

It also highlighted the importance of understanding circuit design, pull-up resistors, and systematic debugging techniques.

---

## Future Improvements

- Toggle the LED with a single button press.
- Implement software debouncing.
- Control multiple LEDs using different button combinations.
- Port the project to an STM32 development board.
