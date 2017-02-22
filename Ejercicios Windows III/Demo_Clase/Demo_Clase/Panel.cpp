// Panel.cpp: archivo de implementación
//

#include "stdafx.h"
#include "Demo_Clase.h"
#include "Panel.h"


// CPanel

IMPLEMENT_DYNAMIC(CPanel, CWnd)

CPanel::CPanel()
{

}

CPanel::~CPanel()
{
}


BEGIN_MESSAGE_MAP(CPanel, CWnd)
  ON_WM_PAINT()
END_MESSAGE_MAP()



// Controladores de mensajes de CPanel




void CPanel::OnPaint()
{
  CPaintDC dc(this); // device context for painting
  CRect r;
  GetClientRect(r);
  dc.FillSolidRect(r, RGB(128,128,255));
    // TODO: Agregue aquí su código de controlador de mensajes
    // No llama a CWnd::OnPaint() para mensajes de pintura
}
