#include "mainApp.h"
#include "miApp.h"
#include <conio.h>	// _kbhit

miApp app2;	// objeto global

MainApp* MainApp::pm = 0;

void main(){
	MainApp::pm->Init();
	while(MainApp::pm != 0){
		MainApp::pm->Loop();
		if(_kbhit()){
			char ch = _getch();
			MainApp::pm->OnChar(ch);
		}
	}
}