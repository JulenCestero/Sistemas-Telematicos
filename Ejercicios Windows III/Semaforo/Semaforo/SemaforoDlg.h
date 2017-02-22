
// SemaforoDlg.h: archivo de encabezado
//

#pragma once
#include "Luz.h"

// Cuadro de diálogo de CSemaforoDlg
class CSemaforoDlg : public CDialogEx
{
// Construcción
public:
	CSemaforoDlg(CWnd* pParent = NULL);	// Constructor estándar

// Datos del cuadro de diálogo
	enum { IDD = IDD_SEMAFORO_DIALOG };

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
  CLuz rojo;
  CLuz verde;
  CLuz ambar;
  bool m_start;
  int m_timer;
public:
  afx_msg void OnBnClickedbnstart();
  afx_msg void OnTimer(UINT_PTR nIDEvent);
};
