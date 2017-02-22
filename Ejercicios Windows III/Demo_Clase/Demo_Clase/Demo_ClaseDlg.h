
// Demo_ClaseDlg.h: archivo de encabezado
//

#pragma once
#include "Panel.h"

// Cuadro de di�logo de CDemo_ClaseDlg
class CDemo_ClaseDlg : public CDialogEx
{
// Construcci�n
public:
	CDemo_ClaseDlg(CWnd* pParent = NULL);	// Constructor est�ndar
  CPanel m_pan1;

// Datos del cuadro de di�logo
	enum { IDD = IDD_DEMO_CLASE_DIALOG };

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
};
