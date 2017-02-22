// Luz.cpp: archivo de implementación
//

#include "stdafx.h"
#include "Semaforo.h"
#include "Luz.h"


// CLuz

IMPLEMENT_DYNAMIC(CLuz, CWnd)

CLuz::CLuz()
{
  m_color = 0;
}

CLuz::~CLuz()
{
}


BEGIN_MESSAGE_MAP(CLuz, CWnd)
  ON_WM_PAINT()
END_MESSAGE_MAP()



// Controladores de mensajes de CLuz




void CLuz::OnPaint()
{
  CPaintDC dc(this); // device context for painting
  CRect r;
  CBrush brush1;
  GetClientRect(r);
  switch(m_color){
  case 0:
    brush1.CreateSolidBrush(RGB(0,0,0));
    dc.SelectObject(&brush1);
    dc.Ellipse(r);
    break;
  case 1:
    brush1.CreateSolidBrush(RGB(255,0,0));
    dc.SelectObject(&brush1);
    dc.Ellipse(r);
    break;
  case 2:
    brush1.CreateSolidBrush(RGB(255,255,0));
    dc.SelectObject(&brush1);
    dc.Ellipse(r);
    break;
  case 3:
    brush1.CreateSolidBrush(RGB(0,255,0));
    dc.SelectObject(&brush1);
    dc.Ellipse(r);
    break;
  }
    // TODO: Agregue aquí su código de controlador de mensajes
    // No llama a CWnd::OnPaint() para mensajes de pintura
}
