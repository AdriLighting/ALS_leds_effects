#include "palettes_fire.h"

#include <arduino.h>
#include <FS.h>
#include <adri_tools.h>
#include <adri_spiff.h>
#include <adri_leds_colors.h>



CRGBPalette16 fire_p( CRGB::Black);

// String firePaletteNames[8];

int firePaletteCount ;
int firePalettes_position = 0;
palette_fire * palette_fire_array[10];

palette_fire::palette_fire(CRGBPalette16 pal, String name){
	_pal 	= pal;
	_name 	= name;
}


int firePalettNextPos(int delta, boolean debug) {
	int cPos = firePalettes_position;
	if 		(cPos == 0 && delta < 0) 						cPos = firePaletteCount - 1;
	else if (cPos >= firePaletteCount - 1 && delta > 0) 	cPos = 0;
	else 													cPos += delta;
	if 		(cPos >= firePaletteCount) 						cPos = 0;
	return cPos;
}
void firePalettNext(int delta, boolean debug) {
	firePalettes_position = firePalettNextPos(delta, debug);
  	// fire_p = firePaletteCreate();
}
// void firePaletteSet(int pos) {
//   fire_p = firePaletteCreate(firePaletteNames[pos]);
// }

int firePalettGetByName(String search) {
	int ret = -1;
	for (int i = 0; i < firePaletteCount; i++) {
			if (search == palette_fire_array[i]->_name) {ret = i;break;}
	}
	fsprintf("\n[firePalettGetByName] : %s - ret: %d\n" , search.c_str(), ret);
	return ret;
}
String firePaletteGetName(){
	return palette_fire_array[firePalettes_position]->_name;
}
String firePaletteGetName(int pos){
	return palette_fire_array[pos]->_name;
}


CRGBPalette16 firePaletteCreate(String pName){
	String path = "/sfp/" + pName + ".txt";
	File file = SPIFFS.open(path, "r");
	if(file){
		// fsprintf("[firePaletteObject] File read success : %s\n", path.c_str());
		CRGBPalette16 spiffPalette;
		int i = 0;
		while (file.position()<file.size()) {

			String xml = file.readStringUntil('\n');
			// fsprintf("i: %d - %s\n",i, xml.c_str());
			if (i < 16) spiffPalette[i] = parsecolorEx(xml);
			else break;
			i++;
			// 
		}
		file.close();
		return spiffPalette;
	} else {
		// fsprintf("[firePaletteObject] File not found : %s\n", path.c_str());
	}
}

String firePaletteFromSPIFF(String path) { 

	CRGBPalette16 pal;

	String s,t;

	Dir dir = SPIFFS.openDir(path);

	int i=0;

	while (dir.next()) {

		File f = dir.openFile("r");
		t = dir.fileName(); 

		t.replace(path, "");
		t.replace(".txt", "");
		// firePaletteNames[i] = t;

			pal = firePaletteCreate(t);
			palette_fire_array[i] = new palette_fire(pal, t);

		i++;

		t = String(i) + " : " + t + "\n";
		s += t;
		
	}
	firePaletteCount = i;
	return s;
}


String firePaletteObject() { 
	// String name;
	// CRGBPalette16 pal;
	// int cnt = 0;
	// Serial.println("");
	// for (int i = 0; i < firePaletteCount; i++) {
	// 	name = firePaletteNames[i];
	// 	if (name!=""){
	// 		fsprintf("i: %d - %s\n",i, name.c_str());
	// 		pal = firePaletteCreate(name);
	// 		palette_fire_array[cnt] = new palette_fire(pal, name);
	// 		cnt++;
	// 	}
	// }
}

CRGBPalette16 firePaletteCreate(){
	return palette_fire_array[firePalettes_position]->_pal;
}