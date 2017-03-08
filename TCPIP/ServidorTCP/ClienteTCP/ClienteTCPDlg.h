
// ClienteTCPDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"


// Cuadro de di�logo de CClienteTCPDlg
class CClienteTCPDlg : public CDialogEx
{
// Construcci�n
public:
	CClienteTCPDlg(CWnd* pParent = NULL);	// Constructor est�ndar

// Datos del cuadro de di�logo
	enum { IDD = IDD_CLIENTETCP_DIALOG };

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
  CListBox m_list;
  CString m_cmd;
  afx_msg void OnBnClickedOk();
};
