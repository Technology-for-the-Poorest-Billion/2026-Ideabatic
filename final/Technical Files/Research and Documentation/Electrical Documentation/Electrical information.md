# Electrical Documentation

For this project, we are conducting significant thermal testing, so figuring out the test equipment and method is an important step.


## Previous thermal tests:
Last year’s (2025) Ideabatic group only conducted a single thermal test to check their calculated dimensions/new prototype did in fact stay within the correct range for ~24hrs. This test was conducted on their first prototype (i.e. not the SMILE GO we are now using) and just used a single DHT22 temperature sensor.

In March, Kitty conducted a thermal test on the current SMILE GO prototype (what we used) in a temperature chamber. She used bluetooth tempo disc sensors and placed 2 in the upper vaccine chambers and 2 in the lower vaccine chambers, with one outside to measure the ambient temperature. Note that the temperature chamber did not work successfully and led to a large variation in ambient temperature.

## Our test setup:
Our test setup aims to be similar to Kitty’s: We are placing 2 temperature sensors in upper vaccine chambers and 2 in bottom ones, with one measuring the ambient temperature

The system needs to: measure the temperatures at multiple locations in the carousel, timestamp the data, store the data and allow the frequency of measurements taken to be adjusted.

Temperature sensor: We initially hoped to use the same BlueMaestro sensors as they were wireless and had a resolution of 0.1 degrees. Unfortunately, Kitty was unable to find them. So we looked at alternative options. We assessed cost, necessary accuracy, availability, shape, and the required circuit. After assessing different options, we settled on DS18B20 temperature sensors. These have an accuracy of 0.5°C, work in a range of -55°C to 125°C and multiple sensors can be connected to one Arduino pin because they use different addresses.

| Sensor                        | Accuracy (°C) | Cost (per unit) | Source      | Other Details                                                         |
| ----------------------------- | ------------- | --------------- | ----------- | --------------------------------------------------------------------- |
| DHT11                         | ±2.0          | £7.12           | RS          | Minimum temperature of 0°C                                            |
| DHT22                         | ±0.5          | £7.25           | Amazon only | Larger temperature range; 2-second readout delay                      |
| DS18B20                       | ±0.5          | £6.22           | RS          | Single data wire allows daisy-chaining; only one Arduino pin required |
| RTD Pt100                     | ~±0.15        | £38.48          | RS          | Higher accuracy and more features than required for this application  |
| Tempo Disc Blue (BlueMaestro) | ±0.3          | £30.99          | Amazon      | Large temperature range; Bluetooth connectivity (no wires required)   |
| Tempo Disc Red (BlueMaestro)  | ±0.3          | £33.99          | Amazon      | Bluetooth connectivity (no wires required)                            |

Table of possible Sensors to use

The setup involved 5x Ds18B20 temperature sensors with their wires going to GND, 5v & pin 2, where pin 2 was connected to 5v via a 4.7k pullup resistor. An SD card module was also connected to the arduino. The arduino was then powered by a computer which also displayed the temperatures in serial monitor as well as writing it to the SD card

| Supplies                     | Quantity        | Source        |
| ---------------------------- | --------------- | ------------- |
| DS18B20 Temperature Sensors  | 5 (6 purchased) | RS Components |
| Breadboard                   | 1               | CUED          |
| Arduino Uno                  | 1               | CUED          |
| SD Card Module               | 1               | CUED          |
| 4.7 kΩ Resistor              | 1               | CUED          |
| RTC (Real-Time Clock) Module | 1               | RS Components |

Table of components used/purchased 

| Component Pin        | Arduino Pin                                                           |
| -------------------- | --------------------------------------------------------------------- |
| SD Card Module: CS   | 10                                                                    |
| SD Card Module: SCK  | 13                                                                    |
| SD Card Module: MOSI | 11                                                                    |
| SD Card Module: MISO | 12                                                                    |
| SD Card Module: VCC  | 5V                                                                    |
| SD Card Module: GND  | GND                                                                   |
| DS18B20 Sensor: VCC  | 5V                                                                    |
| DS18B20 Sensor: GND  | GND                                                                   |
| DS18B20 Sensor: DATA | 2 (all sensors daisy-chained together with a 4.7 kΩ pull-up resistor) |

The components were initially connected to a breadboard, and tested with the code individually. After ascertaining that all the components (sensors, SD card module) were working, the circuit was soldered to a stripboard using headers to attach it to the arduino. The code was then successfully implemented. 


Initial Bread board setup



Soldered circuit

We conducted a test equipment experiment to run overnight to check the equipment worked over several hours and to make sure the dyson PC would provide power overnight.

We then ran a control test aiming to get the same results Kitty did, showing significant asymmetry between the top and bottom of the cooler. This allowed us to compare our subsequent test results with this control test to assess the impact our modifications had. 

## Equipment test setup

# General test setup
- 4 DS18B20 temperature sensors arranged in the vaccine chambers
- In most tests, positioned such that 2 are in top compartments ( not the very top) and 2 in bottom compartments
- Sensors are positioned such that they are all roughly at the same position in each chamber and roughly the same distance from the wall in contact with the icepack
- Sensors are resting on foam and then taped to remain in position
- Their wires had the outer insulation stripped so that the wires can easily exit the SMILE Go through the edges , without significantly disrupting the seal
- A 5th sensor is attached to the cooler such that it measures the ambient temperature
- All sensors and an SD card module are soldered to a board connected to an arduino
- The arduino is powered by a PC so that data can read in real time on the serial monitor and is stored as a txt file on the SD card
- Once the temperature sensors are attached and it's checked that they are all reading correctly, the vaccine carousel is placed into the cooler, and the end lid screwed on. The icepack is then added and that lid screwed on.
- Cooler is orientated horizontally such that icepack lies horizontal and door is on the top face
- Cooler then placed in a tray for safety - in case of leakage, shouldn’t be near PC
- Backup power supply: in event of PC not being available, add RTC module and 6xAA battery connector to barrel jack to arduino


