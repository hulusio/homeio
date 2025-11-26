# smart solutions for smart homes

- This project is an IoT automation solution that provides precise position control of curtains via MQTT with a Stepper Motor (NEMA 17) using an ESP8266 NodeMCU development board.project is an IoT automation solution that provides precise position control of ation.

📜 About project
- MCU: ESP8266 (NodeMCU V3)
- Motor Driver: DRV8825
- Connection: MQTT (Uzaktan kontrol ve durum bildirimi için.)
- Software: ESP-IDF (ESP8266 RTOS SDK)
  
🛠️ 1. Hardware Setup and Connections
    1.1 Pin Connections
    |ESP8266 | GPIO_NUMBER | DRIVER_PIN | FUNCTION |
    D4          GPIO2      STEP        Motor step pulse singnal.
    D3          GPIO0      DIR         İdentifies motor turn direction.
    3V3         N/A        VDD         Drivers logic feed.
    GND         N/A        GND         Common ground.
    12V         N/A        VMOT        Motor power (12V).

    | Attempt | #1  | #2  |
    | ------- | --- | --- |
    | Seconds | 301 | 283 |
