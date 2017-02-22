
// SenoIIDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"


// Cuadro de di�logo de CSenoIIDlg
class CSenoIIDlg : public CDialogEx
{
// Construcci�n
public:
	CSenoIIDlg(CWnd* pParent = NULL);	// Constructor est�ndar

// Datos del cuadro de di�logo
	enum { IDD = IDD_SENOII_DIALOG };

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
//  afx_msg void OnBnClickedCancel();
  afx_msg void OnBnClickedbndraw();
  CStatic m_grafica;
  int m_numCiclos;
//  CEdit m_amplitud;
  int m_amplitud;
  int m_numPuntos;
  afx_msg void OnBnClickedbnexit();
};
