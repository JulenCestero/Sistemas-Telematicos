
// EntregableSensoresDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"
#include <vector>

// Cuadro de diálogo de CEntregableSensoresDlg
class CEntregableSensoresDlg : public CDialogEx
{
// Construcción
public:
	CEntregableSensoresDlg(CWnd* pParent = NULL);	// Constructor estándar

// Datos del cuadro de diálogo
	enum { IDD = IDD_ENTREGABLESENSORES_DIALOG };

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
  afx_msg void OnBnClickedbnnodo1();
  afx_msg void OnBnClickedbnnodo2();
  afx_msg void OnBnClickedbnnodo3();
  afx_msg LRESULT funcion(WPARAM wParam, LPARAM lParam);
  std::vector<CWinThread*> m_threads;
  int m_enviado;
  size_t m_recibido;
};
