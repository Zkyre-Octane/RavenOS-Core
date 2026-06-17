/*
Copyright (c) 2026 NyxOverflow

Permission is granted to anyone to use, copy, modify, and distribute this software, 
for educational and personal purposes only, provided that this notice is included. 

THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
THE AUTHOR IS NOT RESPONSIBLE FOR ANY DAMAGE, MISUSE, OR LEGAL CONSEQUENCES 
RESULTING FROM THE USE OF THIS SOFTWARE.

Use responsibly and ethically. This software is intended for learning, experimentation, 
and personal development purposes only.
*/

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "display_manager.h"
#include "input_manager.h"
#include "menu_manager.h"
#include "wifi_manager.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define NAV_PIN 17    // navigation button on p17 
#define EXEC_PIN 16   // exec button on p16
//#define NAV_PIN_UP 18
//#define NAV_PIN_DOWN 19
//#define NAV_PIN_LEFT 21
//#define NAV_PIN_RIGHT 22

// screen
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DisplayManager* dm;

// buttons
InputManager navButton(NAV_PIN);
InputManager execButton(EXEC_PIN);
//InputManager navUpButton(NAV_PIN_UP);
//InputManager navDownButton(NAV_PIN_DOWN);
//InputManager navLeftButton(NAV_PIN_LEFT);
//InputManager navRightButton(NAV_PIN_RIGHT);

// wifi
WiFiManager wifi("WIFI_SSID", "PASSWORD", 2); // change with your wifi credentials

// menu options
const char* options[] = {"Wifi CONNECT", "Option 2", "Option 3", "Option 4"}; // add more options here

// options funtion
void connectWiFi() {
    if(wifi.connect()) {
        dm->clearDisplay();
        dm->showMessage("WiFi CONNECTED", 4);
    } else {
        dm->clearDisplay();
        dm->showMessage("WiFi FAILED", 4);
    }
}

void option2() {
    dm->clearDisplay();
    dm->showMessage("Option 2 selected", 4);
}

void option3() {
    dm->clearDisplay();
    dm->showMessage("Option 3 selected", 4);
}

void option4() {
    dm->clearDisplay();
    dm->showMessage("Option 4 selected", 4);
}

MenuAction actions[] = {connectWiFi, option2, option3, option4};
MenuManager* menu;

void setup() {
  Serial.begin(115200);

  // Check display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Display failed");
    while(true);
  }

  dm = new DisplayManager(&display);
  dm->bootScreen(); // Show boot screen
  delay(2000);

  // start buttons
  navButton.begin();
  execButton.begin();

  // start menu
  menu = new MenuManager(dm, &navButton, &execButton, options, actions, 4);
}

void loop() {
  // update
  menu->update();

}