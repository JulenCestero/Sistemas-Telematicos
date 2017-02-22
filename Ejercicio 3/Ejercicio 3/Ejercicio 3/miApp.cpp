#include <iostream>
#include "miApp.h"
#include <Windows.h>
using namespace std;

miApp app1;
miApp::miApp(){
	cout << "Const. de miApp" << endl;
}

void miApp::Init(){
	cout << "Init. Press 'q' to exit" << endl;
}

void miApp::Loop(){
	static int c = 0;		// static --> mantiene el valor de la iteraccion anterior, al principio vale 1 pero luego 
											// c se guarda como 1, luego c++ --> 2, ...
	cout << "Loop.." << c++ << endl;
	Sleep(100);
}

void miApp::OnChar(char ch){
	if (ch == 'q'){
		this->pm = 0;
		cout << "Fin.." << endl;
	}
}