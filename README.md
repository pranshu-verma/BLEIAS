# Bluetooth Low Energy - Information Access System
*Final year project on Bluetooth Low Energy*


## Abstract
This project puts forward a **proof-of-concept**, **low-cost**, and **easily deployable** Bluetooth Low Energy (BLE) based localization system using the ESP32 module which actively scans and connects to the nearby mobile devices. The mobile subjects will then be able to access the needed information of a space or a room by logging in to a dedicated self-designed app, namely, the `Information Access system (IAS)` in their smart phones.

## Why BLE?

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
* A service provided by BLE has `7 characteristics`.
* The total number of characters that a characteristic can hold is `578`.
* Thus, the total number of characters in one service is `4046`.
* The time observed for the data to transmit from the ESP module to the app per characteristic is `2.5 seconds`.

### Observations on Data Transfer

| Observation | Result |
| :---: | :---: |
| Service provided by BLE *(A)* | `7 characteristics` |
| Total number of characters per characteristic *(B)*| `578 characters` |
| Total number of characters in one service *(A x B)* | `4046 characters` |
| Time observed for the data to transmit | `2.5 seconds` |

### Observations on Image Transfer

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

## Contributers
1. Amisha Kuwarbi - amisha.kuwarbi@sitpune.edu.in
2. Akshay Bhagwani - akshay.bhagwani@sitpune.edu.in
3. Vennela Bandla - bandla.vennela@sitpune.edu.in
4. Pranshu Verma - pranshu.verma@sitpune.edu.in
