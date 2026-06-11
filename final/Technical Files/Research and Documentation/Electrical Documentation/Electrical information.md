# Electrical Documentation

For this project, we are conducting significant thermal testing, so figuring out the test equipment and method is an important step.


## Previous thermal tests:
Last year’s (2025) Ideabatic group only conducted a single thermal test to check their calculated dimensions/new prototype did in fact stay within the correct range for ~24hrs. This test was conducted on their first prototype (i.e. not the SMILE GO we are now using) and just used a single DHT22 temperature sensor.
In March, Kitty conducted a thermal test on the current SMILE GO prototype (what we used) in a temperature chamber. She used bluetooth tempo disc sensors and placed 2 in the upper vaccine chambers and 2 in the lower vaccine chambers, with one outside to measure the ambient temperature. Note that the temperature chamber did not work successfully and led to a large variation in ambient temperature.

## Our test setup:
Our test setup aims to be similar to Kitty’s: We are placing 2 temperature sensors in upper vaccine chambers and 2 in bottom ones, with one measuring the ambient temperature
The system needs to: measure the temperatures at multiple locations in the carousel, timestamp the data, store the data and allow the frequency of measurements taken to be adjusted.
Temperature sensor: We initially hoped to use the same BlueMaestro sensors as they were wireless and had a resolution of 0.1 degrees. Unfortunately, Kitty was unable to find them. So we looked at alternative options. I assessed cost, necessary accuracy, availability, shape, and the required circuit. After assessing different options, we settled on DS18B20 temperature sensors. These have an accuracy of 0.5°C, work in a range of -55°C to 125°C and multiple sensors can be connected to one Arduino pin because they use different addresses.

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
