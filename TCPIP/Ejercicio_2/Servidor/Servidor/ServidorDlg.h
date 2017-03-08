
// ServidorDlg.h: archivo de encabezado
//

#pragma once
#include "Depositos.h"
#include "MySocket.h"

// Cuadro de diálogo de CServidorDlg
class CServidorDlg : public CDialogEx
{
// Construcción
public:
	CServidorDlg(CWnd* pParent = NULL);	// Constructor estándar

// Datos del cuadro de diálogo
	enum { IDD = IDD_SERVIDOR_DIALOG };

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
//	CString m_textoDeposito1;
	int m_textoDeposito2;
	int m_textoDeposito1;
	CString m_ip;
	int m_port;
	CString m_msg;
	CDepositos m_dep1;
	CDepositos m_dep2;
	CMySocket *misoc;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
