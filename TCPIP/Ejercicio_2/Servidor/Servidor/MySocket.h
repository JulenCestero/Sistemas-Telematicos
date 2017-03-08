#pragma once

// CMySocket command target
class CServidorDlg;

class CMySocket : public CSocket
{
public:
	CMySocket(CServidorDlg *p);
	CServidorDlg *pDlg;
	virtual ~CMySocket();
	virtual void OnAccept(int nErrorCode);
//	virtual void OnReceive(int nErrorCode);
};


