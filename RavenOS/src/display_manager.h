#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class DisplayManager {
  public:
    DisplayManager(Adafruit_SSD1306* display);
    void bootScreen();  // Show boot screen
    void showMenu(const char* options[], int numOptions, int selected); // Show menu with options
    void showMessage(const char* msg, int line);  // Show message on specific line
    void clearDisplay();  // Clear the display
    void drawHeader(const char* text); // Draw header box with text
    void drawLine(const char* text, int y); // Draw line of text at specific y position
    void refresh(); // Refresh the display with current buffer content
  private:
    Adafruit_SSD1306* _display;
};

#endif