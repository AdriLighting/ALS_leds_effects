#include "ALS_leds_effects.h"

#include <adri_tools.h>

namespace  {
	int activeIndex = -1;
} // 

// #define DEBUG





#ifdef EFFLIST_MATRIX
    const char PROGMEM chooseEffect_sinusoid            [] = "Sinusoid";

    const char PROGMEM chooseEffect_colorwaveMatrix     [] = "ColorWaveMatrix";
    const char PROGMEM chooseEffect_metalBalls          [] = "MetalBalls";
    const char PROGMEM chooseEffect_matrix_1            [] = "Matrix";
    const char PROGMEM chooseEffect_movingCube          [] = "MovingCube";
    const char PROGMEM chooseEffect_bouncingBalls       [] = "BouncingBalls";
    const char PROGMEM chooseEffect_doubleComets        [] = "Comets";
    const char PROGMEM chooseEffect_tripleComets        [] = "TripleComets";
    const char PROGMEM chooseEffect_fractionalFire      [] = "FractionalFire";
    const char PROGMEM chooseEffect_noise_2             [] = "Noise_2";
    const char PROGMEM chooseEffect_noise               [] = "Noise";
    const char PROGMEM chooseEffect_whirl               [] = "Whirl";
    const char PROGMEM chooseEffect_flock               [] = "Flock";
    const char PROGMEM chooseEffect_wave                [] = "Wave";
    const char PROGMEM chooseEffect_fire18              [] = "Fire18";
    const char PROGMEM chooseEffect_multiple            [] = "Multiple";
    const char PROGMEM chooseEffect_spiral              [] = "Spiral";
    const char PROGMEM chooseEffect_prismata            [] = "Prismata";

    const char PROGMEM chooseEffect_rainbow_Matrix      [] = "ArcEnCiel_Digonale";
    const char PROGMEM chooseEffect_rainbow_MatrixH     [] = "ArcEnCiel_Horizontal";
    const char PROGMEM chooseEffect_rainbow_MatrixV     [] = "ArcEnCiel_Vertical";
    const char PROGMEM chooseEffect_rainbow_smoke       [] = "ArcEnCiel_fumee";

    const char PROGMEM chooseEffect_fire                [] = "Fire";

#ifdef LAMP_TORCH
    const char PROGMEM chooseEffect_torch               [] = "Torch";
#endif   
 
    const char PROGMEM chooseEffect_clock1              [] = "Clock_horizontal_1";
    const char PROGMEM chooseEffect_clock2              [] = "Clock";
    const char PROGMEM chooseEffect_cube                [] = "Cube";    

    const char PROGMEM chooseEffect_spiro               [] = "Spiro";
    const char PROGMEM chooseEffect_spiral_2            [] = "Spiral_2";
    const char PROGMEM chooseEffect_arrow               [] = "Arrow";
    const char PROGMEM chooseEffect_plasma              [] = "Plasma";
    const char PROGMEM chooseEffect_electricMandala     [] = "Electric_Mandala";

#endif

    const char PROGMEM chooseEffect_colorwave           [] = "Colorwave";


    const char PROGMEM chooseEffect_pride               [] = "Pride";

#ifdef EFFLIST_SEGMENT    
    const char PROGMEM chooseEffect_prideSyncro         [] = "Pride_Syncro";
    const char PROGMEM chooseEffect_fire2012_syncro     [] = "Fire_Syncro";
    const char PROGMEM chooseEffect_colorwaveSyncro     [] = "Colorwave_Syncro";
    const char PROGMEM chooseEffect_colorpalette_syncro [] = "ColorPalette_Syncro";
#endif


#ifdef EFFLIST_FX
    const char PROGMEM chooseEffect_cwrev               [] = "ColorWipe_Reverse";
    const char PROGMEM chooseEffect_cwrevinv            [] = "ColorWipe_Reverse_Inverse";
    const char PROGMEM chooseEffect_cwrnd               [] = "ColorWipe_Random";
    const char PROGMEM chooseEffect_cwinv               [] = "ColorWipe_Inverse";
    const char PROGMEM chooseEffect_breath              [] = "Breath";
    const char PROGMEM chooseEffect_scan                [] = "Scan";
    const char PROGMEM chooseEffect_dualscan            [] = "DualScan";
    const char PROGMEM chooseEffect_fade                [] = "Fade";
    const char PROGMEM chooseEffect_neorainbow          [] = "ArcEnCiel";
    const char PROGMEM chooseEffect_neorainbowcycle     [] = "ArcEnCiel_Cycle";
    const char PROGMEM chooseEffect_dynamic             [] = "Dynamic";
    const char PROGMEM chooseEffect_multidynamic        [] = "MultiDynamic";
#endif

#ifdef EFFLIST_ARMOIRE
    const char PROGMEM chooseEffect_amrmoire_staticrnd      [] = "Amrmoire_Static_Aléatoir";
    const char PROGMEM chooseEffect_amrmoire_statichue      [] = "Amrmoire_Static_Color";
    const char PROGMEM chooseEffect_amrmoire_cychue         [] = "Amrmoire_Cycle_Color";
#endif

    const char PROGMEM chooseEffect_neo_wave                [] = "neo_wave";
    const char PROGMEM chooseEffect_neo_rainbow             [] = "neo_rainbow";

    const char PROGMEM chooseEffect_rainbow             [] = "ArcEnCiel_serpent";
    const char PROGMEM chooseEffect_colorswitchbounce   [] = "colorswitchBounce";
    const char PROGMEM chooseEffect_cw                  [] = "colorWipe";
    const char PROGMEM chooseEffect_colorpalette        [] = "ColorPalette";
    const char PROGMEM chooseEffect_color               [] = "Color";





effect_id::effect_id(const String &id)
{
    _name   = id;
    _id     = id;
}

effect_id::~effect_id()
{
}





uint8_t chooseEffectList_cnt;
chooseEffectList * chooseEffectList_ptr = nullptr;

void chooseEffect_itialize(chooseEffectList * list, uint8_t count) {
    chooseEffectList_ptr = list;
    chooseEffectList_cnt = count;
}

uint8_t chooseEffectRegisterCount;
chooseEffecRegistertList * chooseEffectRegister_ptr = nullptr;
void chooseEffectRegister_initialize(chooseEffecRegistertList * ptr, uint8_t cnt){
    chooseEffectRegister_ptr    = ptr;
    chooseEffectRegisterCount   = cnt;
}


effect_id * effectId_array [40];
int effectId_array_cnt = 0;


effect_manager * effect_managerPtr;
effect_manager::effect_manager(){

    effect_managerPtr = this;

    #ifdef DEBUG
        fsprintf("\n[effect_manager::instance]\n");
    #endif

    for (int i = 0; i < chooseEffectList_cnt; ++i) {
        
        for (int j = 0; j < chooseEffectRegisterCount; ++j) {

            if (chooseEffectList_ptr[i].name == chooseEffectRegister_ptr[j].name) {

                #ifdef DEBUG
                    fsprintf("#%d|%d - %s\n", i, j, chooseEffectRegister_ptr[j].name);
                #endif

                chooseEffectRegister_ptr[j].registerEffect(chooseEffectRegister_ptr[j].name, effectId_array_cnt); 
                effectId_array[effectId_array_cnt]->_namePos = chooseEffectRegister_ptr[j].addEffect;
                effectId_array_cnt++;
            }
        }         
    } 


    // registerEffect_rainbow_matrix(chooseEffect_rainbow_Matrix, effectId_array_cnt);
    // effectId_array_cnt++;
    // registerEffect_rainbow(chooseEffect_rainbow, effectId_array_cnt);
    // effectId_array_cnt++;

}
void effect_manager::print_list(){
	fsprintf("\n[effect_manager::print_list]\n");
    for (int i = 0; i < chooseEffectList_cnt; ++i) {
        for (int j = 0; j < chooseEffectRegisterCount; ++j) {
            if (chooseEffectList_ptr[i].name == chooseEffectRegister_ptr[j].name) {
				fsprintf("#%d|%d - %s\n", i, j, chooseEffectRegister_ptr[j].name);
            }
        }         
    } 
}

void effect_manager::buildEffectsJson(){
}

void effect_manager::processAllEffects() {
}


void effect_manager::activateEffect(int8_t index){
    if (index >= effectId_array_cnt) {
        index = 0;
    }    
    
    if (activeIndex>=0) {
        desactivateEffect();}

    #ifdef PATHEAPSTATS
        if (heap_pass>1) heapStatArray[heap_lastPos]->end();
    #endif

    if (activeIndex != index) {
        activeIndex = index;
    }

	effect_id * effect = effectId_array[index];

    #ifdef DEBUG
        Serial.printf_P(PSTR("\n[effect_manager::activateEffect] : [%u]: %s\n"), index, effect->_name.c_str());
	#endif

    #ifdef PATHEAPSTATS    
        if (heap_pass>=1) heapStatArray[heap_newPos]->start();
    #endif
    
    // FastLED.clear();  
    // leds_settingPtr_get()->lamp_clear();

    effect->setup();

    effect->loadSettingFromFile("/effectsSetting/");

    // String out;
    // lampSettingInstance()->_effect->effect_json(out);
    // String namePos = String(effect->_namePos);
    // bool rFile = true;
    // File file = SPIFFS.open("/effectsSetting/"+namePos+".json", "r");
    // if (file) rFile = false;
    // else file.close();
    // fsprintf("\n[test]\nfile:%d\njson:\n\t%s\n",rFile,out.c_str());

}

void effect_manager::activateEffect(){
    #ifdef DEBUG
        Serial.printf_P(PSTR("\n[effect_manager::activateEffect] : %d\n"), activeIndex);
    #endif    
    effect_id *effect = effectId_array[activeIndex];
    effect->setup();
}

void effect_manager::changeEffectByNam_soft(const String &name) {
    #ifdef DEBUG
        Serial.printf_P(PSTR("\n[effect_manager::changeEffectByNam_soft] : %s\n"), name.c_str());
    #endif

    for (int index = 0; index < effectId_array_cnt; index++) {
        effect_id *effect = effectId_array[index];
        if (effect->_name == name) {
            #ifdef DEBUG
                Serial.printf_P(PSTR("\tpos : : %d\n"), index);
            #endif
            if (activeIndex>=0) {
                desactivateEffect();}                
                activeIndex = index;
            break;
        }
    }
}
void effect_manager::changeEffectByName(const String &name) {
    #ifdef DEBUG
        Serial.printf_P(PSTR("\n[effect_manager::changeEffectByName] : %s\n"), name.c_str());
    #endif

    for (int index = 0; index < effectId_array_cnt; index++) {
        effect_id *effect = effectId_array[index];
        if (effect->_name == name) {
            #ifdef DEBUG
                Serial.printf_P(PSTR("\tpos : : %d\n"), index);
            #endif
            
            activateEffect(index);

            break;
        }
    }
}
void effect_manager::getEffectByName(const String &name, uint8_t & ret) {
    #ifdef DEBUG
        Serial.printf_P(PSTR("\n[effect_manager::getEffectByName] : %s\n"), name.c_str());
    #endif
        
    for (int index = 0; index < effectId_array_cnt; index++) {
        effect_id *effect = effectId_array[index];
        if (effect->_name == name) {
            ret = index;
            #ifdef DEBUG
                Serial.printf_P(PSTR("\tpos : : %d\n"), index);
            #endif
            break;
        }
    }
}

void effect_manager::getEffectName(String & name) {
    #ifdef DEBUG
        Serial.printf_P(PSTR("\n[effect_manager::getEffectByName] : %s\n"), name.c_str());
    #endif
        name = activeEffect()->_name;
        
}



effect_id *effect_manager::activeEffect() {
    if (effectId_array_cnt > activeIndex) {
        return effectId_array[activeIndex];
    }
    return nullptr;
}
effect_id *effect_manager::getEffect(uint8_t index) {
    if (effectId_array_cnt > index) {
        return effectId_array[index];
    }
    return nullptr;
}

uint8_t effect_manager::activeEffectIndex() {
    return activeIndex;
}

void effect_manager::desactivateEffect(){
    activeEffect()->end();
}


void effect_manager::loop(){
    effect_id *effect = effectId_array[activeIndex];
    effect->loop();
    effect->upd();
}


void effect_manager::savSetting(JsonObject & root){
    effect_id *effect = effectId_array[activeIndex];
    effect->savSetting(root);
}
void effect_manager::settingToJson(JsonObject & root){
    effect_id *effect = effectId_array[activeIndex];
    effect->settingToJson(root);
}

void effect_manager::settingToSerial(){
    effect_id *effect = effectId_array[activeIndex];
    effect->settingToSerial();
}

void effect_manager::settingFromSerial(String key, String value, boolean user){
    effect_id *effect = effectId_array[activeIndex];
    effect->settingFromSerial(key, value, user);
}

void effect_manager::settingGetValueByKey(const char * key, String & value){
    effect_id *effect = effectId_array[activeIndex];
    effect->settingGetValueByKey(key, value);
}
void effect_manager::settingGetValueByKey(String key, String & value){
    effect_id *effect = effectId_array[activeIndex];
    effect->settingGetValueByKey(key, value);
}

void effect_manager::get_colorMod(EFFECTCOLOR_MODS & ret){
    effect_id *effect = effectId_array[activeIndex];
    effect->get_colorMod(ret);
}
void effect_manager::get_colorModSelect(EFFECTCOLOR_MODS & ret){
    effect_id *effect = effectId_array[activeIndex];
    effect->get_colorModSelect(ret);
}
void effect_manager::get_hueMod(HUE_MODS & ret){
    effect_id *effect = effectId_array[activeIndex];
    effect->get_hueMod(ret);
}
void effect_manager::get_isDoubleColor(boolean & ret){
    effect_id *effect = effectId_array[activeIndex];
    effect->get_isDoubleColor(ret);
}
void effect_manager::get_hueRnd(int & ret){
    effect_id *effect = effectId_array[activeIndex];
    effect->get_hueRnd(ret);
}
void effect_manager::get_isScale(boolean & ret){
    effect_id *effect = effectId_array[activeIndex];
    effect->get_isScale(ret);
}
void effect_manager::loadSettingFromJsonOject(JsonObject oject){
    effect_id *effect = effectId_array[activeIndex];
    effect->loadSettingFromJsonOject(oject);
}
void effect_manager::loadSettingFromFile(String folder){
    effect_id *effect = effectId_array[activeIndex];
    effect->loadSettingFromFile(folder);
}
effect_id * effectIdInstance(){
    return effect_manager_instance()->activeEffect();
}
void effect_manager::get_isCv(boolean & ret){
    effect_id *effect = effectId_array[activeIndex];
    effect->get_isCv(ret);
}

effect_manager * effect_manager_instance() {
    return effect_managerPtr;
}


void effect_manager_sav(int pos){

    File file = SPIFFS.open("/effectsSetting/"+String(effectId_array[pos]->_namePos)+".json", "w");
            #ifdef DEBUG
                fsprintf("\n[effect_manager_sav]\n");
                fsprintf("\tfilename: %s\n", effectId_array[pos]->_name.c_str());
            #endif
    if (file) {
             #ifdef DEBUG
                fsprintf("\tfileOpen: 1\n");
            #endif
        DynamicJsonDocument buffer(512);
        JsonObject  root    = buffer.to<JsonObject>();
        JsonObject object   = root.createNestedObject(effectId_array[pos]->_name);
        effectId_array[pos]->savSetting(object);
        serializeJson(buffer, file);
        #ifdef DEBUG
            serializeJson(buffer, Serial);
        #endif
        file.close(); 
    }   else {
            #ifdef DEBUG
                fsprintf("\tfileOpen: 0\n");
            #endif
        }
 
}
void effect_manager_load(int pos){
    effectId_array[pos]->loadSettingFromFile("/effectsSetting/");
}


