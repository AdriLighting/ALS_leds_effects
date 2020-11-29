#include "ALS_leds_effectsFnc.h"

// ***************************** WAVEFORM GENERATORS ******************************************

uint8_t timebase_shift_comp; // shift compensation, helps smooth speed variations when speed is adjusted with slider

uint8_t _map8(uint8_t val, uint8_t min, uint8_t max) {
    return map(val, 0, 255, min, max);
}
uint8_t _sin8(uint8_t a) {
    uint8_t result=127*(1+sin(a*6.28/255));
    //Serial.printf("sin8: a:%3d sin8:%3d\n", a, result);
    return result;
}
uint8_t sawtooth_wave(uint8_t bpm) {
    long scale = timebase_shift_comp + (256 * millis() * bpm  )/ 60000 ;
    return scale;
}
uint8_t adjust_bpm(uint8_t old_bpm, uint8_t new_bpm) {
    uint8_t old_st=sawtooth_wave(old_bpm);
    uint8_t new_st=sawtooth_wave(new_bpm);
    timebase_shift_comp += (old_st - new_st);
    return new_bpm;
}
uint8_t step_wave(uint8_t bpm, uint8_t steps) {
    //uint8_t step = 256/steps;
    uint8_t step = steps;
    uint8_t saw = sawtooth_wave(bpm);
    return saw - (saw%step);
}

uint8_t triangle_wave(uint8_t bpm) {
    uint8_t st=sawtooth_wave(bpm);
    uint8_t r = (st<=127) ? (st*2) : (255-st)*2;
    //Serial.printf(buf, "LED_EFFECTS.CPP TRIANGLE: %3d\r\n",r);
    return r;
}

uint8_t sine_wave(uint8_t bpm) {
    return _sin8(sawtooth_wave(bpm));
}

	uint8_t addb(uint8_t a, uint8_t b) {
		int s=a+b;
		uint8_t r = (s>255) ? 255 : a+b;
		return r;
	}