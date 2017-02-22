
// SemaforoDlg.cpp: archivo de implementaci�n
//

#include "stdafx.h"
#include "Semaforo.h"
#include "SemaforoDlg.h"
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


// Cuadro de di�logo de CSemaforoDlg



CSemaforoDlg::CSemaforoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSemaforoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSemaforoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSemaforoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(bnStart, &CSemaforoDlg::OnBnClickedbnstart)
  ON_WM_TIMER()
END_MESSAGE_MAP()


// Controladores de mensaje de CSemaforoDlg

BOOL CSemaforoDlg::OnInitDialog()
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
  verde.SubclassDlgItem(imVerde, this);
  ambar.SubclassDlgItem(imAmbar, this);
  rojo.SubclassDlgItem(imRojo, this);
  m_start = false;
  m_timer = 0;
	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CSemaforoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSemaforoDlg::OnPaint()
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
HCURSOR CSemaforoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSemaforoDlg::OnBnClickedbnstart()
{
  switch(m_start){
  case 0:
    m_start = 1;
    SetTimer(1, 1000,NULL);
    break;
  case 1:
    m_timer = 0;
    KillTimer(1);
    m_start = 0;
    break;
  }
}


void CSemaforoDlg::OnTimer(UINT_PTR nIDEvent)
{
  switch(m_timer){
  case 0:
    rojo.m_color = 0;
    verde.m_color = 0;
    ambar.m_color = 0;
    m_timer++;
    break;
  case 1:
    rojo.m_color = 0;
    verde.m_color = 3;
    ambar.m_color = 0;
    m_timer++;
    break;
  case 2:
    rojo.m_color = 0;
    ambar.m_color = 2;
    verde.m_color = 0;
    m_timer++;
    break;
  case 3:
    rojo.m_color = 1;
    ambar.m_color = 0;
    verde.m_color = 0;
    m_timer = 1;
    break;
  }
  rojo.Invalidate(true);
  verde.Invalidate(true);
  ambar.Invalidate(true);
  CDialogEx::OnTimer(nIDEvent);
}
