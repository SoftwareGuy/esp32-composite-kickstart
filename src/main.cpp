// ESP32 Composite Kickstart Project
// Code written by Coburn, aka "SoftwareGuy"
// Keep up to date! Check https://github.com/SoftwareGuy/esp32-composite-kickstart 
// for the latest stuff.

// Include our needed libraries.
#include <Arduino.h>
#include <soc/rtc.h>

#include "bitluni/Image.h"
#include "bitluni/SimplePALOutput.h"
#include "bitluni/Graphics.h"

// Composite video definitions.
// This is NES/SNES resolution. The bigger the resolution, the more
// precious memory is used by the frame buffer.
const int VIDEO_XRES = 256;
const int VIDEO_YRES = 224;

// DAC pin definitions.
const int DAC1_PIN = 25;
const int DAC2_PIN = 26;

// Memory Check
int BOOT_MEM = 0;

// A loop timer just for testing.
int CURRENT_TICKS = 0;

// References to library code.
Graphics graphics(VIDEO_XRES, VIDEO_YRES);
SimplePALOutput composite;

// Compiler definitions.
void setup();
void loop();
void secondaryLoop(void *data);

// Setup runs first. We do stuff inside it to initialize everything.
void setup() {
	// This will be later used to determine if the board has a ESP32-WROOM or ESP32-WROVER module
	BOOT_MEM = esp_get_free_heap_size();
	
	// Fastest CPU clock please.
	rtc_clk_cpu_freq_set(RTC_CPU_FREQ_240M);
	
	// Open the serial output...	
	Serial.begin(115200);
	
	// TODO: Initialize composite video (will come in later commit)
	composite.init();
	graphics.init();
	
	// Font will be coming in another future commit.
	// graphics.setFont(gameboy);
	// graphics.setTextColor(graphics.rgb(255, 255, 255));
	
	// Pin the task to CPU 0 (the one that's usually idle since CPU 1 runs our code).
	xTaskCreatePinnedToCore(secondaryLoop, "video", 1024, NULL, 1, NULL, 0);
	
	// Announce we're alive...
	Serial.println("Hello World!");
	// Why not output some memory info?
	Serial.print("Boot memory count was: ");
	Serial.print(BOOT_MEM);
	Serial.println(" bytes.");
	Serial.print("Free memory right now is: ");
	Serial.print(esp_get_free_heap_size());
	Serial.println(" bytes.");
	
}

// Loop is... well, you guessed it - it runs every tick/frame/whatever 
// you want to call it.
void loop() {
	/*
	 * This was a failsafe check to ensure that the ESP32 wasn't throwing errors 
	 * if(CURRENT_TICKS == 65536) {
	 *	Serial.println("I'm still here running a loop.");
	 *	CURRENT_TICKS = 0;
	 * }
	 * CURRENT_TICKS++;
	 */
	 
	// This will make a empty Windows 95/98 image. Just enough to
	// say that it's working.
	graphics.begin(graphics.rgb(64, 128, 128));
	graphics.end();
}

// This one is special. It runs on core 0, which does DAC video output.
// We leave core 1 alone because that's where the arduino code lives and it's too busy
// to run this as well as our other code.
void secondaryLoop(void *data) {
	// This should not error, but as of version 1.6.0 of the Arduino framework
	// for the ESP32, it'll crap itself. Unknown reasons why.
	while(true) composite.sendFrame(&graphics.frame);
}