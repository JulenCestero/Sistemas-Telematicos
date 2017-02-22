
// AmortiguadorIIDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CAmortiguadorIIDlg
class CAmortiguadorIIDlg : public CDialogEx
{
// Construcción
public:
	CAmortiguadorIIDlg(CWnd* pParent = NULL);	// Constructor estándar

// Datos del cuadro de diálogo
	enum { IDD = IDD_AMORTIGUADORII_DIALOG };

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
