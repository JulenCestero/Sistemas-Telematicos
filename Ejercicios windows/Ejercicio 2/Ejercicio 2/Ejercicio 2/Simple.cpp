#include <afxwin.h>
#include "Simple.h"
#include <math.h>
CMiApp miObjeto; //crear un objeto global y empieza

BOOL CMiApp::InitInstance()
{
  CMiVentana *pV = new CMiVentana("Mi Ventana");
  pV->ShowWindow(SW_SHOWNORMAL);//SW_SHOWMAXIMIZED
  pV->UpdateWindow();
  CMiApp::m_pMainWnd = pV; //copiar el objeto
  return true;
}
//constructor
CMiVentana::CMiVentana(char *name)
{
  this->Create(NULL,name); //otras opciones
  miBoton.Create("Salir",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
    CRect(1,1,80,25),this,1001);
  btSetTimer.Create("Start Timer",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
    CRect(90,1,225,25),this,1002);
  btKillTimer.Create("Kill Timer",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
    CRect(235,1,375,25),this,1003);
  m_cont = 0;
  w = 200;
  Amp = w/4;
  frec = 10;
  m_x1 = m_y1 = 500;
  m_x2 = m_y2 = 550;
}
BEGIN_MESSAGE_MAP(CMiVentana, CFrameWnd)
ON_COMMAND( 1001, Salir )
ON_COMMAND( 1002, fnSetTimer)
ON_COMMAND( 1003, fnKillTimer)
ON_WM_MOUSEMOVE()
ON_WM_TIMER()
ON_WM_PAINT()
END_MESSAGE_MAP()
void CMiVentana::Salir()
{
  if ( MessageBox("Desea Salir?","Mis Mensajes",MB_YESNO) == IDYES) {
  this->OnClose();
  }
}

void CMiVentana::OnMouseMove(UINT nFlags, CPoint point)
{
  // TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado
  m_point = point;
  Invalidate(false);
}


void CMiVentana::OnTimer(UINT_PTR nIDEvent)
{
  m_cont++;
  int dx = Amp * cos(2 * 3.1416 * m_cont / frec);
  m_x1 += dx;
  m_x2 += dx;
  Invalidate(true);
}
void CMiVentana::fnSetTimer()
{
  SetTimer(1,100,NULL);
  Invalidate(true);
}
void CMiVentana::fnKillTimer()
{
  m_cont = 0;
  KillTimer(1);
  Invalidate(true); 
}
void CMiVentana::OnPaint()
{
  CPaintDC dc(this); //objeto del dispositivo gráfico
  static int cont2 = 0;
  CRect r;
  GetClientRect(r);
  CString cs;
  cs.Format("ContOnPaint=%.3d",cont2++);
  dc.TextOut(500,r.top,cs);
  //Dibujo Ejes
  CPen p1(PS_SOLID,1,RGB(255,0,0));
  dc.SelectObject(&p1);
  dc.MoveTo(r.right/2,0); dc.LineTo(r.right/2,r.bottom);
  dc.MoveTo(0,r.bottom/2); dc.LineTo(r.right,r.bottom/2);

  // Dibujo timer
  CRect r2;
  GetClientRect(r2);
  cs.Format("ContTimer=%.3d",m_cont);
  dc.TextOut(10,r.top+40,cs);
  // Dibujo raton
  CRect r1;
  //obtener las dimen. del area cliente
  GetClientRect(r1);
  cs.Format("x:%.3d y:%.3d",m_point.x,m_point.y);
  dc.TextOut(10,r1.bottom-20,cs);//escribir

  // Rectangulo
  dc.Rectangle(m_x1, m_y1, m_x2, m_y2);
  }