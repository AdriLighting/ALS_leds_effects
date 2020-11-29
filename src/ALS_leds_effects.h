#ifndef ALS_LEDS_EFFECTS_H
	#define ALS_LEDS_EFFECTS_H 
	#include <Arduino.h>
	#include <ArduinoJson.h>
	#include "ALS_leds_effectsMod.h"

	#define EFFLIST_MATRIX
	#define EFFLIST_FX
	#define LAMP_TORCH
	#define EFFLIST_SEGMENT
	#define EFFLIST_ARMOIRE

#ifdef EFFLIST_MATRIX
    extern const char PROGMEM chooseEffect_sinusoid            [];
    extern const char PROGMEM chooseEffect_colorwaveMatrix     [];
    extern const char PROGMEM chooseEffect_metalBalls          [];
    extern const char PROGMEM chooseEffect_matrix_1            [];
    extern const char PROGMEM chooseEffect_movingCube          [];
    extern const char PROGMEM chooseEffect_bouncingBalls       [];
    extern const char PROGMEM chooseEffect_doubleComets        [];
    extern const char PROGMEM chooseEffect_tripleComets        [];
    extern const char PROGMEM chooseEffect_fractionalFire      [];
    extern const char PROGMEM chooseEffect_noise_2             [];
    extern const char PROGMEM chooseEffect_noise               [];
    extern const char PROGMEM chooseEffect_whirl               [];
    extern const char PROGMEM chooseEffect_flock               [];
    extern const char PROGMEM chooseEffect_wave                [];
    extern const char PROGMEM chooseEffect_fire18              [];
    extern const char PROGMEM chooseEffect_multiple            [];
    extern const char PROGMEM chooseEffect_spiral              [];
    extern const char PROGMEM chooseEffect_prismata            [];
    extern const char PROGMEM chooseEffect_rainbow_Matrix      [];
    extern const char PROGMEM chooseEffect_rainbow_MatrixH     [];
    extern const char PROGMEM chooseEffect_rainbow_MatrixV     [];
    extern const char PROGMEM chooseEffect_rainbow_smoke       [];
    extern const char PROGMEM chooseEffect_fire                [];

#ifdef LAMP_TORCH
    extern const char PROGMEM chooseEffect_torch               [];
#endif   
 
    extern const char PROGMEM chooseEffect_clock1              [];
    extern const char PROGMEM chooseEffect_clock2              [];
    extern const char PROGMEM chooseEffect_cube                []; 

    extern const char PROGMEM chooseEffect_spiro               [];
    extern const char PROGMEM chooseEffect_spiral_2            [];
    extern const char PROGMEM chooseEffect_arrow               [];
    extern const char PROGMEM chooseEffect_plasma              [];
    extern const char PROGMEM chooseEffect_electricMandala     [];

#endif

    extern const char PROGMEM chooseEffect_colorwave           [];
    extern const char PROGMEM chooseEffect_pride               [];

#ifdef EFFLIST_SEGMENT    
    extern const char PROGMEM chooseEffect_prideSyncro         [];
    extern const char PROGMEM chooseEffect_colorwaveSyncro     [];
	extern const char PROGMEM chooseEffect_fire2012_syncro      [];
	extern const char PROGMEM chooseEffect_colorpalette_syncro  [];

#endif



#ifdef EFFLIST_FX
    extern const char PROGMEM chooseEffect_cwrev               [];
    extern const char PROGMEM chooseEffect_cwrevinv            [];
    extern const char PROGMEM chooseEffect_cwrnd               [];
    extern const char PROGMEM chooseEffect_cwinv               [];
    extern const char PROGMEM chooseEffect_breath              [];
    extern const char PROGMEM chooseEffect_scan                [];
    extern const char PROGMEM chooseEffect_dualscan            [];
    extern const char PROGMEM chooseEffect_fade                [];
    extern const char PROGMEM chooseEffect_neorainbow          [];
    extern const char PROGMEM chooseEffect_neorainbowcycle     [];
    extern const char PROGMEM chooseEffect_dynamic             [];
    extern const char PROGMEM chooseEffect_multidynamic        [];
#endif

#ifdef EFFLIST_ARMOIRE
    extern const char PROGMEM chooseEffect_amrmoire_staticrnd      [];
    extern const char PROGMEM chooseEffect_amrmoire_statichue      [];
    extern const char PROGMEM chooseEffect_amrmoire_cychue         [];
#endif

    extern const char PROGMEM chooseEffect_neo_wave				[];
	extern const char PROGMEM chooseEffect_neo_rainbow          [];

    extern const char PROGMEM chooseEffect_rainbow             [];
    extern const char PROGMEM chooseEffect_colorswitchbounce   [];
    extern const char PROGMEM chooseEffect_cw                  [];
    extern const char PROGMEM chooseEffect_colorpalette        [];
    extern const char PROGMEM chooseEffect_color               [];

	struct chooseEffectList {
		const char 	* name;
	};	

	struct chooseEffecRegistertList {
		const char 	* name;
		int 		addEffect;
		void 		(* registerEffect)(const char * name, int pos);
		
	};	


	class effect_id
	{

	public:
		String 	_name;
		String 	_id;
		int 	_namePos;

		effect_id(){};
		effect_id(const String &id);

		virtual ~effect_id 						();

		virtual void loop 						()								{}
		virtual void upd 						()								{}
		virtual void setup 						()								{}	
		virtual void end 						()								{}	

		virtual void savSetting 				(JsonObject & ) 				{}	
		virtual void settingToJson 				(JsonObject & ) 				{}	
		virtual void settingToSerial 			()								{}	
		virtual void settingFromSerial(String , String , boolean )	 			{}	
		virtual void settingGetValueByKey 		(const char * , String & )		{}	
		virtual void settingGetValueByKey 		(String , String & )			{}	

		virtual void get_colorMod 				(EFFECTCOLOR_MODS & )			{}
		virtual void get_colorModSelect 		(EFFECTCOLOR_MODS & )			{}
		virtual void get_hueMod 				(HUE_MODS & )					{}
		virtual void get_isDoubleColor 			(boolean & )					{}
		virtual void get_hueRnd 				(int & )						{}
		virtual void get_isScale 				(boolean & )					{}
		virtual void get_isFade 				(boolean & )					{}
		virtual void get_isReverse 				(boolean & )					{}
		virtual void get_isCv 					(boolean & )					{}
		virtual void loadSettingFromJsonOject	(JsonObject )					{}
		virtual void loadSettingFromFile		(String )						{}	
		virtual void getEffectName 				(String & )	 					{}
	};	
	
	class effect_manager
	{
		
	public:
		effect_manager();
		virtual void 		processAllEffects();

		virtual void 		activateEffect(int8_t index);
		virtual void 		activateEffect();

		virtual void 		loop() ;


		virtual void 		changeEffectByName(const String &name);
		virtual void 		changeEffectByNam_soft(const String &name);
		
		virtual void 		getEffectByName(const String &name, uint8_t & ret);
		virtual effect_id 	* activeEffect();
		virtual effect_id 	* getEffect(uint8_t index);
		virtual void 		desactivateEffect();
		virtual uint8_t 	activeEffectIndex();

		virtual void 		savSetting(JsonObject & root);
		virtual void 		settingToJson(JsonObject & root);
		virtual void 		settingToSerial();
		virtual void 		settingFromSerial(String key, String value, boolean user);
		virtual void 		settingGetValueByKey(const char * key, String & value);
		virtual void 		settingGetValueByKey(String key, String & value);

		virtual void 		get_colorMod(EFFECTCOLOR_MODS & ret);
		virtual void 		get_colorModSelect(EFFECTCOLOR_MODS & ret);
		virtual void 		get_hueMod(HUE_MODS & ret);
		virtual void 		get_isDoubleColor(boolean & ret);
		virtual void 		get_hueRnd(int & ret);
		virtual void 		get_isScale(boolean & ret);
		virtual void 		get_isCv(boolean & ret);
		virtual void 		loadSettingFromJsonOject(JsonObject oject)		;
		virtual void 		loadSettingFromFile(String folder)							;

		virtual void  		getEffectName(String & name);

		void buildEffectsJson();
		void print_list();
		// std::vector<effect_id*> effects = {};
	protected:

	};


	effect_manager 	* effect_manager_instance();
	effect_id 		* effectIdInstance();

	extern 			effect_id * effectId_array [];

	void effect_manager_sav 	(int pos);
	void effect_manager_load 	(int pos);	

	void chooseEffectRegister_initialize 	(chooseEffecRegistertList * ptr, 	uint8_t cnt);
	void chooseEffect_itialize 				(chooseEffectList * list, 			uint8_t count);

	extern uint8_t chooseEffectList_cnt;
	extern chooseEffectList * chooseEffectList_ptr;
#endif