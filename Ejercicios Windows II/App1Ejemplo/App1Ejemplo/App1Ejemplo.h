
// App1Ejemplo.h: archivo de encabezado principal para la aplicaci�n PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// S�mbolos principales


// CApp1EjemploApp:
// Consulte la secci�n App1Ejemplo.cpp para obtener informaci�n sobre la implementaci�n de esta clase
//

class CApp1EjemploApp : public CWinApp
{
public:
	CApp1EjemploApp();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementaci�n

	DECLARE_MESSAGE_MAP()
};

extern CApp1EjemploApp theApp;