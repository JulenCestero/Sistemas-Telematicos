#pragma once

// CSockServidor command target
class CServidorRealDlg;
class CSockServidor : public CSocket
{
public:
	CSockServidor(CServidorRealDlg *p);
	CServidorRealDlg *pDlg;
	virtual ~CSockServidor();
	virtual void OnReceive(int nErrorCode);
};


