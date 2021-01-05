#include "palettes.h"
#include "lib_palettes.h"
#include <adri_tools.h>

RGBeffect_palette * RGBeffecPalette_ptr = nullptr;
RGBeffect_palette * RGBeffecPalette_ptr_get(){
    if (RGBeffecPalette_ptr==nullptr) RGBeffecPalette_ptr = new RGBeffect_palette();
    return RGBeffecPalette_ptr;
}
RGBeffect_palette::RGBeffect_palette(){
}
void RGBeffect_palette::palette_init(){
	// palette_compo_restore() ;

    grTargetPalette     = grandientPaletteCreate( grandientPaletteGetName(), false);
	grCurrentPalette 	= grandientPaletteCreate( grandientPaletteGetName(), false);

	classiquePaletteFromSPIFF("/scp/");
	clPalette 			= classiquePaletteCreate(cpFromSPIFF[clPalettes_position], false);

	firePaletteFromSPIFF("/sfp/");
	// firePaletteObject();
	firePalettNext(1, false);
}

int RGBeffect_palette::myPalette_getPos(PALETTE_MODS palette_mod) {
    int ret;

    switch (palette_mod) {
        case PALETTE_MOD_CYCLE:
            ret = clPalettes_position; 
             fsprintf("\n[myPalette_getPos PALETTE_MOD_CYCLE][%d]\n", ret);
        break;
        case PALETTE_MOD_GRADIENTS:
            ret = grPalettes_position;
             fsprintf("\n[myPalette_getPos PALETTE_MOD_GRADIENTS][%d]\n", ret);
        break; 
        case PALETTE_MOD_FIRE:
            ret = firePalettes_position; 
             fsprintf("\n[myPalette_getPos PALETTE_MOD_FIRE][%d]\n", ret);
        break; 

        #ifdef PALETTES_COMPOSTIONS
        case PALETTE_MOD_COMPO:
            ret = patternOject_get_currentPaletteCompoPos(); 
        break; 
        #endif                                                                
    }
    return ret;
}  
void RGBeffect_palette::myPalette_setPos(PALETTE_MODS palette_mod, int pos) {
    int ret;

    switch (palette_mod) {
        case PALETTE_MOD_CYCLE:
            clPalettes_position = pos; 
            clPalette = classiquePaletteCreate(cpFromSPIFF[clPalettes_position], false);
            fsprintf("\n[myPalette_setPos PALETTE_MOD_CYCLE][%d]\n", pos);
        break;
        case PALETTE_MOD_GRADIENTS:
            grPalettes_position = pos; 
            grTargetPalette = grandientPaletteCreate( grandientPaletteGetName(grPalettes_position), false);
            fsprintf("\n[myPalette_setPos PALETTE_MOD_GRADIENTS][%d]\n", pos);
        break; 
        case PALETTE_MOD_FIRE:
            firePalettes_position = pos; 
            firePaletteCreate();
            fsprintf("\n[myPalette_setPos PALETTE_MOD_FIRE][%d]\n", pos);
        break; 

        #ifdef PALETTES_COMPOSTIONS
        case PALETTE_MOD_COMPO:
            ret = patternOject_get_currentPaletteCompoPos(); 
        break; 
        #endif                                                                
    }
}     
void RGBeffect_palette::myPalette_next(PALETTE_MODS palette_mod, boolean debug) {

    // palette_sav(p, debug);

    switch (palette_mod) {
        #ifdef PALETTES_COMPOSTIONS
        case PALETTE_MOD_COMPO:
            palette_compo_palette_next();
        break;     
        #endif  

        case PALETTE_MOD_FIRE:
            firePalettNext(1, debug); 
        break; 
        case PALETTE_MOD_GRADIENTS:
            grandientPaletteNext(1, debug);
        break; 

        case PALETTE_MOD_CYCLE:
            classiquePalettNext(1, debug);
        break; 
   }  
}  
void RGBeffect_palette::myPalette_prev(PALETTE_MODS palette_mod, boolean debug) {

    // palette_sav(p, debug);

    switch (palette_mod) {
        #ifdef PALETTES_COMPOSTIONS
        case PALETTE_MOD_COMPO:
            palette_compo_palette_next();
        break;     
        #endif  

        case PALETTE_MOD_FIRE:
            firePalettNext(-1, debug); 
        break; 
        case PALETTE_MOD_GRADIENTS:
            grandientPaletteNext(-1, debug);
        break; 

        case PALETTE_MOD_CYCLE:
            classiquePalettNext(-1, debug);
        break; 
   }  
}    
void RGBeffect_palette::myPalette_getPalette(PALETTE_MODS palette_mod, CRGBPalette16 & ret, boolean palette_play, boolean palette_toward){
    switch (palette_mod) {
        #ifdef PALETTES_COMPOSTIONS
        case PALETTE_MOD_COMPO:
                ret = pcCPAL;
        break;     
        #endif    

        case PALETTE_MOD_FIRE:
            ret = firePaletteCreate();
        break;         
        case PALETTE_MOD_CYCLE:
            ret = clPalette;
        break;
        case PALETTE_MOD_GRADIENTS:
            if (palette_play) {
                if (!palette_toward) ret =  grTargetPalette;
                else ret = grCurrentPalette;               
            }
            else  {
                ret =  grTargetPalette;
            } 

        break;                                    
    } 
}

unsigned long RGBeffect_palette_timerTower;


void RGBeffect_palette::myPalette_toward(uint8_t incr, int delay, adri_timer * timer){
        if (delay == 0) {
            nblendPaletteTowardPalette( grCurrentPalette, grTargetPalette, incr);
            return;
        }
        if ( timer->loop(delay) ) { nblendPaletteTowardPalette( grCurrentPalette, grTargetPalette, incr); }    
}
 
void RGBeffect_palette::myPalette_toward(uint8_t incr, int delay){
        if (delay == 0) {
            nblendPaletteTowardPalette( grCurrentPalette, grTargetPalette, incr);
            return;
        }
        if ((millis() - RGBeffect_palette_timerTower) > delay) {
            RGBeffect_palette_timerTower = millis();
            nblendPaletteTowardPalette( grCurrentPalette, grTargetPalette, incr);
        }
}