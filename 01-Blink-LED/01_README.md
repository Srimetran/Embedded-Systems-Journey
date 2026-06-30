# 💡 Project 1 – Blink LED

## Objective

The objective of this project was to learn the fundamentals of embedded programming by controlling an external LED using an Arduino Uno. This project introduced the basic structure of an Arduino program, GPIO output, and timing using software delays.

---

## Background

One of the first skills every embedded engineer learns is how to control digital outputs. In this project, an external LED is connected to one of the Arduino's digital pins. The microcontroller repeatedly outputs a HIGH signal to turn the LED on and a LOW signal to turn it off, creating a blinking effect.

Although simple, this project introduces many of the core concepts used throughout embedded systems development.

---

## Concepts Learned

- Embedded C/C++
- Arduino Program Structure
- `setup()` and `loop()`
- GPIO Output
- `pinMode()`
- `digitalWrite()`
- `delay()`
- HIGH vs LOW Logic Levels
- LED Polarity (Anode & Cathode)
- Current Limiting Resistors
- Breadboard Wiring

---

## Hardware Used

- Arduino Uno R3
- Breadboard
- LED
- 220Ω Resistor
- Jumper Wires

---

## Circuit Overview

```
Arduino Pin 8
      │
      ▼
220Ω Resistor
      │
      ▼
LED (Anode)
      │
      ▼
LED (Cathode)
      │
      ▼
GND
```

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
    │
    ▼
Run loop()
    │
    ▼
Turn LED ON
    │
    ▼
Wait 1 Second
    │
    ▼
Turn LED OFF
    │
    ▼
Wait 1 Second
    │
    ▼
Repeat Forever
```

---

## Source Code

```cpp
void setup()
{
    pinMode(8, OUTPUT);
}

void loop()
{
    digitalWrite(8, HIGH);
    delay(1000);

    digitalWrite(8, LOW);
    delay(1000);
}
```

---

## Challenges Encountered

During development, the LED initially appeared to remain constantly on. This was caused by forgetting to include the second `delay()` after turning the LED off. Since the Arduino executes instructions extremely quickly, the LED switched back on almost immediately, making it appear as though it never turned off.

Adding the second delay allowed the OFF state to remain visible.

---

## Key Takeaways

This project established the foundation for future embedded systems development by introducing GPIO output and the basic structure of embedded firmware. It also reinforced the importance of understanding both the software and hardware involved in controlling electronic components.

---

## Future Improvements

- Control multiple LEDs simultaneously.
- Replace software delays with hardware timers.
- Implement non-blocking timing using `millis()`.
- Port the project to an STM32 microcontroller.
