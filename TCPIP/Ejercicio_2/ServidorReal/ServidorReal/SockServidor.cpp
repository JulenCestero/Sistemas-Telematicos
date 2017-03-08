// SockServidor.cpp : implementation file
//

#include "stdafx.h"
#include "ServidorReal.h"
#include "SockServidor.h"
#include "ServidorRealDlg.h"

// CSockServidor

CSockServidor::CSockServidor(CServidorRealDlg *p)
{
	pDlg = p;
}

CSockServidor::~CSockServidor()
{
}


// CSockServidor member functions


void CSockServidor::OnReceive(int nErrorCode)
{
	char buf[50];
	CString addr,cs;
	UINT port;
	//Recibe Mensaje
	int len=ReceiveFrom(buf,50,addr,port);
	buf[len]=0;
	cs.Format("Add:'%s' Port:%d MSG:%s",addr,port,buf);
	pDlg->m_msg = cs;
	pDlg->UpdateData(0);
	//enviar 
	CString cs2;
	cs2.Format("%d", pDlg->m_slider1);
	SendTo(cs2,cs2.GetLength(),port,addr);
}
