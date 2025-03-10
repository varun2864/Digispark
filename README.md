# Digispark Payload Scripts
Automated Digispark Payload for Guest Admin Creation
Overview
This repository contains a Digispark BadUSB payload designed to create a hidden guest administrator account on Windows machines. The script executes commands to add a new user with administrative privileges while modifying system settings to maintain stealth and persistence.

Features
Creates a new administrator account using net user and net localgroup commands.
Hides the account from the login screen by modifying registry values.
Ensures persistence by adding scheduled tasks and adjusting local group policies.
Executes stealthily to avoid detection by basic security measures.
Prerequisites
A Digispark ATTiny85 microcontroller
Windows 10/11 target machine
Digispark-compatible Arduino IDE with DigiKeyboard library installed
