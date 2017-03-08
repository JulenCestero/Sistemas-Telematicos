#pragma once

class CServidorTCPDlg;
// Destino del comando de MySocket

class MySocket : public CSocket
{
public:
	MySocket(CServidorTCPDlg *p);
  CServidorTCPDlg *pDlg;
	virtual ~MySocket();
  virtual void OnAccept(int nErrorCode);
};


