
// Demo_Clase.h: archivo de encabezado principal para la aplicaci�n PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// S�mbolos principales


// CDemo_ClaseApp:
// Consulte la secci�n Demo_Clase.cpp para obtener informaci�n sobre la implementaci�n de esta clase
//

class CDemo_ClaseApp : public CWinApp
{
public:
	CDemo_ClaseApp();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementaci�n

	DECLARE_MESSAGE_MAP()
};

extern CDemo_ClaseApp theApp;