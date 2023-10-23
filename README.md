# esp32-composite-kickstart
A kickstart project for ESP32 Composite Graphics

## This project is obsolete.
I no longer work with ESP32 Composite stuffs and I do not have time to mantain this kickstart project.

Sorry to disappoint. It is what it is. 😔

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
1. Install the latest Python 2.7.x for your platform from https://python.org or your package manager
2. Install PlatformIO from https://platform.io
3. Download this repo as a ZIP file or git clone it.
4. Open a terminal/command prompt and in the root folder where the `lib` and `src` folders are, enter:
```
platformio run
(compile process will start and take a bit of time)
platformio run -t upload
(the upload process will start. WARNING: Any existing firmware on the ESP32 WILL BE DESTROYED!!)
```
5. If no errors occurred the firmware has been uploaded to the ESP32 and it should auto reboot and display an image on the composite output. If so, you're winner winner chicken dinner.

### Getting started using Arduino IDE
**This is currently untested as I don't have the IDE installed, but it should be okay...**
1. Make sure you have installed the ESP32 platform for the Arduino IDE.
2. Download this repo as a ZIP file or git clone it.
3. Inside the `src` folder, rename `main.cpp` to `esp32-composite-kickstart.ino`. Open the renamed file with the Arduino IDE.
4. Make sure your ESP32 is plugged in. Ensure the device is set to a ESP32 device (mine is a generic one, so I chose ESP32 Development Unit). Check the upload port to ensure it's not flashing code to the wrong device and leave the speed alone.
4. Click "Verify" to ensure it compiles alright, then click "Upload". **WARNING: Any existing firmware on the ESP32 WILL BE DESTROYED!!**
5. When it's done uploading, you're winner winner chicken dinner.

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
