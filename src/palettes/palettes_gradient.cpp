
#include "palettes_gradient.h"
#include "palettes_gradient_list.h"


#include <arduino.h>
#include <FS.h>
#include <adri_tools.h>


#ifdef DEBUG_PALETTE
   #define DEBUG
#endif


CRGBPalette16 	grCurrentPalette( CRGB::Black);
CRGBPalette16 	grTargetPalette(CRGB::Black ); 
CRGBPalette16 	grcPalette( CRGB::Black ); 
uint8_t 		grPalettes_position = 0;
int 			gpFromSPIFFcount = GRADIENT_PALETTE_COUNT;


String grandientPaletteGetName(){
	return ch_toString(gpName_list[grPalettes_position]);
}

String grandientPaletteGetName(int pos){
	return ch_toString(gpName_list[pos]);
}

int grandientPaletteGetByName(String search) {
	int ret = -1;
	for (int i = 0; i < gpFromSPIFFcount; i++) {
		String name = ch_toString(gpName_list[i]);
		if (search == name) {ret = i;break;}
	}
	return ret;
}

String grandientPaletteFromSPIFF(String path) { 
	for (int i = 0; i < gpFromSPIFFcount; ++i)
	{
		fsprintf("%d - %s\n", i, gpName_list[i] );
	}
}
String listGrandientPalette(String display) {
  
	String ret;

	if (display != "") fsprintf("%s - %d\n", display.c_str(), gpFromSPIFFcount);

	for (int i = 0; i < gpFromSPIFFcount; i++) {
			ret +=  ch_toString(gpName_list[i]) + ";";
			if (display != "") fsprintf("%s\n" , gpName_list[i]);
	}
	return ret;
}


CRGBPalette16 grandientPaletteCreate(String pName, boolean debug){
	CRGBPalette16 spiffPalette;
	int index = grandientPaletteGetByName(pName);
	byte i = constrain(index, 0, gpFromSPIFFcount -1);
	byte tcp[72]; //support gradient palettes with up to 18 entries
	memcpy_P(tcp, (byte*)pgm_read_dword(&(gGradientPalettes[i])), 72);
	spiffPalette.loadDynamicGradientPalette(tcp);
	return spiffPalette;
}


int grandientPaletteNextPos(int delta, boolean debug) {
	int cPos = grPalettes_position;
	if 		(cPos == 0 && delta < 0) 					cPos = gpFromSPIFFcount - 1;
	else if (cPos >= gpFromSPIFFcount - 1 && delta > 0) cPos = 0;
	else 												cPos += delta;
	if 		(cPos >= gpFromSPIFFcount) 					cPos = 0;
	return cPos;
}
int grandientPaletteNext(int delta, boolean debug) {
	grPalettes_position = grandientPaletteNextPos(delta, debug);
	grTargetPalette = grandientPaletteCreate( grandientPaletteGetName(), debug);
	return grPalettes_position;
}
// void grandientPaletteSet(int pos) {
// 	grTargetPalette = grandientPaletteCreate(gpFromSPIFF[pos]);
// }