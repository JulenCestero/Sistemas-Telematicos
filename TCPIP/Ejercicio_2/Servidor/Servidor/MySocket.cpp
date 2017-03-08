// MySocket.cpp : implementation file
//

#include "stdafx.h"
#include "Servidor.h"
#include "MySocket.h"
#include "ServidorDlg.h";

// CMySocket

CMySocket::CMySocket(CServidorDlg *p)
{
	pDlg = p;
}

CMySocket::~CMySocket()
{
}


// CMySocket member functions


void CMySocket::OnAccept(int nErrorCode)
{
	char buf[50], buf2[50];
	static int num=0;
	CSocket cliente;
	Accept(cliente);
	while(TRUE){
		int len = cliente.Receive(buf,50);
		buf[len]= buf2[len] = 0;
		if (len==0 || len==-1) break;
		pDlg->m_msg = buf;
		sprintf(buf2,"ACK: %d",num++);
		cliente.Send(buf2,strlen(buf2));
		pDlg->m_dep2.m_nivel = atoi(buf);
		pDlg->m_textoDeposito2 = atoi(buf);
		pDlg->m_dep2.Invalidate(true);
	}
	pDlg->UpdateData(0);
	cliente.Close();
}


//void CMySocket::OnReceive(int nErrorCode)
//{
//	char buf[50];
//	CString addr,cs;
//	UINT port;
//	//Recibe Mensaje
//	int len=ReceiveFrom(buf,50,addr,port);
//	buf[len]=0;
//	cs.Format("Add:'%s' Port:%d MSG:%s",addr,port,buf);
//	pDlg->m_msg = cs;
//	//enviar ACK
//	SendTo("ACK UDP",7,port,addr);
//}
