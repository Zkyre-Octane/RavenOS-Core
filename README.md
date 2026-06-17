<p align="center">
  <img src="https://github.com/Zkyre-Octane/RavenOS-Core/blob/main/RavenOS/assets/logo/ravenos-logo.png">
</p>


# RavenOS Minimal Core — ESP32 / Flipper‑Style Runtime

RavenOS is a lightweight, modular operating environment inspired by Flipper Zero’s UX philosophy and built specifically for the ESP32 platform.  
This repository contains the **Minimal Core**, designed as a clean foundation for future modules, apps, and hardware integrations.

---

## Features

- **Bootscreen** — compact startup sequence with branding support  
- **Navigation UI** — single-button directional navigation  
- **Execution control** — action/confirm button for triggering modules  
- **Four‑option menu system** — simple, extensible UI framework  
- **Wi‑Fi ready** — networking stack initialized for wireless features  

---

## Purpose of This Release

This core is intentionally minimal:

- Clean enough for professional review  
- Stable enough to build on  
- Flexible enough for custom modules, plugins, and hardware experiments  

It serves as the foundation for the full RavenOS ecosystem.

---

## Repository Structure

src/            → Core OS logic, UI, drivers, Wi-Fi
include/        → Header files
assets/         → Bootscreen and UI assets
docs/           → Architecture and technical documentation


---

## Build Instructions

1. Install ESP-IDF (v5.x recommended)  
2. Configure your ESP32 target  
3. Build and flash:


---

## Hardware Requirements

- ESP32‑WROOM or ESP32‑WROVER module  
- 1–3 buttons (navigation + execution)  
- Optional: OLED or LCD display  
- Optional: Wi‑Fi antenna  

---

## Roadmap

- Module loader system  
- App sandboxing  
- File manager  
- Plugin API  
- UI theming  
- Full wireless configuration menu  

---

## License

See `LICENSE` file for details.

---

## Credits

RavenOS is developed as an experimental embedded OS for ESP32, inspired by the interaction model of Flipper Zero.

