#ifndef ALS_LEDS_EFFECTSMOD_H
	#define ALS_LEDS_EFFECTSMOD_H 
	#include <Arduino.h>

	enum PALETTE_MODS { 
		PALETTE_MOD_STATIC, 
		PALETTE_MOD_CYCLE, 
		PALETTE_MOD_GRADIENTS, 
		PALETTE_MOD_NOISE, 
		PALETTE_MOD_TWKIKLEHUE, 
		PALETTE_MOD_COMPO, 
		PALETTE_MOD_RAINBOW, 
		PALETTE_MOD_FIRE,
		PALETTE_MOD_NULL,
	}; 

	enum EFFECTCOLOR_MODS
	{
		EFFECTCOLOR_HUE,
		EFFECTCOLOR_PALETTE,
		EFFECTCOLOR_PALETTEHUE,
		EFFECTCOLOR_NULL,
	};


	enum HUE_MODS { 
		HUE_MOD_NM, 
		HUE_MOD_TIMER, 
		HUE_MOD_PASS,
		HUE_MOD_OFF, 
		HUE_MOD_INDEX, 
		HUE_MOD_CPAl, 
		HUE_MOD_CC,
		HUE_MOD_CCHUE
	}; 

	enum PATTERNEFFECT_MODS { 
		PATTERNEFFECT_WAVE_1, 
		PATTERNEFFECT_DC, 
		PATTERNEFFECT_NULL
	};


	String 				are_paletteModToString(PALETTE_MODS searchMod);
	PALETTE_MODS 		are_paletteModFromString(int Search);

	String 				are_effectColorModToString(EFFECTCOLOR_MODS searchMod);
	EFFECTCOLOR_MODS 	are_effectColorModFromString(int Search);

	String 				are_patternEffectModToString(EFFECTCOLOR_MODS searchMod);
	PATTERNEFFECT_MODS 	are_patternEffectModFromString(int Search);	

	String 				are_hueModToString(HUE_MODS searchMod);
	HUE_MODS 			are_hueModStringToMod(int Search);
#endif