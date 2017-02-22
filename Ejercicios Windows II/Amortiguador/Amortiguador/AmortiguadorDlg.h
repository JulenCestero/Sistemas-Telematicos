
// AmortiguadorDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"


// Cuadro de di�logo de CAmortiguadorDlg
class CAmortiguadorDlg : public CDialogEx
{
// Construcci�n
public:
	CAmortiguadorDlg(CWnd* pParent = NULL);	// Constructor est�ndar

// Datos del cuadro de di�logo
	enum { IDD = IDD_AMORTIGUADOR_DIALOG };

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
  CStatic m_grafica;
  int m_amp;
  int m_frec;
  bool m_start;
  int m_timer;
  int m_x1;
  int m_x2;
  afx_msg void OnBnClickedbnaction();
  afx_msg void OnTimer(UINT_PTR nIDEvent);
  afx_msg void OnBnClickedbnexit();
};
