
// AmortiguadorII.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CAmortiguadorIIApp:
// Consulte la sección AmortiguadorII.cpp para obtener información sobre la implementación de esta clase
//

class CAmortiguadorIIApp : public CWinApp
{
public:
	CAmortiguadorIIApp();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CAmortiguadorIIApp theApp;