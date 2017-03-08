// MySocket.cpp: archivo de implementación
//

#include "stdafx.h"
#include "ServidorTCP.h"
#include "MySocket.h"
#include "ServidorTCPDlg.h"

// MySocket

MySocket::MySocket(CServidorTCPDlg *p){
  pDlg = p;  
}

MySocket::~MySocket()
{
}


// Funciones de miembro de MySocket


void MySocket::OnAccept(int nErrorCode)
{
  char buf[5000];
  static int num=0;
  CSocket cliente;
  Accept(cliente);
  while(TRUE){
    int len = cliente.Receive(buf,5000);
    buf[len]=0;
    if (len==0 || len==-1) break;
    pDlg->m_list.AddString(buf);
    sprintf(buf,"ACK: %d",num++);
    cliente.Send(buf,strlen(buf));
    pDlg->m_list.AddString(buf);
  }
  pDlg->UpdateData(false);
  cliente.Close();
}
