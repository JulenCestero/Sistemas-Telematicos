// Circulo.cpp: archivo de implementación
//

#include "stdafx.h"
#include "Controles_usuario.h"
#include "Circulo.h"


// CCirculo

IMPLEMENT_DYNAMIC(CCirculo, CWnd)

CCirculo::CCirculo()
{
  option = 0;
  pens[0].CreateSolidBrush(RGB(255,255,255));
  pens[1].CreateSolidBrush(RGB(255, 0, 0,));
}

CCirculo::~CCirculo()
{
}


BEGIN_MESSAGE_MAP(CCirculo, CWnd)
  ON_WM_PAINT()
END_MESSAGE_MAP()



// Controladores de mensajes de CCirculo




void CCirculo::OnPaint()
{
  CPaintDC dc(this); // device context for painting
  CRect r;
  dc.SelectObject(&pens[option]);
  GetClientRect(r);
  dc.Ellipse(r);

    // TODO: Agregue aquí su código de controlador de mensajes
    // No llama a CWnd::OnPaint() para mensajes de pintura
}
