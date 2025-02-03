# Autonomous Sumo Bot

## Components Needed
- **Arduino Nano**
- **L298N Motor Driver**
- **2 DC Motors** (for left and right wheels)
- **3 Ultrasonic Sensors** (HC-SR04)
- **2 IR Sensors** (for edge detection)
- **1 Push Button** (for start)
- **Power Supply** (e.g., 7.4V LiPo battery for motors, 5V for Arduino)
- **Jumper Wires**
- **Breadboard** (optional, for easier connections)

## Wiring Diagram

### 1. L298N Motor Driver Connections

| L298N Pin | Arduino Nano Pin | Motor Connection |
|-----------|----------------|----------------|
| IN1       | D2             | Motor Left 1  |
| IN2       | D3             | Motor Left 2  |
| IN3       | D4             | Motor Right 1 |
| IN4       | D5             | Motor Right 2 |
| VCC       | 5V (Arduino)   | -             |
| GND       | GND (Arduino)  | -             |
| 12V       | Battery (+)    | -             |
| GND       | Battery (-)    | -             |
| 5V Output | -              | Not used      |

**Motor Connections:**
- Connect the left motor to **OUT1** and **OUT2**.
- Connect the right motor to **OUT3** and **OUT4**.

### 2. Ultrasonic Sensor Connections

| Ultrasonic Sensor | Arduino Nano Pin |
|-------------------|-----------------|
| **Front Sensor**  |                 |
| VCC              | 5V              |
| GND              | GND             |
| Trig             | D6              |
| Echo            | D7              |
| **Left Sensor**  |                 |
| VCC              | 5V              |
| GND              | GND             |
| Trig             | D8              |
| Echo             | D9              |
| **Right Sensor** |                 |
| VCC              | 5V              |
| GND              | GND             |
| Trig             | D10             |
| Echo             | D11             |

### 3. IR Sensor Connections

| IR Sensor | Arduino Nano Pin |
|-----------|-----------------|
| **Left IR**  |                 |
| VCC        | 5V              |
| GND        | GND             |
| OUT        | D12             |
| **Right IR** |                 |
| VCC        | 5V              |
| GND        | GND             |
| OUT        | D13             |

### 4. Button Connection

| Button Pin | Arduino Nano Pin |
|------------|-----------------|
| One Side   | A0              |
| Other Side | GND             |

> Use a **pull-down resistor (10kΩ)** if your button doesn't have one built-in.

### 5. Power Connections

#### **Arduino Nano:**
- Connect **5V** and **GND** to the respective pins on the Arduino.

#### **L298N:**
- Connect **12V** to the positive terminal of your motor battery.
- Connect **GND** to the negative terminal of your motor battery and the Arduino GND.

## Visual Wiring Diagram
```
Arduino Nano
-----------------
| D2  -> IN1 (L298N) -> Motor Left 1
| D3  -> IN2 (L298N) -> Motor Left 2
| D4  -> IN3 (L298N) -> Motor Right 1
| D5  -> IN4 (L298N) -> Motor Right 2
| D6  -> Front Trig
| D7  -> Front Echo
| D8  -> Left Trig
| D9  -> Left Echo
| D10 -> Right Trig
| D11 -> Right Echo
| D12 -> Left IR OUT
| D13 -> Right IR OUT
| A0  -> Button
| 5V  -> VCC (Sensors, L298N)
| GND -> GND (Sensors, L298N, Button)
-----------------
```

## Power Supply Notes
- Use a **7.4V LiPo battery** for the motors (connected to the L298N's **12V and GND** pins).
- Use a **5V regulator** or a **separate 5V battery** for the Arduino Nano and sensors if your motor battery voltage is too high for the Arduino.

## Testing the Wiring
1. Upload the code to the **Arduino Nano**.
2. Power on the system.
3. Press the button and wait **5 seconds**.
4. Test the following:
   - **Motors**: Verify forward, reverse, left, and right movements.
   - **Ultrasonic Sensors**: Place an object in front, left, and right to ensure the robot responds correctly.
   - **IR Sensors**: Place the robot near a black line to ensure it reverses and turns away.
   - **Button**: Ensure the robot starts only after the button is pressed and the **5-second delay** is complete.

## License
This project is licensed under the **MIT License** – see the [LICENSE](LICENSE) file for details.

## Code
The full source code for the Autonomous Sumo Bot can be found in the file [Control.ino](**Control.ino**) in this repository.

---

🚀 **Enjoy building your Autonomous Sumo Bot!** 🤖
