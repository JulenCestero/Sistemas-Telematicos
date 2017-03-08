// SockServidor.cpp: archivo de implementación
//

#include "stdafx.h"
#include "ServidorUDP.h"
#include "SockServidor.h"
#include "ServidorUDPDlg.h"

// CSockServidor

CSockServidor::CSockServidor(CServidorUDPDlg *p)
{
  pDlg = p;
}

CSockServidor::~CSockServidor()
{
}


// Funciones de miembro de CSockServidor


void CSockServidor::OnReceive(int nErrorCode)
{
  char buf[50];
  CString addr,cs;
  UINT port;
  //Recibe Mensaje
  int len=ReceiveFrom(buf,50,addr,port);
  buf[len]=0;
  cs.Format("Add:'%s' Port:%d MSG:%s",addr,port,buf);
  pDlg->m_lista.AddString(cs);
  //enviar ACK
  SendTo("ACK",3,port,addr);
}
