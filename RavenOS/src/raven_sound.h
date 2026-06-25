#ifndef RAVEN_SOUND_H
#define RAVEN_SOUND_H

#include <Arduino.h>

/*
    RavenOS Core — Sound Subsystem
    --------------------------------
    The SoundManager class provides a unified interface for generating
    tones, melodies, and system audio cues using a passive buzzer driven
    by the ESP32 LEDC PWM hardware.

    This module is used across all RavenOS Core devices:
    - Raven Node (Flipper Zero–based ESP32 module)
    - Raven Wraith (FPV/UGV platform)
    - Future RavenOS UAV systems

    All sound patterns are non-blocking in design intent, but currently
    use delay() for timing. Future versions may integrate with the
    RavenOS Task Scheduler for asynchronous playback.
*/

class SoundManager {
public:

    /* --------------------------------------------------------------
       Constructor
       --------------------------------------------------------------
       buzzerPin   : GPIO pin connected to the passive buzzer
       pwmChannel  : LEDC PWM channel (0–15)
    */
    SoundManager(int buzzerPin, int pwmChannel);

    /* --------------------------------------------------------------
       Core Control
       -------------------------------------------------------------- */

    // Initialize PWM hardware and attach buzzer pin
    void ravenInit();

    // Play a tone at a given frequency (Hz) for a duration (ms)
    void ravenPlayTone(int freq, int ms);

    // Immediately stop any tone output
    void ravenStopSound();


    /* --------------------------------------------------------------
       System Sounds (UI / OS Feedback)
       -------------------------------------------------------------- */

    void ravenSoundBoot();         // Boot jingle
    void ravenSoundBeep();         // Simple short beep
    void ravenSoundError();        // Error tone pattern
    void ravenSoundTaskComplete(); // Success tone pattern
    void ravenSoundShutdown();     // Shutdown tone pattern
    void ravenSoundNotify();       // Notification tone pattern
    void ravenSoundClick();        // UI click tone


    /* --------------------------------------------------------------
       Pairing / Connectivity Melodies
       -------------------------------------------------------------- */

    void ravenSoundNfcPairing();     // NFC pairing melody
    void ravenSoundEspNowPairing();  // ESP-NOW pairing melody
    void ravenSoundWifiPairing();    // WiFi pairing melody


    /* --------------------------------------------------------------
       Vehicle / FPV / Robotics Sounds
       -------------------------------------------------------------- */

    void ravenSoundArm();     // FPV-style arming tone
    void ravenSoundDisarm();  // FPV-style disarm tone
    void ravenSoundBeacon();  // Locator beacon pulse


private:
    int _pin;       // Buzzer GPIO pin
    int _channel;   // LEDC PWM channel
};

#endif
