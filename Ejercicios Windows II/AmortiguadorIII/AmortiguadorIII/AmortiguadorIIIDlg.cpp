
// AmortiguadorIIIDlg.cpp: archivo de implementación
//

#include "stdafx.h"
#include "AmortiguadorIII.h"
#include "AmortiguadorIIIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
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


// Cuadro de diálogo de CAmortiguadorIIIDlg



CAmortiguadorIIIDlg::CAmortiguadorIIIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAmortiguadorIIIDlg::IDD, pParent)
  , m_amp(0)
  , m_frec(0)
  , m_info(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAmortiguadorIIIDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Text(pDX, txbxAmp, m_amp);
  DDX_Text(pDX, IDC_EDIT2, m_frec);
  DDX_Control(pDX, imArea, m_grafica);
  DDX_Text(pDX, txbxInfo, m_info);
}

BEGIN_MESSAGE_MAP(CAmortiguadorIIIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(bnStart, &CAmortiguadorIIIDlg::OnBnClickedbnstart)
  ON_BN_CLICKED(bnExit, &CAmortiguadorIIIDlg::OnBnClickedbnexit)
  ON_WM_TIMER()
END_MESSAGE_MAP()


// Controladores de mensaje de CAmortiguadorIIIDlg

BOOL CAmortiguadorIIIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

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

	// Establecer el icono para este cuadro de diálogo. El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional
  m_start = false;
  m_timer = 0;
  CRect r;
  m_grafica.GetClientRect(r);
  m_x1 = r.right / 2 - 20;
  m_x2 = r.right / 2 + 20;
  m_info.Format("Width: %d", m_x1); 
	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CAmortiguadorIIIDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono. Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CAmortiguadorIIIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
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
    CRect r;
    m_grafica.GetClientRect(r);
    CDC *pdc = m_grafica.GetDC();
    CPen p1(PS_SOLID,1,RGB(255,0,0));
    pdc->SelectObject(&p1);
    pdc->MoveTo(0,r.bottom / 2);
    pdc->LineTo(r.right,r.bottom / 2);
    pdc->MoveTo(r.right / 2, 0);
    pdc->LineTo(r.right / 2, r.bottom);
    CDC *pdc2 = m_grafica.GetDC();
    pdc2->Rectangle(m_x1, r.bottom / 2 - 60, m_x2, r.bottom / 2 - 20);
    pdc2->MoveTo(0, r.bottom / 2 - 40);
    pdc2->LineTo(m_x1, r.bottom / 2 - 40);
    UpdateData(false);
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CAmortiguadorIIIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAmortiguadorIIIDlg::OnBnClickedbnstart()
{
  UpdateData(1);
  if(m_start == false){
    m_start = true;
    SetTimer(1, 50, NULL);
  }
  else{
    KillTimer(1);
    m_timer = 0;
    m_start = false;
    CRect r;
    m_grafica.GetClientRect(r);
    m_x1 = r.right / 2 - 20;
    m_x2 = r.right / 2 + 20;
    Invalidate(true);
  }
}


void CAmortiguadorIIIDlg::OnBnClickedbnexit()
{
  CDialog::OnOK();
}


void CAmortiguadorIIIDlg::OnTimer(UINT_PTR nIDEvent)
{
  CRect r;
  m_grafica.GetClientRect(r);
  m_timer++;
  int dx;
  dx = m_amp * cos(2 * 3.1416 * m_timer / m_frec); 
  m_x1 = dx + r.right / 2 - 20;
  m_x2 = dx + r.right / 2 + 20;
  m_info.Format("Width: %d", m_x1); 
  Invalidate(true);
}
