
// Demo_Clase.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CDemo_ClaseApp:
// Consulte la sección Demo_Clase.cpp para obtener información sobre la implementación de esta clase
//

class CDemo_ClaseApp : public CWinApp
{
public:
	CDemo_ClaseApp();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CDemo_ClaseApp theApp;