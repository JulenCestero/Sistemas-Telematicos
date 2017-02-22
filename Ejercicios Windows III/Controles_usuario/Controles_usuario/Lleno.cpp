// Lleno.cpp: archivo de implementación
//

#include "stdafx.h"
#include "Controles_usuario.h"
#include "Lleno.h"


// CLleno

IMPLEMENT_DYNAMIC(CLleno, CWnd)

CLleno::CLleno()
{
  m_height = 0;
}

CLleno::~CLleno()
{
}


BEGIN_MESSAGE_MAP(CLleno, CWnd)
  ON_WM_PAINT()
END_MESSAGE_MAP()



// Controladores de mensajes de CLleno




void CLleno::OnPaint()
{
  CPaintDC dc(this); // device context for painting
  CRect r;
  GetClientRect(r);
  dc.FillSolidRect(r, RGB(255,255,255));
  CPen p1(PS_SOLID, 1, RGB(0,0,255));
  dc.SelectObject(&p1);
  dc.Rectangle(r);
  m_altura = m_height * r.bottom / 100;
  r.top = r.bottom - m_altura;
  dc.FillSolidRect(r, RGB(0,0,255));
  

    // TODO: Agregue aquí su código de controlador de mensajes
    // No llama a CWnd::OnPaint() para mensajes de pintura
}
