# Advanced Ultrasonic Obstacle Detection & Reverse Parking Assistance System Using CAN Protocol

## 📌 Project Overview

This project is an automotive reverse parking assistance system designed to detect obstacles behind a vehicle and provide an alert to the driver.

The system uses **ultrasonic sensors** to measure obstacle distance and **CAN communication** to exchange information between two electronic control units (ECUs).

## 🎯 Objectives

* Detect obstacles during reverse parking.
* Measure the distance between the vehicle and obstacle.
* Transfer information between ECUs using CAN protocol.
* Alert the driver using a buzzer.
* Reduce wiring complexity using CAN communication.

## 🏗️ System Architecture

The system consists of two CAN nodes:

### Node A – Vehicle/Reverse Gear Node

* Detects reverse gear activation.
* Sends a CAN remote frame request to Node B.
* Uses CAN communication to request obstacle information.

### Node B – Ultrasonic/Alert Node

* Measures obstacle distance using an ultrasonic sensor.
* Receives the request from Node A.
* Sends obstacle information through CAN.
* Activates the buzzer according to the detected obstacle distance.

## 🔄 Communication Flow

```text
        Reverse Gear
             │
             ▼
       ┌───────────┐
       │   Node A  │
       │   ECU     │
       └─────┬─────┘
             │
             │ CAN Request
             ▼
       ┌───────────┐
       │   Node B  │
       │   ECU     │
       └─────┬─────┘
             │
       Ultrasonic Sensor
             │
             ▼
      Obstacle Distance
             │
             ▼
          Buzzer
```

## 🔧 Technologies Used

* Embedded C
* ARM Microcontroller
* CAN Protocol
* UART
* Ultrasonic Sensor
* LCD
* Buzzer
* GPIO
* Embedded Firmware

## 📡 CAN Communication

CAN was selected because it is widely used for communication between automotive ECUs.

Important CAN concepts implemented in this project:

* CAN Data Frame
* CAN Remote Frame
* CAN Identifier
* RTR Bit
* CAN Arbitration
* Differential Communication
* ECU-to-ECU Communication

The system uses a **remote frame request** from Node A to request obstacle information from Node B.

## 🧩 Hardware Components

* ARM-based microcontroller
* CAN transceiver
* Ultrasonic sensor
* 16×2 LCD
* Buzzer
* Power supply
* Connecting hardware

## 💻 Software

The firmware is developed using **Embedded C**.

Main software modules include:

```text
CAN Initialization
CAN Transmission
CAN Reception
UART Communication
LCD Display
Ultrasonic Distance Measurement
Buzzer Control
GPIO Configuration
```

## 📂 Project Structure

```text
advanced-ultrasonic-parking-system/
│
├── README.md
│
├── source/
│   ├── node_a.c
│   ├── node_b.c
│   ├── can.c
│   ├── can.h
│   ├── uart.c
│   ├── lcd.c
│   └── buzzer.c
│
├── documentation/
│   └── project_report.pdf
│
└── images/
    ├── project_setup.jpg
    └── block_diagram.png
```

## 🚀 Key Learning

Through this project, I gained practical experience in:

* Embedded C programming
* ARM microcontroller programming
* CAN protocol
* ECU-to-ECU communication
* UART communication
* GPIO programming
* Ultrasonic sensor interfacing
* LCD interfacing
* Buzzer control
* Embedded system debugging

## 👩‍💻 Author

**Kajal Galani**

Electronics & Communication Engineering

Interested in **Embedded Software / Embedded Firmware Engineering**.
