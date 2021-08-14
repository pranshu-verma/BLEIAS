# Bluetooth Low Energy - Information Access System
*Final year project on Bluetooth Low Energy*

## Table of contents
* [Abstract](#abstract)
* [Why BLE?](#why-ble)
  + [Features](#features)
  + [Tech details](#tech-details)
* [Diagram](#diagram)
* [Workflow](#workflow)
* [Results and Observations](#results-and-observations)
  + [Data Transfer](#data-transfer)
  + [Image Transfer](#image-transfer)
* [Demo](#demo)
* [Experience](#experience)
* [Links](#links)
* [Contributers](#contributers)


## Abstract
This project puts forward a **proof-of-concept**, **low-cost**, and **easily deployable** Bluetooth Low Energy (BLE) based localization system using the ESP32 module which actively scans and connects to the nearby mobile devices. The mobile subjects will then be able to access the needed information of a space or a room by logging in to a dedicated self-designed app, namely, the `Information Access system (IAS)` in their smart phones.

## Why BLE?
Bluetooth Low Energy is an intelligent, power-friendly version of Bluetooth wireless
technology. This really is making smart devices more portable, affordable, and less complicated
to convert into smarter devices.

### Features
1. **The lowest power consumption**: To reduce power consumption, a BLE device is kept in sleep mode most of the time. A short message is transferred to a gateway or smartphone, whenever an event occurs. The device wakes up as during the occurrence of the event. *Maximum/peak power consumption is less than `15 mA` and the average power consumption is about `1 μA`.*
2. **Cost-efficient and compatible**: Two types of chipsets exist to provide compatibility with classic Bluetooth technology as well as cost efficiency for small battery-operated devices:
→ `Dual-mode` technology for both BLE and classic Bluetooth features:
→ `Stand-alone BLE` technology designed for small battery-powered devices with low cost and low power consumption as their priority
3. **Robustness, security, and reliability**: The technology used in BLE is the same adaptive frequency hopping (AFH) technology as used in classic Bluetooth technology.
4. **Connection range**: BLE technology provides a modulation slightly different than that of classic Bluetooth. This variant provides a range of up to `300 meters with a 10 dBm radio chipset` (BLE maximum).

### Tech details
1. **Data transfers** – Very short data packets `(8 octet minimum up to 27 octets maximum)` are supported by BLE and are transferred at `1 Mbps`.
2. **Latency** – BLE can also support connection setup and transferring of data in as quickly as `6ms`. The time lag taken during data transmission is up to `3ms`.
3. **Topology** – BLE uses every slave's 32-bit access address, allowing thousands of devices to be connected. The technology is designed for single connections, though one-to-many connections using a star topology are possible.

## Diagram
![Diagram](https://github.com/pranshu-verma/BLEIAS/blob/master/Screenshots/block-diagram.png)

## Workflow
![Workflow](https://github.com/pranshu-verma/BLEIAS/blob/master/Screenshots/workflow.jpg)

## Results and Observations

### Data Transfer

| Observation | Result |
| :---: | :---: |
| Service provided by BLE *(A)* | `7 characteristics` |
| Total number of characters per characteristic *(B)*| `578 characters` |
| Total number of characters in one service *(A x B)* | `4046 characters` |
| Time observed for the data to transmit | `2.5 seconds` |

### Image Transfer

| Observation | Result |
| :---: | :---: |
| Size of the image | `3 KB` |
| Pixel of the image | `75 x 75` |
| Total time taken by the app to display the image | `7 x 2.5 seconds` | 

## Demo

| Step  | Preview |
| :-------------: | :-------------: |
| 1. Press connect to view the list of BLEs around you | <img src="https://github.com/pranshu-verma/BLEIAS/blob/master/Screenshots/home.jpeg" width="250px">  |
| 2. Give Bluetooth permission to the application | <img src="https://github.com/pranshu-verma/BLEIAS/blob/master/Screenshots/bt-request.jpeg" width="250px">  |
| 3. List of available devices | <img src="https://github.com/pranshu-verma/BLEIAS/blob/master/Screenshots/list-ble.png" width="250px">  |
| 4. Lab Info | <img src="https://github.com/pranshu-verma/BLEIAS/blob/master/Screenshots/lab-info.png" width="250px">  |
| 5. Faculty Info (with Image) | <img src="https://github.com/pranshu-verma/BLEIAS/blob/master/Screenshots/faculty-info.png" width="250px">  |

## Experience
![Experience](https://github.com/pranshu-verma/BLEIAS/blob/master/Screenshots/irl-example.png)

## Links
* [Project report](https://drive.google.com/file/d/1g5iRCCeRysPG2UQmxSBpCURfNOPGbmp8/view?usp=sharing) 
* [Research paper](https://drive.google.com/file/d/1Nt02oB1f3RyGd3N0XGsK91FEk0I8R74O/view?usp=sharing)

## Contributers
1. Amisha Kuwarbi - amisha.kuwarbi@sitpune.edu.in / amishakuwarbi17@gmail.com
2. Akshay Bhagwani - akshay.bhagwani@sitpune.edu.in / akshaybhagwani@gmail.com
3. Vennela Bandla - bandla.vennela@sitpune.edu.in / vennelabandla1@gmail.com
4. Pranshu Verma - pranshu.verma@sitpune.edu.in / pranshuvrm@gmail.com
