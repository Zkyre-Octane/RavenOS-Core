#include "menu_manager.h"
#include <Arduino.h>

MenuManager::MenuManager(DisplayManager* dm,
                         InputManager* navBtn,
                         InputManager* execBtn,
                         const char* opts[],
                         MenuAction actions[],
                         int numOpts)
  : _dm(dm),
    _navBtn(navBtn),
    _execBtn(execBtn),
    _options(opts),
    _actions(actions),
    _numOptions(numOpts),
    _selected(0),
    _lastNavState(false),
    _lastExecState(false)
{
    // Fail‑safe: avoid crashes if something is misconfigured
    if (_dm && _options && _numOptions > 0) {
        _dm->showMenu(_options, _numOptions, _selected);
    }
}

void MenuManager::update() {
    // Hard safety: if anything is invalid, do nothing
    if (!_dm || !_navBtn || !_execBtn || !_options || !_actions || _numOptions <= 0) {
        return;
    }

    bool navPressed  = _navBtn->isPressed();
    bool execPressed = _execBtn->isPressed();

    // Navigation (Next option)
    if (navPressed && !_lastNavState) {
        _selected++;
        if (_selected >= _numOptions) {
            _selected = 0;
        }

        _dm->showMenu(_options, _numOptions, _selected);
        delay(150); // simple debounce
    }
    _lastNavState = navPressed;

    // Execute selected action
    if (execPressed && !_lastExecState) {
        if (_selected >= 0 && _selected < _numOptions && _actions[_selected]) {
            _actions[_selected]();
        }
        delay(150); // simple debounce
    }
    _lastExecState = execPressed;
}
