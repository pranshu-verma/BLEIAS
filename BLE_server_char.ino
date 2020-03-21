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
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define CHARACTERISTICSS_UUID "f2db914b-0110-4ebf-86d1-cd07c69cb47e"
#define CHARACTERISTICSSS_UUID   "f724be6d-c5e0-49bb-92f0-b62fa37cfd4a"
//#define CHARACTERISTICSSSS_UUID "835a7880-9b50-4948-bc8e-b5fb449b2adb"

//#define SERVICES_UUID       "f4999a5b-1b4d-405e-863e-09f318b529e0"
//#define CHARACTERSTICS_UUID "e04ce4a6-0ef7-4328-903c-1e4c2b465778"


void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
/* Device Name for Faculty room */
//  BLEDevice::init("BLE Faculty room no. 5");

/* Device Name for Labs */  
  BLEDevice::init("BLE CCN Lab");
  BLEServer *pServer = BLEDevice::createServer();

  BLEService *pService = pServer->createService(SERVICE_UUID);
//  BLEService *mService = pServer->createService(SERVICES_UUID);
// First Service

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

 //  BLECharacteristic *rCharacteristic = pService->createCharacteristic(
//                                         CHARACTERISTICSSSS_UUID,
//                                         BLECharacteristic::PROPERTY_READ |
//                                         BLECharacteristic::PROPERTY_WRITE
//                                       );
                                       
// Second service's characteristics
//   BLECharacteristic *qCharacteristic = mService->createCharacteristic(
//                                         CHARACTERSTICS_UUID,
//                                         BLECharacteristic::PROPERTY_READ |
//                                         BLECharacteristic::PROPERTY_WRITE
//                                       );

/* Characteristics for Faculty room */
// aCharacteristic->setValue("Name: Dr. Bhaskar Thakkar, Designation: Professor of Electronics and Telecommunication department in Symbiosis Institute of Technology.");                                       
// bCharacteristic->setValue("Subject expertise: Embedded System Design, Joining date: DD/MM/YYYY");
// pCharacteristic->setValue("1 1 0 0 0 1 1 0");

/* Characteristics for Labs */
aCharacteristic->setValue("A: This system is based on Bluetooth Low Energy (BLE) technology to forward the collected data from the data collector (server) to the data gateways and proposes the use of smart phones as data collectors.Example of Lab Description: CCN lab is a lab in which various experiments specific to networking domain are performed so as to have a practical understanding of industry levl networking.Data communication refers to the transmission of digital data between two or more computers.This lab comprises of 20PCs all conneccted to gether in a single computer network.");
bCharacteristic->setValue("B: This system is based on Bluetooth Low Energy (BLE) technology to forward the collected data from the data collector (server) to the data gateways and proposes the use of smart phones as data collectors.");
pCharacteristic->setValue("C: This system is based on Bluetooth Low Energy (BLE) technology to forward the collected data from the data collector (server) to the data gateways and proposes the use of smart phones as data collectors.");
// rCharacteristic->setValue("R This system is based on Bluetooth Low Energy (BLE) technology to forward the collected data from the data collector (server) to the data gateways and proposes the use of smart phones as data collectors.Example of Lab Description: CCN lab is a lab in which various experiments specific to networking domain are performed so as to have a practical understanding of industry levl networking.Data communication refers to the transmission of digital data between two or more computers.This lab comprises of 20PCs all conneccted to gether in a single computer network.");
// qCharacteristic->setValue("Q This system is based on Bluetooth Low Energy (BLE) technology to forward the collected data from the data collector (server) to the data gateways and proposes the use of smart phones as data collectors.Example of Lab Description: CCN lab is a lab in which various experiments specific to networking domain are performed so as to have a practical understanding of industry levl networking.Data communication refers to the transmission of digital data between two or more computers.This lab comprises of 20PCs all conneccted to gether in a single computer network.");

  BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
//  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
   
  //BLEAdvertising *qAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
  BLEAdvertising *aAdvertising = BLEDevice::getAdvertising();   
  BLEAdvertising *bAdvertising = BLEDevice::getAdvertising();
  BLEAdvertising *rAdvertising = BLEDevice::getAdvertising();
 
  
  BLEAdvertising *qAdvertising = BLEDevice::getAdvertising();    //M service (second service)
  pService->start();

  pAdvertising->addServiceUUID(SERVICE_UUID);
  
  aAdvertising->setScanResponse(true);
  aAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  aAdvertising->setMinPreferred(0x12);

  bAdvertising->setScanResponse(true);
  bAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  bAdvertising->setMinPreferred(0x12);
   
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
 
  rAdvertising->setScanResponse(true);
  rAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  rAdvertising->setMinPreferred(0x12);
  
//  qAdvertising->addServiceUUID(SERVICES_UUID);
  qAdvertising->setScanResponse(true);
  qAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  qAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
}
