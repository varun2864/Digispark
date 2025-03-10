# Hidden Guest Administrator Account Creation

This repository contains a Digispark BadUSB payload designed to create a hidden guest administrator account on Windows machines. The payload executes commands to add a new user with administrative privileges and modifies system settings to maintain stealth and persistence.

## Key Features:

- **Account Creation:** Utilizes `net user` and `net localgroup` commands to create a new administrator account.
- **Stealth Mode:** Hides the account from the login screen by modifying registry values.
- **Persistence:** Ensures the account remains active by adding scheduled tasks and adjusting local group policies.

## Prerequisites:

- **Hardware:** Digispark ATTiny85 microcontroller.
- **Target System:** Windows 10/11.
- **Software:** Arduino IDE with Digispark drivers and the DigiKeyboard library installed.

## Installation & Usage:

1. **Clone the Repository:**

   ```sh
   git clone https://github.com/yourusername/hidden-guest-admin-payload.git
   cd hidden-guest-admin-payload

2. **Upload Script to Digispark:**
Open the guest_admin_creation.ino script in the Arduino IDE.
Compile and upload the script to the Digispark device.

3. **Deploy Payload:**
Insert the Digispark into the target machine's USB port.
The payload will execute automatically, creating the hidden admin account.

## Detection and Removal
To detect and remove the hidden guest admin account, run: 
   ```sh
   net user GuestAdmin /delete
   reg delete "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon\SpecialAccounts\UserList" /v GuestAdmin /f
   schtasks /delete /tn "SystemUpdate" /f

## Disclaimer:
This project is intended for educational and authorized penetration testing purposes only. Unauthorized use on systems without explicit permission is illegal and unethical. Use responsibly.


