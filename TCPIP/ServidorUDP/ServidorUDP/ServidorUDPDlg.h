
// ServidorUDPDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"
#include "SockServidor.h"

// Cuadro de di�logo de CServidorUDPDlg
class CServidorUDPDlg : public CDialogEx
{
// Construcci�n
public:
	CServidorUDPDlg(CWnd* pParent = NULL);	// Constructor est�ndar

// Datos del cuadro de di�logo
	enum { IDD = IDD_SERVIDORUDP_DIALOG };

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
  CListBox m_lista;
  afx_msg void OnBnClickedbnstart();
  CSockServidor *pSock;
};
