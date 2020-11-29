#ifndef PALETTES_CLASSIQUE_H
   	#define PALETTES_CLASSIQUE_H

	#include <FastLED.h>
	#include <Arduino.h>	

	extern String cpFromSPIFF[];
	extern int cpFromSPIFFcount;
	extern CRGBPalette16 clPalette;
	extern int clPalettes_position;

	int      		classiquePalettGetByName	(String search);
	String   		classiquePaletteGetName		();
	String   		classiquePaletteGetName		(int pos);
	int 			classiquePalettNext			(int delta, boolean debug);
	int 			classiquePalettNextPos		(int delta, boolean debug);
	CRGBPalette16	classiquePaletteCreate		(String pName, boolean debug);
	String 			classiquePaletteFromSPIFF	(String path);
	void 			classiquePalettSet			(int pos);
/*	
	// A mostly red palette with green accents and white trim.
	// "CRGB::Gray" is used as white to keep the brightness more uniform.
	const TProgmemRGBPalette16 RedGreenWhite_p FL_PROGMEM =
	{ CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Red,
	  CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Red,
	  CRGB::Red, CRGB::Red, CRGB::Gray, CRGB::Gray,
	  CRGB::Green, CRGB::Green, CRGB::Green, CRGB::Green
	};
	// A mostly (dark) green palette with red berries.
	#define Holly_Green 0x00580c
	#define Holly_Red   0xB00402
	const TProgmemRGBPalette16 Holly_p FL_PROGMEM =
	{ Holly_Green, Holly_Green, Holly_Green, Holly_Green,
	  Holly_Green, Holly_Green, Holly_Green, Holly_Green,
	  Holly_Green, Holly_Green, Holly_Green, Holly_Green,
	  Holly_Green, Holly_Green, Holly_Green, Holly_Red
	};

	// A red and white striped palette
	// "CRGB::Gray" is used as white to keep the brightness more uniform.
	const TProgmemRGBPalette16 RedWhite_p FL_PROGMEM =
	{ CRGB::Red,  CRGB::Red,  CRGB::Gray, CRGB::Gray,
	  CRGB::Red,  CRGB::Red,  CRGB::Gray, CRGB::Gray,
	  CRGB::Red,  CRGB::Red,  CRGB::Gray, CRGB::Gray,
	  CRGB::Red,  CRGB::Red,  CRGB::Gray, CRGB::Gray
	};

	// A mostly blue palette with white accents.
	// "CRGB::Gray" is used as white to keep the brightness more uniform.
	const TProgmemRGBPalette16 BlueWhite_p FL_PROGMEM =
	{ CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue,
	  CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue,
	  CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue,
	  CRGB::Blue, CRGB::Gray, CRGB::Gray, CRGB::Gray
	};

	// A pure "fairy light" palette with some brightness variations
	#define HALFFAIRY ((CRGB::FairyLight & 0xFEFEFE) / 2)
	#define QUARTERFAIRY ((CRGB::FairyLight & 0xFCFCFC) / 4)
	const TProgmemRGBPalette16 FairyLight_p FL_PROGMEM =
	{ CRGB::FairyLight, CRGB::FairyLight, CRGB::FairyLight, CRGB::FairyLight,
	  HALFFAIRY,        HALFFAIRY,        CRGB::FairyLight, CRGB::FairyLight,
	  QUARTERFAIRY,     QUARTERFAIRY,     CRGB::FairyLight, CRGB::FairyLight,
	  CRGB::FairyLight, CRGB::FairyLight, CRGB::FairyLight, CRGB::FairyLight
	};

	// A palette of soft snowflakes with the occasional bright one
	const TProgmemRGBPalette16 Snow_p FL_PROGMEM =
	{ 0x304048, 0x304048, 0x304048, 0x304048,
	  0x304048, 0x304048, 0x304048, 0x304048,
	  0x304048, 0x304048, 0x304048, 0x304048,
	  0x304048, 0x304048, 0x304048, 0xE0F0FF
	};
	// A palette reminiscent of large 'old-school' C9-size tree lights
	// in the five classic colors: red, orange, green, blue, and white.
	#define C9_Red    0xB80400
	#define C9_Orange 0x902C02
	#define C9_Green  0x046002
	#define C9_Blue   0x070758
	#define C9_White  0x606820
	const TProgmemRGBPalette16 RetroC9_p FL_PROGMEM =
	{ C9_Red,    C9_Orange, C9_Red,    C9_Orange,
	  C9_Orange, C9_Red,    C9_Orange, C9_Red,
	  C9_Green,  C9_Green,  C9_Green,  C9_Green,
	  C9_Blue,   C9_Blue,   C9_Blue,
	  C9_White
	};

	// A cold, icy pale blue palette
	#define Ice_Blue1 0x0C1040
	#define Ice_Blue2 0x182080
	#define Ice_Blue3 0x5080C0
	const TProgmemRGBPalette16 IcyBlue_p FL_PROGMEM =
	{
	  Ice_Blue1, Ice_Blue1, Ice_Blue1, Ice_Blue1,
	  Ice_Blue1, Ice_Blue1, Ice_Blue1, Ice_Blue1,
	  Ice_Blue1, Ice_Blue1, Ice_Blue1, Ice_Blue1,
	  Ice_Blue2, Ice_Blue2, Ice_Blue2, Ice_Blue3
	};

	extern CRGBPalette16 blueFirePalette;
	extern CRGBPalette16 yellowFirePalette;
	extern CRGBPalette16 hueFirePalette;
	extern CRGBPalette16 FirePalette;
	extern CRGBPalette16 snowColors;
	extern CRGBPalette16 incandescentColors;
	extern CRGBPalette16 IceColors_p;
*/
#endif
