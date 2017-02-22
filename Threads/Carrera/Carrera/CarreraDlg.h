
// CarreraDlg.h: archivo de encabezado
//

#pragma once
#include "afxcmn.h"
#include <vector>

// Cuadro de diálogo de CCarreraDlg
class CCarreraDlg : public CDialogEx
{
// Construcción
public:
	CCarreraDlg(CWnd* pParent = NULL);	// Constructor estándar

// Datos del cuadro de diálogo
	enum { IDD = IDD_CARRERA_DIALOG };

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
  afx_msg void OnBnClickedbnsalir();
  afx_msg void OnBnClickedbnplay();
  afx_msg void OnBnClickedbnpausa();
  afx_msg void OnBnClickedbnstop();
  afx_msg LRESULT OnFinHilo(WPARAM wParam, LPARAM lParam); 
  int m_vueltas;
  int m_longitud;
  CProgressCtrl m_renault;
  CProgressCtrl m_ferrari;
  std::vector<CWinThread*> m_threads;
  bool m_fin, m_susp;
};
