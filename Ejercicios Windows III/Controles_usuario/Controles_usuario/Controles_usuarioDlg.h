
// Controles_usuarioDlg.h: archivo de encabezado
//

#pragma once
#include "Circulo.h"
#include "Lleno.h"
// Cuadro de diálogo de CControles_usuarioDlg
class CControles_usuarioDlg : public CDialogEx
{
// Construcción
public:
	CControles_usuarioDlg(CWnd* pParent = NULL);	// Constructor estándar
  CCirculo m_circulo;
  CLleno m_lleno;
// Datos del cuadro de diálogo
	enum { IDD = IDD_CONTROLES_USUARIO_DIALOG };

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
  int m_slider;
  afx_msg void OnNMCustomdrawsllleno(NMHDR *pNMHDR, LRESULT *pResult);
//  CString m_datos;
  CString m_datos;
  int m_fondo;
  afx_msg void OnBnClickedrdfondo1();
  afx_msg void OnBnClickedrdfondo2();
  void CambiaFondo();
};
