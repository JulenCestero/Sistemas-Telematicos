
// Amortiguador.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CAmortiguadorApp:
// Consulte la sección Amortiguador.cpp para obtener información sobre la implementación de esta clase
//

class CAmortiguadorApp : public CWinApp
{
public:
	CAmortiguadorApp();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CAmortiguadorApp theApp;