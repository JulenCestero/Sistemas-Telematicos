
// ServidorRealDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ServidorReal.h"
#include "ServidorRealDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CServidorRealDlg dialog



CServidorRealDlg::CServidorRealDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CServidorRealDlg::IDD, pParent)
	, m_msg(_T(""))
	, m_slider1(0)
	, m_slider2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServidorRealDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_msg);
	DDX_Slider(pDX, slDeposito1, m_slider1);
	DDV_MinMaxInt(pDX, m_slider1, 0, 100);
	DDX_Slider(pDX, slDeposito2, m_slider2);
	DDV_MinMaxInt(pDX, m_slider2, 0, 100);
}

BEGIN_MESSAGE_MAP(CServidorRealDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_RELEASEDCAPTURE, slDeposito2, &CServidorRealDlg::OnNMReleasedcapturesldeposito2)
	ON_NOTIFY(NM_RELEASEDCAPTURE, slDeposito1, &CServidorRealDlg::OnNMReleasedcapturesldeposito1)
	ON_BN_CLICKED(bnSalir, &CServidorRealDlg::OnBnClickedbnsalir)
END_MESSAGE_MAP()


// CServidorRealDlg message handlers

BOOL CServidorRealDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_slider1 = 10;
	m_slider2 = 45;
	pSock = new CSockServidor(this);
	if(!pSock->Create(503,SOCK_DGRAM)){
		MessageBox("Error al crear server...");
		return TRUE;
	}
	UpdateData(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServidorRealDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CServidorRealDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CServidorRealDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CServidorRealDlg::OnNMReleasedcapturesldeposito2(NMHDR *pNMHDR, LRESULT *pResult)
{
	char buf[50];
	UpdateData(1);
	CSocket misoc;
	if ( !misoc.Create() ){
		MessageBox("Error"); return;
	}
	if ( !misoc.Connect( "127.0.0.1",502) ){
		MessageBox("No conecta.."); return;
	}
	CString cs;
	cs.Format("%d", m_slider2);
	misoc.Send(cs, cs.GetLength());
	int len = misoc.Receive(buf,50);
	buf[len]=0;
	m_msg = buf;
	misoc.Close();
	UpdateData(0);
}


void CServidorRealDlg::OnNMReleasedcapturesldeposito1(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(1);
}


void CServidorRealDlg::OnBnClickedbnsalir()
{
	CDialog::OnOK();
}
