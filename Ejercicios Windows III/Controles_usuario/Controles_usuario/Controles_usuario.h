
// Controles_usuario.h: archivo de encabezado principal para la aplicaci�n PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// S�mbolos principales


// CControles_usuarioApp:
// Consulte la secci�n Controles_usuario.cpp para obtener informaci�n sobre la implementaci�n de esta clase
//

class CControles_usuarioApp : public CWinApp
{
public:
	CControles_usuarioApp();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementaci�n

	DECLARE_MESSAGE_MAP()
};

extern CControles_usuarioApp theApp;