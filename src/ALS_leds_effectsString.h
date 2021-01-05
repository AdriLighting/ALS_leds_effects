#ifndef ALS_LEDS_EFFECTSSTRING_H
	#define ALS_LEDS_EFFECTSSTRING_H
	#include <Arduino.h>
	#include <ArduinoJson.h>
	#include <ALS_leds_effects.h>

// ####################################################################################
	extern const char PROGMEM settingEffectKey_multipleEffect	[];
// ####################################################################################
	extern const char PROGMEM settingEffectKey_patternMod 		[];
// ####################################################################################
	extern const char PROGMEM settingEffectKey_colorMod 		[];
	extern const char PROGMEM settingEffectKey_colorModSelect	[];
// ####################################################################################
	extern const char PROGMEM settingEffectKey_paletteMod			[];
	extern const char PROGMEM settingEffectKey_palettePlay			[];
	extern const char PROGMEM settingEffectKey_paletteToward		[];
	extern const char PROGMEM settingEffectKey_paletteDelay			[];
	extern const char PROGMEM settingEffectKey_paletteTowardDelay	[];
	extern const char PROGMEM settingEffectKey_paletteTowardIncr	[];
	extern const char PROGMEM settingEffectKey_paletteIndex			[];
// ####################################################################################
	extern const char PROGMEM settingEffectKey_reverse 			[];
	extern const char PROGMEM settingEffectKey_reverseTimer 	[];
	extern const char PROGMEM settingEffectKey_reverseDelay 	[];
// ####################################################################################
	extern const char PROGMEM settingEffectKey_hue 				[];
// ####################################################################################
	extern const char PROGMEM settingEffectKey_hueDelta 		[];
// ####################################################################################
	extern const char PROGMEM settingEffectKey_hueMod 			[];
	extern const char PROGMEM settingEffectKey_hueRnd 			[];
	extern const char PROGMEM settingEffectKey_hueDelay 		[];	
	extern const char PROGMEM settingEffectKey_hueMin			[];
	extern const char PROGMEM settingEffectKey_hueMax			[];
// ####################################################################################
	extern const char PROGMEM settingEffectKey_isTw 			[];
	extern const char PROGMEM settingEffectKey_tw 				[];
	extern const char PROGMEM settingEffectKey_sat 				[];
	extern const char PROGMEM settingEffectKey_bri 				[];

	extern const char PROGMEM settingEffectKey_cRgb 			[];
	extern const char PROGMEM settingEffectKey_cRgb_cp 			[];
	extern const char PROGMEM settingEffectKey_cRgb_2 			[];
	extern const char PROGMEM settingEffectKey_cRgb_doubl 		[];
	extern const char PROGMEM settingEffectKey_cRgb_isDoubl 	[];
// ####################################################################################
	extern const char PROGMEM settingEffectKey_delay 			[];
	extern const char PROGMEM settingEffectKey_speed 			[];
// ####################################################################################
	extern const char PROGMEM settingEffectKey_isScale 			[];
	extern const char PROGMEM settingEffectKey_scale 			[];
	extern const char PROGMEM settingEffectKey_fade 			[];
// ####################################################################################
	extern const char PROGMEM settingEffectKey_isCv 			[];
	extern const char PROGMEM settingEffectKey_cv 				[];

	extern const char PROGMEM settingEffectKey_rep 				[];




	enum effectSettingReturn_mod
	{
		esrm_value,
		esrm_full,
		esrm_grp,
		esrm_multiple
	};
	struct effectSettingString_reponse {
		const char * id;
	} ;		
	struct effectSettingString_list {
		const char * name;
		effectSettingReturn_mod mod;
		const char * grpName;
		boolean (*condition)() ;
        effectSettingString_reponse * list;
        int cnt;


	};	
	struct effectSettingGrp_list {
		const char * name;
		boolean (*condition)() ;
	};		
	void effectSettingStringList_keyToJson(const char * search, String & ret);	
	void effectSettingStringList_keyToJson(String search, String & ret);	
	void effectSettingStringList_keyFromJson(String search, String & ret);	
	String effectSettingStringList_print();
	void effectSetting_toJson(JsonObject & root, effect_id * ptr);
	void effectSettingStringList_retGrpFromJson(String search, effectSettingReturn_mod & ret);

	extern PROGMEM effectSettingString_list effectSettingString_fullList [];
	extern uint8_t effectSettingString_fullListCount;

	extern boolean effectSetting_toJson_keyInNumber;

	void effectSavSetting_toJson(JsonObject & root, effect_id * ptr);
	void effectSettingLoad_fromJson(DynamicJsonDocument  root, effect_id * ptr);

	void effectSetting_toJson(int mod, JsonObject & root, effect_id * ptr);
	void effectSetting_toJson_v2(int mod, JsonObject & root, effect_id * ptr);
#endif