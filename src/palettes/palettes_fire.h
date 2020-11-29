#ifndef PALETTES_FIRE_H
	#define PALETTES_FIRE_H 
		#include <FastLED.h>
		#include <Arduino.h>
		extern int 				firePaletteCount;
		extern String 			firePaletteNames[];
		extern int 				firePalettes_position;
		extern CRGBPalette16 	fire_p;
		// extern CRGBPalette16 firePalettes[];


		int 			firePalettGetByName		(String search); 
		void 			firePalettNext			(int delta, boolean debug);
		int				firePalettNextPos		(int delta, boolean debug); 
		String 			firePaletteGetName		();
		String			firePaletteGetName		(int pos);
		String 			firePaletteFromSPIFF	(String path);
		CRGBPalette16	firePaletteCreate		();
		void 			firePaletteSet(int pos);

		class palette_fire {
			public:

			CRGBPalette16 	_pal;
			String 			_name;

			palette_fire(CRGBPalette16 pal, String name);

		};	
	    String firePaletteObject();
#endif