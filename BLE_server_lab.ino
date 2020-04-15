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
#define CHARACTERISTICSSSS_UUID "835a7880-9b50-4948-bc8e-b5fb449b2adb"

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  BLEDevice::init("BLE CCN Lab");
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

  BLECharacteristic *rCharacteristic = pService->createCharacteristic(
                                        CHARACTERISTICSSSS_UUID,
                                        BLECharacteristic::PROPERTY_READ |
                                        BLECharacteristic::PROPERTY_WRITE
                                       );

aCharacteristic->setValue("Computer Communication Lab&& &&Faculty In-charges: Prof. Shripad Deshpande and Prof. Harikrishnan R&&Lab Assistant: Mr.Pratap More&& &&Equipments: 20 PCs all connected together in a single computer network, Network Interface Card, Hub, Switches, Router, Modem, Cable and connectors. Supplementary like crimping tool, LAN Ethernet cables are also provided for thorough understanding. We also have manuals for stepwise implementation of the experiments");                                       
bCharacteristic->setValue("It is a lab in which various experiments specific to networking domain are performed so as to have a practical understanding of industry level networking. Learning Outcomes of this lab could be Data Communication Systems and its components, Identifying different types of network topologies and protocols, Understanding of the OSI model and TCP/IP. Also different types of network devices and their functions within a network and comprehension of application layer that how it communicates across the information network.");
pCharacteristic->setValue("Course Outcomes: Students will get practical knowledge about various networking components. Good hands on knowledge could be acquired in troubleshooting networking problems using various techniques. Students would also become able to construct straight and cross cabling and most importantly will be competent to program for network management. Pre learning required is just the basic understanding and use of computers in data communication.");
rCharacteristic->setValue("1 1 0 0 1 1 0 0, 1 1 1 1 0 0 0 0, 0 0 1 1 0 0 1 1, 0 0 1 1 0 0 0 0, 0 0 0 0 1 1 0 0");
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
