
// ServidorDlg.cpp: archivo de implementaci�n
//

#include "stdafx.h"
#include "Servidor.h"
#include "ServidorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de di�logo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de di�logo
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementaci�n
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


// Cuadro de di�logo de CServidorDlg



CServidorDlg::CServidorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CServidorDlg::IDD, pParent)
	, m_textoDeposito2(0)
	, m_textoDeposito1(0)
	, m_ip(_T(""))
	, m_port(0)
	, m_msg(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServidorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, txbxDeposito1, m_textoDeposito1);
	DDX_Text(pDX, txbxDeposito2, m_textoDeposito2);
	DDX_Text(pDX, txbxDeposito1, m_textoDeposito1);
	DDX_Text(pDX, IDC_EDIT3, m_ip);
	DDX_Text(pDX, IDC_EDIT4, m_port);
	DDX_Text(pDX, IDC_EDIT5, m_msg);
}

BEGIN_MESSAGE_MAP(CServidorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CServidorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CServidorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CServidorDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Controladores de mensaje de CServidorDlg

BOOL CServidorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de men� "Acerca de..." al men� del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
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

	// Establecer el icono para este cuadro de di�logo. El marco de trabajo realiza esta operaci�n
	//  autom�ticamente cuando la ventana principal de la aplicaci�n no es un cuadro de di�logo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono peque�o

	// TODO: agregar aqu� inicializaci�n adicional
	misoc = new CMySocket(this);
	misoc->Create(502,SOCK_STREAM);
	misoc->Listen();
	m_msg = "Esperando conexi�n en 502";
	m_dep1.SubclassDlgItem(imDeposito1, this);
  m_dep2.SubclassDlgItem(imDeposito2, this);
	m_dep1.m_nivel = 10;
	m_dep2.m_nivel = 45;
	m_textoDeposito1 = m_dep1.m_nivel;
	m_textoDeposito2 = m_dep2.m_nivel;
	m_ip = "127.0.0.1";
	m_port = 503;
	UpdateData(0);
	m_dep1.Invalidate(true);
	m_dep2.Invalidate(true);
	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CServidorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si agrega un bot�n Minimizar al cuadro de di�logo, necesitar� el siguiente c�digo
//  para dibujar el icono. Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operaci�n la realiza autom�ticamente el marco de trabajo.

void CServidorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rect�ngulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta funci�n para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CServidorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CServidorDlg::OnTimer(UINT_PTR nIDEvent)
{
	static int num=0;
	char buf[50];
	UpdateData(true);
	CSocket cliente;
	if ( !cliente.Create(0,SOCK_DGRAM)){
		MessageBox("Error al crea cliente..");
		return;
	}
	CString cs;
	cs.Format("UDP %d", num);
	int sl=cliente.SendTo(cs,cs.GetLength(),m_port,m_ip);
	int rl=cliente.Receive(buf,30);
	if (rl>0){
		buf[rl]=0;
		m_msg.Format("Num:%d MSG:%s",num++,buf);
		m_dep1.m_nivel = atoi(buf);
		m_textoDeposito1 = atoi(buf);
		m_dep1.Invalidate(true);
	}
	cliente.Close();
	UpdateData(false);
}


void CServidorDlg::OnBnClickedButton1()
{
	SetTimer(1, 5000, NULL);
}


void CServidorDlg::OnBnClickedButton2()
{
	KillTimer(1);
}


void CServidorDlg::OnBnClickedButton3()
{
	CDialog::OnOK();
}
