
// ServidorRealDlg.h : header file
//

#pragma once
#include "SockServidor.h"

// CServidorRealDlg dialog
class CServidorRealDlg : public CDialogEx
{
// Construction
public:
	CServidorRealDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SERVIDORREAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_msg;
	int m_slider1;
	int m_slider2;
	CSockServidor *pSock;
	afx_msg void OnNMReleasedcapturesldeposito2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcapturesldeposito1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedbnsalir();
};
