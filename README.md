# esp32-composite-kickstart
A kickstart project for ESP32 Composite Graphics

**This project is intended for use with the PlatformIO and Eclipse IDE.
However, if you don't like this for whatever reason, I will provide a Arduino project file that'll help you out.**
## What's this?
This project is a very simple "let's go!" approach to the ESP32 and composite graphics. This means that you can use your ESP32's internal DACs (Digital-to-Analogue Converter) to render and output video and audio.

Make sure you have a CRT TV or another device capable of receiving Composite Video and Audio signals. I recommend a cheap capture card, be it PCI(e) or USB, but a portable car reversing monitor also will be sufficient. Just hunt around for a screen with RCA (Composite) input.

This project makes use of bitluni's composite video and sound libraries. Without him, we'd be stuck using SPI-driven TFT displays.

### Setting up
1. Composite video uses G25 (DAC1). Connect this to the "stick" part of the connector on a male-to-male RCA cable.
2. Connect the outer shield to GND (Ground) but make sure you don't short the two together. The ESP32 will not like that otherwise.
3. Connect the other end of the RCA cable to your TV, portable monitor or whatever.
4. Plug in your ESP32 to your computer and make sure drivers are installed. Windows will pick them up if you're on Windows 10, MacOS may/may not automatically detect it. Linux will require you to be in the `dialout` user group to use USB Serial ports.
5. Continue below.

### Getting started using PlatformIO
*This will be updated once the project is uploaded*

### Getting started using Arduino IDE
*This will be updated once the project is uploaded*

### Improvements and Problems
**Warnings that are generated from the compile process can be safely ignored unless it throws an error because the warning was potentially fatal.**

**For problems:** Please open a issue ticket and clearly state what your problem is. You must provide your OS, Arduino IDE or Platform IO version and the brand of your ESP32. Failure to do so will almost give your issue a 100% sure-fire chance of getting a "wontfix"/"cantfix" sticker.

**For improvements:** Please open a issue ticket and put either "Idea", "Suggestion" or "Improvement" in the title. I will then be able to consider them rather than going "Is that a bug or an idea?"

**For pull requests:** Please detail pull requests in detail like so. This makes tracking merges easier because if your commit breaks something, we can blame you for it.

*Good pull request:*
```
Rewrote the composite video output to make it faster and achieve at least 55 FPS at SNES resolution when nothing much is going on.
```
*Bad pull request:*
```
speedup fix
```

## Thank you for your interest in this project!
