#include "ALS_leds_effectsString.h"
#include <adri_tools.h>

// ####################################################################################
	const char PROGMEM settingEffectKey_multipleEffect	[] = "multipleEffect";
// ####################################################################################
	const char PROGMEM settingEffectKey_patternMod 		[] = "patternMod";
// ####################################################################################
	const char PROGMEM settingEffectKey_colorMod 		[] = "colorMod";
	const char PROGMEM settingEffectKey_colorModSelect	[] = "colorModSelect";
// ####################################################################################
	const char PROGMEM settingEffectKey_paletteMod				[] = "paletteMod";
	const char PROGMEM settingEffectKey_palettePlay				[] = "palettePlay";
	const char PROGMEM settingEffectKey_paletteToward			[] = "paletteToward";
	const char PROGMEM settingEffectKey_paletteDelay			[] = "paletteDelay";
	const char PROGMEM settingEffectKey_paletteTowardDelay		[] = "paletteTowardDelay";
	const char PROGMEM settingEffectKey_paletteTowardIncr		[] = "paletteTowardIncr";
// ####################################################################################
	const char PROGMEM settingEffectKey_reverse 		[] = "reverse";
	const char PROGMEM settingEffectKey_reverseTimer 	[] = "reverse_timer";
	const char PROGMEM settingEffectKey_reverseDelay 	[] = "reverse_delay";
// ####################################################################################
	const char PROGMEM settingEffectKey_hue 			[] = "hue";
// ####################################################################################
	const char PROGMEM settingEffectKey_hueDelta 		[] = "hue_delta";
// ####################################################################################
	const char PROGMEM settingEffectKey_hueMod 			[] = "hue_mod";
	const char PROGMEM settingEffectKey_hueRnd 			[] = "hue_rnd";
	const char PROGMEM settingEffectKey_hueDelay 		[] = "hue_delay";	
	const char PROGMEM settingEffectKey_hueMin			[] = "hue_min";
	const char PROGMEM settingEffectKey_hueMax			[] = "hue_max";
// ####################################################################################
	const char PROGMEM settingEffectKey_tw 				[] = "tw";
	const char PROGMEM settingEffectKey_isTw 			[] = "isTw";
	const char PROGMEM settingEffectKey_sat 			[] = "sat";
	const char PROGMEM settingEffectKey_bri 			[] = "bri";
	const char PROGMEM settingEffectKey_cRgb_cp 		[] = "cRgb_cp";
	const char PROGMEM settingEffectKey_cRgb 			[] = "cRgb";
	const char PROGMEM settingEffectKey_cRgb_2 			[] = "cRgb_2";
	const char PROGMEM settingEffectKey_cRgb_doubl 		[] = "cRgb_d";
	const char PROGMEM settingEffectKey_cRgb_isDoubl 	[] = "cRgb_i";
// ####################################################################################
	const char PROGMEM settingEffectKey_delay 			[] = "delay";
	const char PROGMEM settingEffectKey_speed 			[] = "speed";
// ####################################################################################
	const char PROGMEM settingEffectKey_isScale 		[] = "isScale";
	const char PROGMEM settingEffectKey_scale 			[] = "scale";
// ####################################################################################
	const char PROGMEM settingEffectKey_isCv 			[] = "isCv";
	const char PROGMEM settingEffectKey_cv 				[] = "cv";
// ####################################################################################
	const char PROGMEM settingEffectKey_fade 			[] = "fade";
// ####################################################################################
	const char PROGMEM settingEffectKey_waveCount		[] = "waveCount";
	const char PROGMEM settingEffectKey_waveRotation	[] = "waveRotation";

	const char PROGMEM settingEffectKey_rep			[] = "rep";





boolean effectSetting_create_es(){return true;};
boolean effectSetting_create_default(){return true;};
boolean effectSetting_create_ere();
boolean effectSetting_create_ep();
boolean effectSetting_create_eh();
boolean effectSetting_create_er();
boolean effectSetting_create_hue();
boolean effectSetting_create_hueMinMax();
boolean effectSetting_create_satBri();
boolean effectSetting_create_doubleColor();
boolean effectSetting_create_cv();
boolean effectSetting_create_tw();


 PROGMEM effectSettingString_reponse rrl_r1 [] = {
		{settingEffectKey_bri},
		{settingEffectKey_sat},
		{settingEffectKey_hue},
		{settingEffectKey_cRgb},
};

 PROGMEM effectSettingString_list effectSettingString_fullList [] = {
	{settingEffectKey_multipleEffect, 			esrm_value, 	"", 	effectSetting_create_default,		NULL, 0},

	{settingEffectKey_patternMod, 				esrm_value, 	"", 	effectSetting_create_default,		NULL, 0},

	{settingEffectKey_colorMod, 				esrm_full, 		"es", 	effectSetting_create_default,		NULL, 0},
	{settingEffectKey_colorModSelect, 			esrm_full,  	"es", 	effectSetting_create_default,		NULL, 0},

	{settingEffectKey_paletteMod, 				esrm_full, 		"ep", 	effectSetting_create_ep, 			NULL, 0},
	{settingEffectKey_palettePlay, 				esrm_value, 	"ep", 	effectSetting_create_ep, 			NULL, 0},
	{settingEffectKey_paletteToward, 			esrm_value, 	"", 	effectSetting_create_default,		NULL, 0},
	{settingEffectKey_paletteDelay,				esrm_value, 	"ep",	effectSetting_create_ep, 			NULL, 0},
	{settingEffectKey_paletteTowardDelay, 		esrm_value, 	"", 	effectSetting_create_default,		NULL, 0},
	{settingEffectKey_paletteTowardIncr, 		esrm_value,		"", 	effectSetting_create_default,		NULL, 0},

	{settingEffectKey_reverse, 					esrm_value, 	"ere", 	effectSetting_create_ere, 			NULL, 0},
	{settingEffectKey_reverseTimer, 			esrm_value, 	"ere", 	effectSetting_create_ere, 			NULL, 0},
	{settingEffectKey_reverseDelay, 			esrm_value, 	"ere", 	effectSetting_create_ere, 			NULL, 0},

	{settingEffectKey_hue, 						esrm_multiple, 	"er", 	effectSetting_create_hue, 			rrl_r1, 4},

	{settingEffectKey_hueDelta, 				esrm_value, 	"", 	effectSetting_create_default,		NULL, 0},

	{settingEffectKey_hueMod, 					esrm_full, 		"es", 	effectSetting_create_default,		NULL, 0},
	{settingEffectKey_hueRnd, 					esrm_full, 		"eh",	effectSetting_create_eh, 			NULL, 0},
	{settingEffectKey_hueDelay, 				esrm_value, 	"eh", 	effectSetting_create_eh, 			NULL, 0},
	{settingEffectKey_hueMin, 					esrm_value, 	"eh", 	effectSetting_create_hueMinMax, 	NULL, 0},
	{settingEffectKey_hueMax, 					esrm_value, 	"eh", 	effectSetting_create_hueMinMax, 	NULL, 0},

	{settingEffectKey_sat, 						esrm_multiple, 	"es", 	effectSetting_create_satBri, 		rrl_r1, 4},
	{settingEffectKey_bri, 						esrm_multiple, 	"es", 	effectSetting_create_satBri, 		rrl_r1, 4},

	{settingEffectKey_cRgb, 					esrm_multiple, 	"er", 	effectSetting_create_er, 			rrl_r1, 4},
	{settingEffectKey_cRgb_2, 					esrm_value, 	"er", 	effectSetting_create_doubleColor,	NULL, 0},
	{settingEffectKey_cRgb_doubl, 				esrm_value, 	"er", 	effectSetting_create_doubleColor, 	NULL, 0},
	{settingEffectKey_cRgb_isDoubl, 			esrm_value, 	"er", 	effectSetting_create_er, 			NULL, 0},

	{settingEffectKey_delay, 					esrm_value, 	"", 	effectSetting_create_default,		NULL, 0},
	{settingEffectKey_speed, 					esrm_value, 	"es", 	effectSetting_create_default,		NULL, 0},

	{settingEffectKey_isScale, 					esrm_value, 	"", 	effectSetting_create_default,		NULL, 0},
	{settingEffectKey_scale, 					esrm_value, 	"es", 	effectSetting_create_default,		NULL, 0},
	{settingEffectKey_fade, 					esrm_value, 	"es", 	effectSetting_create_default,		NULL, 0},

	{settingEffectKey_isCv, 					esrm_value, 	"", 	effectSetting_create_default,		NULL, 0},
	{settingEffectKey_cv, 						esrm_value, 	"es", 	effectSetting_create_cv, 			NULL, 0},
	
	{settingEffectKey_tw, 						esrm_value, 	"er", 	effectSetting_create_tw, 			NULL, 0},
	{settingEffectKey_isTw, 					esrm_full, 		"er", 	effectSetting_create_er, 			NULL, 0},
	{settingEffectKey_cRgb_cp, 					esrm_multiple,	"er", 	effectSetting_create_er, 			rrl_r1, 4},
	{settingEffectKey_rep, 						esrm_value, 	"es", 	effectSetting_create_default,		NULL, 0},


};
uint8_t effectSettingString_fullListCount = ARRAY_SIZE(effectSettingString_fullList);

PROGMEM effectSettingGrp_list effectSettingGrp_List [] = {
	{"es",	effectSetting_create_es},
	{"ere",	effectSetting_create_ere},
	{"ep",	effectSetting_create_ep},
	{"eh",	effectSetting_create_eh},
	{"er",	effectSetting_create_er},
};
uint8_t effectSettingGrp_ListCount = ARRAY_SIZE(effectSettingGrp_List);

boolean effectSetting_toJson_keyInNumber = true;

String effectSettingStringList_print(){
	fsprintf("\n[effectSettingStringList_print]\n");
	for (int i = 0; i < effectSettingString_fullListCount; ++i)
	{
		fsprintf("[%5d][%s]\n", i, effectSettingString_fullList[i].name );
	}
}
void effectSettingStringList_keyToJson(const char * search, String & ret){

	if (!effectSetting_toJson_keyInNumber) {
			ret = ch_toString(search);
			return;
	}
	for (int i = 0; i < effectSettingString_fullListCount; ++i)
	{
		if (effectSettingString_fullList[i].name == search) {
			ret = String(i);
			break;
		}
	}
}
void effectSettingStringList_keyToJson(String search, String & ret){
	for (int i = 0; i < effectSettingString_fullListCount; ++i)
	{
		if (ch_toString(effectSettingString_fullList[i].name) == search) {
			ret = String(i);
			break;
		}
	}
}

void effectSettingStringList_keyFromJson(String search, String & ret){
	for (int i = 0; i < effectSettingString_fullListCount; ++i)
	{
		if (String(i) == search) {
			ret = ch_toString(effectSettingString_fullList[i].name);
			break;
		}
	}
}
void effectSettingStringList_retGrpFromJson(String search, effectSettingReturn_mod & ret){
	for (int i = 0; i < effectSettingString_fullListCount; ++i)
	{
		if (String(i) == search) {
			ret = effectSettingString_fullList[i].mod;
			break;
		}
	}
}

void effectSettingLoad_fromJson(DynamicJsonDocument  root, effect_id * ptr){

}
void effectSavSetting_toJson(JsonObject & root, effect_id * ptr){
         ptr->savSetting(root);
}
void effectSetting_toJson(int mod, JsonObject & root, effect_id * ptr){
    String value;
    String nullValue = "null";
	String key;

    // fsprintf("\n[effectSetting_print]\n");
	for (int i = 0; i < effectSettingString_fullListCount; ++i)
	{
        ptr->settingGetValueByKey(effectSettingString_fullList[i].name, value);
        if (value != nullValue) {
			// fsprintf("[key : %15s] [value : %10s]\n", effectSettingString_fullList[i].name, value.c_str());
			key = ch_toString(effectSettingString_fullList[i].name);
	        root[key] = value;
		}
	}

	 // effectSetting_toJson_v2(ptr);
}


boolean effectSetting_create_ere(){
	String value;
    effectIdInstance()->settingGetValueByKey(settingEffectKey_reverse, value);
	if (value != "null") return true;
	return false;
}

boolean effectSetting_create_ep(){
    EFFECTCOLOR_MODS color_mod_select;
    effectIdInstance()->get_colorModSelect(color_mod_select);
	if (color_mod_select == EFFECTCOLOR_PALETTE) return true;
	return false;
}

boolean effectSetting_create_eh(){
    EFFECTCOLOR_MODS color_mod_select;
    effectIdInstance()->get_colorModSelect(color_mod_select);
	if (color_mod_select != EFFECTCOLOR_HUE) return false;
	HUE_MODS hue_mod;
    effectIdInstance()->get_hueMod(hue_mod);
	if (hue_mod == HUE_MOD_TIMER) return true;	
	return false;
}
boolean effectSetting_create_hueMinMax(){
	if (!effectSetting_create_eh()) return false;

	int hue_rnd = 1;
    effectIdInstance()->get_hueRnd(hue_rnd);
	if(hue_rnd<2) return true;

	return false;
}
boolean effectSetting_create_cv(){
    EFFECTCOLOR_MODS color_mod_select;
    effectIdInstance()->get_colorModSelect(color_mod_select);
	if (color_mod_select == EFFECTCOLOR_HUE) return true;
	return false;
}

boolean effectSetting_create_er(){
	HUE_MODS hue_mod;
    effectIdInstance()->get_hueMod(hue_mod);
	if((hue_mod == HUE_MOD_CC)||(hue_mod == HUE_MOD_CCHUE)) return true;
	return false;
}
boolean effectSetting_create_hue(){
	if (!effectSetting_create_er()) return false;

    String value;
    effectIdInstance()->settingGetValueByKey(settingEffectKey_isTw, value);
    if (value != "null") {
        if (value == "1") return false;
    }

	HUE_MODS hue_mod;
    effectIdInstance()->get_hueMod(hue_mod);
	if (hue_mod == HUE_MOD_CCHUE) return true;

	return false;
}	
boolean effectSetting_create_tw(){
	if (!effectSetting_create_er()) return false;

    String value;
    effectIdInstance()->settingGetValueByKey(settingEffectKey_isTw, value);
    if (value != "null") {
        if (value == "1") return true;
    }
	return false;
}	
boolean effectSetting_create_doubleColor(){
	if (!effectSetting_create_er()) return false;

    boolean color_rgb_isDoubl = false;
    effectIdInstance()->get_isDoubleColor(color_rgb_isDoubl);

    if (color_rgb_isDoubl) return true;

	return false;
}	

boolean effectSetting_create_satBri(){
    String value;
    effectIdInstance()->settingGetValueByKey(settingEffectKey_isTw, value);
    if (value != "null") {
        if (value == "1") return false;
    }
	return true;
}	

void effectSetting_toJson_v2(int mod, JsonObject & root, effect_id * ptr){ 
	String 	value;
	String 	key;
	boolean addValue 	= false;
	String 	nullValue 	= "null";

	// fsprintf("\n[effectSetting_toJson_v2] %s\n", ptr->_name.c_str());

	for (int j = 0; j < effectSettingGrp_ListCount; ++j) {

		if (!effectSettingGrp_List[j].condition()) continue;

		JsonObject object = root.createNestedObject(effectSettingGrp_List[j].name);

		for (int i = 0; i < effectSettingString_fullListCount; ++i) {

			addValue = false;

			if (effectSettingString_fullList[i].grpName == effectSettingGrp_List[j].name) {

				if (effectSettingString_fullList[i].condition != NULL) {
					if (!effectSettingString_fullList[i].condition()) continue;
					else addValue = true;
				} else addValue = true;

				if (addValue) {
		        	ptr->settingGetValueByKey(effectSettingString_fullList[i].name, value);
			        if (value != nullValue) {
						effectSettingStringList_keyToJson(effectSettingString_fullList[i].name, key);
						// fsprintf("[%s] [%15s][%s]\n", effectSettingGrp_List[j].name, effectSettingString_fullList[i].name, value.c_str());
						if (mod == 0) object[key] = value;
						if (mod == 1) object[ch_toString(effectSettingString_fullList[i].name)] = value;
				    }				
				}
			}
		}

		// fsprintf("\n");
	}

}

void effectSetting_toJson(JsonObject & root, effect_id * ptr){
	effectSetting_toJson_v2(0, root, ptr);
}


