#ifndef PALETTES_H
	#define PALETTES_H 

	#include <Arduino.h>
	#include <FastLED.h>
	#include <adri_timer.h>
	#include <ALS_leds_effectsMod.h>	



class RGBeffect_palette
	{
	public:
		RGBeffect_palette();
		~RGBeffect_palette(){};

		void 	palette_init();
		void 	myPalette_setPos(PALETTE_MODS palette_mod, int pos);
		int		myPalette_getPos(PALETTE_MODS palette_mod);
		void 	myPalette_next(PALETTE_MODS palette_mod, boolean debug);
		void 	myPalette_prev(PALETTE_MODS palette_mod, boolean debug);
		void 	myPalette_getPalette(PALETTE_MODS palette_mod, CRGBPalette16 & ret, boolean palette_play, boolean palette_toward);
		void 	myPalette_toward(uint8_t incr, int delay, adri_timer * timer); 
		void 	myPalette_toward(uint8_t incr, int delay); 

		
	};	

	RGBeffect_palette * RGBeffecPalette_ptr_get();
#endif