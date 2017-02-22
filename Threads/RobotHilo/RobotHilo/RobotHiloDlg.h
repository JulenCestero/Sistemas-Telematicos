
// RobotHiloDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"


// Cuadro de di�logo de CRobotHiloDlg
class CRobotHiloDlg : public CDialogEx
{
// Construcci�n
public:
	CRobotHiloDlg(CWnd* pParent = NULL);	// Constructor est�ndar

// Datos del cuadro de di�logo
	enum { IDD = IDD_ROBOTHILO_DIALOG };

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
  int m_task;
  CListBox m_list;
  afx_msg void OnBnClickedbnstart();
  afx_msg void OnBnClickedbnclear();
  afx_msg LRESULT Funcion(WPARAM wParam, LPARAM lParam);
};
