# Smart-Dustbin
Simulated a multi-sensor-based smart dustbin using Arduino to detect motion, orientation, light, and temperature with interactive feedback.
# Smart Dustbin Simulation (Embedded IoT Project)
# Smart Dustbin Simulation (Multi-Sensor Embedded System)

This project simulates a **smart dustbin system** using Arduino, combining real-time environmental sensing, waste level monitoring, and safety feedback using various sensors and actuators. The system is built and simulated using **Tinkercad**, and the code is implemented in **C++ (Arduino)**.

---

## Features

### Sensor Modules
- **Ultrasonic Sensors (x2)**:  
  - One for **detecting approach** to auto-open the lid  
  - One for **measuring trash level**
- **IR Sensor**: Confirms object proximity for precise lid opening
- **Tilt Sensor**: Detects if the bin has **fallen over**
- **MQ135 Gas Sensor**: Detects **harmful gases** from decomposing waste
- **LDR (Light Sensor)**: Detects low-light conditions and turns on LED lighting
- **Temperature Sensor**: Measures ambient temperature for heating/cooling feedback

### Actuator Modules
- **Servo Motor (Lid Control)**: Opens/closes bin lid based on user proximity
- **Fan Servo**: Activates when temperature > 30°C
- **Heater Servo**: Activates when temperature < 10°C
- **LED Light**: Turns on when light level is low
- **Buzzer**: Alerts for:
  - Harmful gas
  - Tilt/fall detection

### LCD Interface (I2C 16x2)
- Real-time display of:
  - Bin lid state
  - Trash fill level
  - Gas levels
  - Temperature and heating/cooling response
  - Light level and LED state
  - Tilt status

---

## Components Used

- Arduino Uno
- Ultrasonic Sensors (2x)
- IR Sensor
- MQ135 Gas Sensor
- LDR (Light Sensor)
- Tilt Sensor
- TMP36 or LM35 Temperature Sensor
- Servo Motors (3x)
- Buzzer
- LEDs
- I2C 16x2 LCD Display
- Breadboard + Jumpers (simulated in Tinkercad)

---

## Functional Logic

| Feature             | Behavior                                                                 |
|---------------------|--------------------------------------------------------------------------|
| Lid Opening         | If user <30cm away and IR confirms presence, lid opens via servo        |
| Trash Level         | If <10cm remaining → "BIN FULL" LED alert                               |
| Gas Detection       | If gas >600 → "Harmful Gas" warning and buzzer activates                |
| Tilt Detection      | If tilt == 1 → "BIN HAS FALLEN!" on LCD and buzzer alert                |
| Temperature Logic   | >30°C → Fan ON, <10°C → Heater ON, else both OFF                        |
| Light Detection     | Light < 300 → LED ON                                                    |

---

## Simulation & Code

- [Tinkercad Simulation Link](https://www.tinkercad.com/things/bGz5uPH024A/editel?returnTo=%2Fdashboard&sharecode=_XlnP6aowTnA_ldBu66A92KBQwnj_nQMWEK9LOenr80)
- [Simulation Video](https://drive.google.com/file/d/1Qu_DzZt6DtZ1tAffLEceqxBBSKHJc7V1/view?usp=sharing)
- Code included in this repository (`smart_dustbin.ino`)

---

## Concepts Demonstrated

- Sensor data fusion
- Servo control for actuation
- Real-time embedded control logic
- Environmental monitoring
- Human-machine interaction using I2C LCD
- Safety and fault alerting with buzzer/LED

---

## Future Enhancements

- Add Wi-Fi module (ESP8266) to upload bin data to cloud
- Enable bin pickup alerts for municipal authorities
- Add solar power management logic
- Build a physical prototype from simulation


