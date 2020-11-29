
#ifndef ALS_LEDS_EFFECTSFNC_H
#define ALS_LEDS_EFFECTSFNC_H
	#include <Arduino.h>

	extern uint8_t timebase_shift_comp; // shift compensation, helps smooth speed variations when speed is adjusted with slider

	uint8_t _map8(uint8_t val, uint8_t min, uint8_t max) ;
	uint8_t _sin8(uint8_t a);
	uint8_t sawtooth_wave(uint8_t bpm);
	uint8_t adjust_bpm(uint8_t old_bpm, uint8_t new_bpm) ;
	uint8_t step_wave(uint8_t bpm, uint8_t steps) ;

	uint8_t triangle_wave(uint8_t bpm);

	uint8_t sine_wave(uint8_t bpm);
	uint8_t addb(uint8_t a, uint8_t b) ;
#endif