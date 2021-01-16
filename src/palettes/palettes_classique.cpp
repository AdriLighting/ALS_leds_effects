
#include "palettes_classique.h"

#include <arduino.h>
#include <FS.h>
#include <adri_tools.h>
#include <adri_spiff.h>
#include <adri_leds_colors.h>


#ifdef DEBUG_PALETTE
   #define DEBUG
#endif



int 			clPalettes_position = 0;
String 			cpFromSPIFF[18];
int 			cpFromSPIFFcount;
CRGBPalette16 	clPalette;


int classiquePalettGetByName(String search) {
	int ret = -1;
	for (int i = 0; i < cpFromSPIFFcount; i++) {
		if (search == cpFromSPIFF[i]) {ret = i;break;}
	}
	return ret;
}
String classiquePaletteGetName(){
	 return cpFromSPIFF[clPalettes_position];
}
String classiquePaletteGetName(int pos){
	 return cpFromSPIFF[pos];
}

String classiquePaletteFromSPIFF(String path) { 
	 String s,t;
	 Dir dir = LittleFS.openDir(path);
	 int i=0;
	 while (dir.next()) {

			File f = dir.openFile("r");
			t = dir.fileName(); 

			t.replace(path, "");
			t.replace(".txt", "");
			cpFromSPIFF[i] = t;
			i++;

			t = String(i) + " : " + t + "\n";
			s += t;
			
	 }
	 cpFromSPIFFcount = i;
	 return s;
}

CRGBPalette16 classiquePaletteCreate(String pName, boolean debug){
	 String path = "/scp/" + pName + ".txt";
	 File file = LittleFS.open(path, "r");
	 if(file){
	 		#ifdef DEBUG
				if (debug) fsprintf("[classiquePaletteCreate] File read succes : %s\n", path.c_str());
			#endif
			CRGBPalette16 spiffPalette;
			int i = 0;
			while (file.position()<file.size()) {

						String xml = file.readStringUntil('\n');
						
						if (i < 16) spiffPalette[i] = parsecolorEx(xml);
						else break;
						i++;
						// 
			}
			file.close();
			return spiffPalette;
	 } else {
	 		#ifdef DEBUG
				if (debug) fsprintf("[classiquePaletteCreate] File not found : %s\n", path.c_str());
			#endif
	 }
}
int classiquePalettNextPos(int delta, boolean debug) {
	int cPos = clPalettes_position;
	if 		(cPos == 0 && delta < 0) 					cPos = cpFromSPIFFcount - 1;
	else if (cPos >= cpFromSPIFFcount - 1 && delta > 0) cPos = 0;
	else 												cPos += delta;
	if 		(cPos >= cpFromSPIFFcount) 					cPos = 0;
	return cPos;
}
int classiquePalettNext(int delta, boolean debug) {
	clPalettes_position = classiquePalettNextPos(delta, debug);
	clPalette = classiquePaletteCreate(cpFromSPIFF[clPalettes_position], debug);
	return clPalettes_position;
}
