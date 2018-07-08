// ESP32 Composite Kickstart Project
// Code written by Coburn, aka "SoftwareGuy"
// Keep up to date! Check https://github.com/SoftwareGuy/esp32-composite-kickstart 
// for the latest stuff.

// Include our needed libraries.
#include <Arduino.h>

// Composite video definitions.
// This is NES/SNES resolution. The bigger the resolution, the more
// precious memory is used by the frame buffer.
const int VIDEO_XRES = 256;
const int VIDEO_YRES = 224;

// DAC pin definitions.
const int DAC1_PIN = 25;
const int DAC2_PIN = 26;

// A loop timer just for testing.
int CURRENT_TICKS = 0;

// Compiler definitions.
void setup();
void loop();
void secondaryLoop(void* data);

// Setup runs first. We do stuff inside it to initialize everything.
void setup() {
	// Open the serial output...	
	Serial.begin(115200);
	// TODO: Initialize composite video (will come in later commit)
	//
	// Announce we're alive...
	Serial.println("Hello World!");
	// Why not output some memory info?
	Serial.print("Free memory right now is: ");
	Serial.print(esp_get_free_heap_size());
	Serial.println(" bytes.");
}

// Loop is... well, you guessed it - it runs every tick/frame/whatever 
// you want to call it.
void loop() {
	if(CURRENT_TICKS == 65536) {
		Serial.println("I'm still here running a loop. :)");
		CURRENT_TICKS = 0;
	}
	
	CURRENT_TICKS++;
}

// This one is special. It runs on core 0, which does DAC video output.
// We leave core 1 alone because that's where the arduino code lives and it's too busy
// to run this as well as our other code.
void secondaryLoop(void* data) {
	;
}