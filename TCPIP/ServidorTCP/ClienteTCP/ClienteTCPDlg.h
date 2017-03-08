
// ClienteTCPDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"


// Cuadro de diálogo de CClienteTCPDlg
class CClienteTCPDlg : public CDialogEx
{
// Construcción
public:
	CClienteTCPDlg(CWnd* pParent = NULL);	// Constructor estándar

// Datos del cuadro de diálogo
	enum { IDD = IDD_CLIENTETCP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
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
