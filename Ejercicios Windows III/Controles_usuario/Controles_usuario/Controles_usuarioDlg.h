
// Controles_usuarioDlg.h: archivo de encabezado
//

#pragma once
#include "Circulo.h"
#include "Lleno.h"
// Cuadro de di�logo de CControles_usuarioDlg
class CControles_usuarioDlg : public CDialogEx
{
// Construcci�n
public:
	CControles_usuarioDlg(CWnd* pParent = NULL);	// Constructor est�ndar
  CCirculo m_circulo;
  CLleno m_lleno;
// Datos del cuadro de di�logo
	enum { IDD = IDD_CONTROLES_USUARIO_DIALOG };

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
  int m_slider;
  afx_msg void OnNMCustomdrawsllleno(NMHDR *pNMHDR, LRESULT *pResult);
//  CString m_datos;
  CString m_datos;
  int m_fondo;
  afx_msg void OnBnClickedrdfondo1();
  afx_msg void OnBnClickedrdfondo2();
  void CambiaFondo();
};
