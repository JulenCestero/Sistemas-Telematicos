
// AmortiguadorIIIDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"
#include <math.h>

// Cuadro de diálogo de CAmortiguadorIIIDlg
class CAmortiguadorIIIDlg : public CDialogEx
{
// Construcción
public:
	CAmortiguadorIIIDlg(CWnd* pParent = NULL);	// Constructor estándar

// Datos del cuadro de diálogo
	enum { IDD = IDD_AMORTIGUADORIII_DIALOG };

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
  afx_msg void OnBnClickedbnstart();
  afx_msg void OnBnClickedbnexit();
  int m_amp;
  int m_frec;
  bool m_start;
  int m_timer;
  int m_x1;
  int m_x2;
  CStatic m_grafica;
  afx_msg void OnTimer(UINT_PTR nIDEvent);
  CString m_info;
};
