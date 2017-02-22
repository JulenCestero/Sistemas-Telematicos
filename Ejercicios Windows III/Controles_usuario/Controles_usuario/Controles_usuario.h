
// Controles_usuario.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CControles_usuarioApp:
// Consulte la sección Controles_usuario.cpp para obtener información sobre la implementación de esta clase
//

class CControles_usuarioApp : public CWinApp
{
public:
	CControles_usuarioApp();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CControles_usuarioApp theApp;