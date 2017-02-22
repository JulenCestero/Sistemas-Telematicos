#pragma once
#include "mainApp.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class miApp: public MainApp
{
public:
	miApp();
	void Init();
	void Loop();
	void OnChar(char ch);
	//void End(){exit(exit_code);}
};