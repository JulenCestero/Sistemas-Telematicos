#pragma once
class CServidorUDPDlg;
// Destino del comando de CSockServidor

class CSockServidor : public CSocket
{
public:
	CSockServidor(CServidorUDPDlg *p);
  CServidorUDPDlg *pDlg;
	virtual ~CSockServidor();

protected:
  virtual void OnReceive(int nErrorCode);
};


