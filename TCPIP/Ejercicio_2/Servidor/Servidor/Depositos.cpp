// Depositos.cpp : implementation file
//

#include "stdafx.h"
#include "Servidor.h"
#include "Depositos.h"


// CDepositos

IMPLEMENT_DYNAMIC(CDepositos, CWnd)

CDepositos::CDepositos()
{
	m_nivel = 0;
}

CDepositos::~CDepositos()
{
}


BEGIN_MESSAGE_MAP(CDepositos, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CDepositos message handlers




void CDepositos::OnPaint()
{
	CPaintDC dc(this); // device context for painting
  CRect r;
  GetClientRect(r);
  dc.FillSolidRect(r, RGB(255,255,255));
  CPen p1(PS_SOLID, 1, RGB(0,0,0));
  dc.SelectObject(&p1);
  dc.Rectangle(r);
  int tmp = m_nivel * r.bottom / 100;
  r.top = r.bottom - tmp;
  dc.FillSolidRect(r, RGB(0,0,255));
}
