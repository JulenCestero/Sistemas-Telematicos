
// Demo_ClaseDlg.h: archivo de encabezado
//

#pragma once
#include "Panel.h"

// Cuadro de diálogo de CDemo_ClaseDlg
class CDemo_ClaseDlg : public CDialogEx
{
// Construcción
public:
	CDemo_ClaseDlg(CWnd* pParent = NULL);	// Constructor estándar
  CPanel m_pan1;

// Datos del cuadro de diálogo
	enum { IDD = IDD_DEMO_CLASE_DIALOG };

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
};
