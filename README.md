# smart solutions for smart homes

- This project is an IoT automation solution that provides precise position control of curtains via MQTT with a Stepper Motor (NEMA 17) using an ESP8266 NodeMCU development board.project is an IoT automation solution that provides precise position control of ation.

📜 About project
- MCU: ESP8266 (NodeMCU V3)
- Motor Driver: DRV8825
- Connection: MQTT (Uzaktan kontrol ve durum bildirimi için.)
- Software: ESP-IDF (ESP8266 RTOS SDK)
**- To see requirements about this project see: co-req-v001.xlsx
- To see software and hardware funtion implementations see : co-design (drawio)**
  
🛠️ 1. Hardware Setup and Connections
    1.1 Pin Connections
      
      |  ESP8266 | GPIO_NUMBER | DRIVER_PIN | FUNCTION                           |
      |  D4      |    GPIO2    |   STEP     |   Motor step pulse singnal.        |
      |  D3      |    GPIO0    |   DIR      |   İdentifies motor turn direction. |
      |  3V3     |    N/A      |   VDD      |   Drivers logic feed.              |
      |  GND     |    N/A      |   GND      |   Common ground.                   |  
      |  12V     |    N/A      |   VMOT     |   Motor power (12V).               |

  ⚠️ Note: Use GPIO2 and  GPIO0  pins while defining  ESP-IDF software.
  
  1.2 DRV8825 Current Setup (Vref Calibration)
  - The DRV8825's potentiometer (Vref) is used to set the maximum current ($I_{max}$) the motor can draw. Incorrect adjustment will cause the motor to overheat or lose steps.
  - Fomula:
          $$V_{ref} = I_{max} \times 0.5$$
  - Thanks to: https://how2electronics.com/control-stepper-motor-with-drv8825-driver-esp8266/
  -  See connection bellow 

     *<img width="1309" height="806" alt="drv_connecion_with_esp" src="https://github.com/user-attachments/assets/1e97b947-a46c-4a0e-82b8-6765609ea0ec" />
**

3. Sowftware
 - Dowload ESP8266_SDK from  [https://github.com/platformio/platform-espressif8266/tree/master/examples?utm_source=platformio.org&utm_medium=docs](https://github.com/espressif/esp-idf)
 - Be sure anout python3  installed on your system
 - Then run $ . /c/esp/ESP8266_RTOS_SDK/export.sh on root project path
 - build your project with idf.py build
 
 - <img width="835" height="791" alt="image" src="https://github.com/user-attachments/assets/2fffa6dc-d936-4e45-b0b4-bdf26e429b0a" />


 - <img width="1223" height="421" alt="image" src="https://github.com/user-attachments/assets/b9e42ec9-86f1-4ae9-832e-3befcae2d62b" />


 
   
          
  
