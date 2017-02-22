
// EntregableSensoresDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"
#include <vector>

// Cuadro de di�logo de CEntregableSensoresDlg
class CEntregableSensoresDlg : public CDialogEx
{
// Construcci�n
public:
	CEntregableSensoresDlg(CWnd* pParent = NULL);	// Constructor est�ndar

// Datos del cuadro de di�logo
	enum { IDD = IDD_ENTREGABLESENSORES_DIALOG };

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
  CListBox m_list;
  afx_msg LRESULT funcion(WPARAM wParam, LPARAM lParam);
  std::vector<CWinThread*> m_threads;
  int m_enviado;
	bool m_active;
  size_t m_recibido;
	int m_id;
	afx_msg void OnSelchangeCbnodes();
	CComboBox m_comboNodes2;
	CComboBox m_comboNodes;
	afx_msg void OnBnClickedbnsend();
};
