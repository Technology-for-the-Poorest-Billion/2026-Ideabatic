// This is the arduino C++ code used for the temperature monitoring system. Note this does not include code for adding on the RTC module
// Libraries
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <SD.h>

//temp sensor setup
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int deviceCount = 0;
float tempC;

// SD Card Setup
const int chipSelect = 10;
File myFile;

// time signature setup
unsigned long previousMillis = 0;
unsigned long elapsedMinutes = 0;

void setup() {

  Serial.begin(9600);

  // Starting temperature sensor library
  sensors.begin();
  // Finding the connected DS18B20 sensors
  Serial.println("Locating devices...");
  deviceCount = sensors.getDeviceCount();
  Serial.print(deviceCount);
  Serial.println(" device(s).");

  // Initialising SD card
  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    while (1);
  }
  Serial.println("SD card initialized.");
  // Creating file - name of file changed for each test
  myFile = SD.open("Tempn1.txt", FILE_WRITE);

  if (myFile) {
    myFile.println("Temperature Log");
    myFile.println("----------------------------");
    myFile.close();
    Serial.println("File created.");
  } else {
    // Provides error message on serial monitor, so can monitor SD card setup fails
    Serial.println("Error opening temps.txt");
  }
}

void loop() {
  unsigned long currentMillis = millis();
  // Loop to take reading every x seconds (note number is in miliseconds)
  if (currentMillis-previousMillis >= 600000){
    previousMillis = currentMillis;
    elapsedMinutes++;
 
    // Requesting temperature readings
    sensors.requestTemperatures();

    myFile = SD.open("Tempn1.txt", FILE_WRITE);

    if (myFile) {
      // Reading each sensor
      myFile.print(elapsedMinutes);
      Serial.print("Elapsed time");
      Serial.print(elapsedMinutes);
      for (int i = 0; i < deviceCount; i++) {
        tempC = sensors.getTempCByIndex(i);
        // Printing to Serial Monitor
        Serial.print("Sensor ");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(tempC);
        Serial.print(" °C | ");

        // Writing to SD card
        myFile.print(",");
        myFile.print(tempC);
      }

      myFile.println();
      myFile.close();

      Serial.println("Data saved to SD card.");
      Serial.println();
    }
    else {
      // Provides error message on serial monitor, so can monitor if data stops writing to SD card
      Serial.println("Error opening temps.txt");
    }
  }
}
