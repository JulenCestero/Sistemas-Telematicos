
// AmortiguadorIIDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de di�logo de CAmortiguadorIIDlg
class CAmortiguadorIIDlg : public CDialogEx
{
// Construcci�n
public:
	CAmortiguadorIIDlg(CWnd* pParent = NULL);	// Constructor est�ndar

// Datos del cuadro de di�logo
	enum { IDD = IDD_AMORTIGUADORII_DIALOG };

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
