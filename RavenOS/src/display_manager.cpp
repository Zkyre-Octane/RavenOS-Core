#include "display_manager.h"

DisplayManager::DisplayManager(Adafruit_SSD1306* display)
    : _display(display)
{
    _display->clearDisplay();
    _display->setTextSize(1);
    _display->setTextColor(SSD1306_WHITE);
}

// Boot screen
void DisplayManager::bootScreen() {
    _display->clearDisplay();   //clean initial buffer

    _display->drawRect(0, 0, 128, 16, SSD1306_WHITE);
    _display->setCursor(4, 4);
    _display->println("BOOTING");

    _display->drawRect(0, 16, 128, 48, SSD1306_WHITE);
    _display->setCursor(4, 22);
    _display->println("RavenOS CORE");

    _display->setCursor(4, 52);
    _display->println("Dev by NyxOverflow");

    _display->display();
}

void DisplayManager::clearDisplay() {
    _display->clearDisplay();
}

void DisplayManager::drawHeader(const char* text) {
    _display->setTextSize(1);
    _display->setTextColor(SSD1306_WHITE);

    _display->drawRect(0, 0, 128, 16, SSD1306_WHITE);
    _display->setCursor(4, 4);
    _display->println(text);
}

void DisplayManager::refresh() {
    _display->display();
}

// Draw menu with options
void DisplayManager::showMenu(const char* options[], int numOptions, int selected) {
    _display->clearDisplay();

    // Header
    drawHeader("ACTIONS");

    // Options
    for (int i = 0; i < numOptions; i++) {
        int y = 18 + i * 10;

        _display->setCursor(2, y);

        if (i == selected)
            _display->print("> ");
        else
            _display->print("  ");

        _display->println(options[i]);
    }

    _display->display();
}

// Show a message at a specific line
void DisplayManager::showMessage(const char* msg, int line) {
    _display->setCursor(0, line);
    _display->println(msg);
    _display->display();
}
