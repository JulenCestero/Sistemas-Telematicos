
// ServidorTCPDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"
#include "MySocket.h"

// Cuadro de di�logo de CServidorTCPDlg
class CServidorTCPDlg : public CDialogEx
{
// Construcci�n
public:
	CServidorTCPDlg(CWnd* pParent = NULL);	// Constructor est�ndar
  MySocket *misoc;
// Datos del cuadro de di�logo
	enum { IDD = IDD_SERVIDORTCP_DIALOG };

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
  CListBox m_list;
 
};
