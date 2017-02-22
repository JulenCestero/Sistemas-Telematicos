
// App1Ejemplo.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CApp1EjemploApp:
// Consulte la sección App1Ejemplo.cpp para obtener información sobre la implementación de esta clase
//

class CApp1EjemploApp : public CWinApp
{
public:
	CApp1EjemploApp();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CApp1EjemploApp theApp;