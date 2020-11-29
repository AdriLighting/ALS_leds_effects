#include "ALS_leds_effectsMod.h"

String are_paletteModToString(PALETTE_MODS searchMod) {
	switch (searchMod) {
		case PALETTE_MOD_STATIC: 		return "0";	break;
		case PALETTE_MOD_CYCLE:			return "1";	break;
		case PALETTE_MOD_GRADIENTS:		return "2";	break;         
		case PALETTE_MOD_NOISE:			return "3";	break;
		case PALETTE_MOD_TWKIKLEHUE:	return "4";	break;
		case PALETTE_MOD_COMPO:   		return "5"; break;         
		case PALETTE_MOD_RAINBOW:		return "6";	break;         
		case PALETTE_MOD_FIRE:			return "7";	break;         
		case PALETTE_MOD_NULL:			return "8";	break;         
	}
	return "8";
}
PALETTE_MODS are_paletteModFromString(int Search) {
	PALETTE_MODS ret = PALETTE_MOD_NULL;
	if (Search ==  0 ) {ret = PALETTE_MOD_STATIC;		}
	if (Search ==  1 ) {ret = PALETTE_MOD_CYCLE;		} 
	if (Search ==  2 ) {ret = PALETTE_MOD_GRADIENTS;	}    
	if (Search ==  3 ) {ret = PALETTE_MOD_NOISE;		} 
	if (Search ==  4 ) {ret = PALETTE_MOD_TWKIKLEHUE;	} 
	if (Search ==  5 ) {ret = PALETTE_MOD_COMPO;  		}                           
	if (Search ==  6 ) {ret = PALETTE_MOD_RAINBOW;		}   
	if (Search ==  7 ) {ret = PALETTE_MOD_FIRE;			}   
	if (Search ==  8 ) {ret = PALETTE_MOD_NULL;			}   
	return ret;
}

String are_effectColorModToString(EFFECTCOLOR_MODS searchMod) {
	switch (searchMod) {
		case EFFECTCOLOR_HUE: 			return "0";	break;
		case EFFECTCOLOR_PALETTE:		return "1";	break;
		case EFFECTCOLOR_PALETTEHUE:	return "2";	break;         
		case EFFECTCOLOR_NULL:			return "3";	break;         
	}
	return "3";
}
EFFECTCOLOR_MODS are_effectColorModFromString(int Search) {
	EFFECTCOLOR_MODS ret = EFFECTCOLOR_NULL;
	if (Search ==  0 ) {ret = EFFECTCOLOR_HUE;			}
	if (Search ==  1 ) {ret = EFFECTCOLOR_PALETTE;		} 
	if (Search ==  2 ) {ret = EFFECTCOLOR_PALETTEHUE;	}    
	if (Search ==  3 ) {ret = EFFECTCOLOR_NULL;			}    
	return ret;
}

String are_patternEffectModToString(EFFECTCOLOR_MODS searchMod) {
	switch (searchMod) {
		case PATTERNEFFECT_WAVE_1: 	return "0";	break;
		case PATTERNEFFECT_DC:		return "1";	break;
		case PATTERNEFFECT_NULL:	return "2";	break;         
	}
	return "2";
}
PATTERNEFFECT_MODS are_patternEffectModFromString(int Search) {
	PATTERNEFFECT_MODS ret = PATTERNEFFECT_NULL;
	if (Search ==  0 ) {ret = PATTERNEFFECT_WAVE_1;	}
	if (Search ==  1 ) {ret = PATTERNEFFECT_DC;		} 
	if (Search ==  2 ) {ret = PATTERNEFFECT_NULL;	}    
	return ret;
}

String are_hueModToString(HUE_MODS searchMod) {
	switch (searchMod) {
		case HUE_MOD_NM: 		return "0";	break;
		case HUE_MOD_TIMER:		return "1";	break;
		case HUE_MOD_CC:		return "2";	break;         
		case HUE_MOD_INDEX:		return "3";	break;
		case HUE_MOD_OFF:		return "4";	break;
		case HUE_MOD_PASS:   	return "5"; break;         
		case HUE_MOD_CPAl:		return "6";	break;         
		case HUE_MOD_CCHUE:		return "7";	break;         
	}
	return "";
}
HUE_MODS are_hueModStringToMod(int Search) {
	HUE_MODS ret = HUE_MOD_CC;
	if (Search ==  0 ) {ret = HUE_MOD_NM;	}
	if (Search ==  1 ) {ret = HUE_MOD_TIMER;	} 
	if (Search ==  2 ) {ret = HUE_MOD_CC;	}    
	if (Search ==  3 ) {ret = HUE_MOD_INDEX;	} 
	if (Search ==  4 ) {ret = HUE_MOD_OFF;	} 
	if (Search ==  5 ) {ret = HUE_MOD_PASS;  }                           
	if (Search ==  6 ) {ret = HUE_MOD_CPAl;	}   
	if (Search ==  7 ) {ret = HUE_MOD_CCHUE;	}   

	// fsprintf("\n[are_hueModStringToMod] search : %d - ret : %s", Search, are_hueModToString(ret).c_str())                        
	return ret;
}