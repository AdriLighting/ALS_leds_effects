
#ifndef PALETTES_GRADIENT_H
	#define PALETTES_GRADIENT_H
	
	#include <FastLED.h>
	#include <Arduino.h>


	extern uint8_t 								grPalettes_position;
	extern CRGBPalette16 						grCurrentPalette;
	extern CRGBPalette16 						grTargetPalette;  
	extern int 									gpFromSPIFFcount;
	extern PROGMEM const char * 				gpName_list[] ;

	String 			grandientPaletteGetName 	();
	String			grandientPaletteGetName 	(int pos);
	int 			grandientPaletteGetByName 	(String search);   
	String 			grandientPaletteFromSPIFF	(String path);
	int 			grandientPaletteNext		(int delta, boolean debug);
	int 			grandientPaletteNextPos		(int delta, boolean debug);
	CRGBPalette16 	grandientPaletteCreate 		(String pName, boolean debug);
	void 			grandientPaletteSet 		(int pos);
	String 			listGrandientPalette		(String display); 

#endif