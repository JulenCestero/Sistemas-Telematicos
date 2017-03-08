
// ServidorUDPDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"
#include "SockServidor.h"

// Cuadro de diálogo de CServidorUDPDlg
class CServidorUDPDlg : public CDialogEx
{
// Construcción
public:
	CServidorUDPDlg(CWnd* pParent = NULL);	// Constructor estándar

// Datos del cuadro de diálogo
	enum { IDD = IDD_SERVIDORUDP_DIALOG };

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
  CListBox m_lista;
  afx_msg void OnBnClickedbnstart();
  CSockServidor *pSock;
};
