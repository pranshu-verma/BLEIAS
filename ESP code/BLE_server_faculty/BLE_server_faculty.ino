/*
    Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleServer.cpp
    Ported to Arduino ESP32 by Evandro Copercini
    updates by chegewara
*/

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "835a7880-9b50-4948-bc8e-b5fb449b2adb"
#define CHARACTERISTICSS_UUID "f2db914b-0110-4ebf-86d1-cd07c69cb47e"
#define CHARACTERISTICSSS_UUID   "f724be6d-c5e0-49bb-92f0-b62fa37cfd4a"

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  BLEDevice::init("BLE Faculty room no. 5");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);


BLECharacteristic *aCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

 
  BLECharacteristic *bCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTICSS_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTICSSS_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

/* Faculty information */
aCharacteristic->setValue("Dr. Bhaskar Thakker is a Professor of Electronics and Telecommunication Department with highest qualification as Ph.D. in Embedded Systems from Indian Institute of Technology (IIT) Delhi. He has published around 25-30 articles in renowned journals and has a teaching experience of around 21 years.");                                       
bCharacteristic->setValue("He takes Advanced Embedded System Design and IoT and Applications courses for M.Tech students which include both theory sessions and practical sessions. Apart from this he also takes embedded systems course for B.Tech students as well as mentors a few groups of Final Year for their B.Tech project.");

/* Time table */
pCharacteristic->setValue("1 0 1 1 0 0 1 0, 0 0 1 1 0 1 0 0, 1 0 1 0 1 0 1 0, 0 1 1 0 1 0 1 0, 1 0 1 0 0 0 0 0");

  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  BLEAdvertising *aAdvertising = BLEDevice::getAdvertising();   
  BLEAdvertising *bAdvertising = BLEDevice::getAdvertising();
  
  pAdvertising->addServiceUUID(SERVICE_UUID);
  
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
}
