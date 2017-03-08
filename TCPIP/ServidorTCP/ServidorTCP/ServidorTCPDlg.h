
// ServidorTCPDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"
#include "MySocket.h"

// Cuadro de diálogo de CServidorTCPDlg
class CServidorTCPDlg : public CDialogEx
{
// Construcción
public:
	CServidorTCPDlg(CWnd* pParent = NULL);	// Constructor estándar
  MySocket *misoc;
// Datos del cuadro de diálogo
	enum { IDD = IDD_SERVIDORTCP_DIALOG };

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
  CListBox m_list;
 
};
