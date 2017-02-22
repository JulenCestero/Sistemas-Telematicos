#pragma once

class MainApp
{
public:
	static MainApp* pm;
public:
	MainApp(){pm = this;}
	virtual void Init() = 0;
	virtual void Loop() = 0;
	virtual void OnChar(char) = 0;
};
