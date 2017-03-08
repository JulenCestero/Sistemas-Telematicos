
// ClienteUDPDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de di�logo de CClienteUDPDlg
class CClienteUDPDlg : public CDialogEx
{
// Construcci�n
public:
	CClienteUDPDlg(CWnd* pParent = NULL);	// Constructor est�ndar

// Datos del cuadro de di�logo
	enum { IDD = IDD_CLIENTEUDP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementaci�n
protected:
	HICON m_hIcon;

	// Funciones de asignaci�n de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
  CString m_ip;
  int m_port;
  CString m_tx;
  CString m_rx;
  afx_msg void OnBnClickedbnenviar();
};
