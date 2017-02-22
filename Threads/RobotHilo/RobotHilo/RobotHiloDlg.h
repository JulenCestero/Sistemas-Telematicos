
// RobotHiloDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"


// Cuadro de diálogo de CRobotHiloDlg
class CRobotHiloDlg : public CDialogEx
{
// Construcción
public:
	CRobotHiloDlg(CWnd* pParent = NULL);	// Constructor estándar

// Datos del cuadro de diálogo
	enum { IDD = IDD_ROBOTHILO_DIALOG };

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
  int m_task;
  CListBox m_list;
  afx_msg void OnBnClickedbnstart();
  afx_msg void OnBnClickedbnclear();
  afx_msg LRESULT Funcion(WPARAM wParam, LPARAM lParam);
};
