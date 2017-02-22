
// SenoIIDlg.cpp: archivo de implementación
//

#include "stdafx.h"
#include "SenoII.h"
#include "SenoIIDlg.h"
#include "afxdialogex.h"
#include <math.h>

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


// Cuadro de diálogo de CSenoIIDlg



CSenoIIDlg::CSenoIIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSenoIIDlg::IDD, pParent)
  , m_numCiclos(0)
  , m_amplitud(0)
  , m_numPuntos(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSenoIIDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Control(pDX, imArea, m_grafica);
  DDX_Text(pDX, txbxCiclos, m_numCiclos);
  //  DDX_Control(pDX, txbxAmplitud, m_amplitud);
  DDX_Text(pDX, txbxAmplitud, m_amplitud);
  DDX_Text(pDX, txbxPuntos, m_numPuntos);
}

BEGIN_MESSAGE_MAP(CSenoIIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//  ON_BN_CLICKED(IDCANCEL, &CSenoIIDlg::OnBnClickedCancel)
ON_BN_CLICKED(bnDraw, &CSenoIIDlg::OnBnClickedbndraw)
ON_BN_CLICKED(bnExit, &CSenoIIDlg::OnBnClickedbnexit)
END_MESSAGE_MAP()


// Controladores de mensaje de CSenoIIDlg

BOOL CSenoIIDlg::OnInitDialog()
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

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CSenoIIDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSenoIIDlg::OnPaint()
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
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CSenoIIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CSenoIIDlg::OnBnClickedCancel()
//{
//  // TODO: Agregue aquí su código de controlador de notificación de control
//  CDialogEx::OnCancel();
//}


void CSenoIIDlg::OnBnClickedbndraw()
{
  CString cs;
  CRect rc; 
  m_grafica.GetClientRect(rc); //obtener el area cliente
  CDC *pDC = m_grafica.GetDC(); //obtener el DC del cliente
  CBrush b1;
  //fondo blanco
  b1.CreateSolidBrush(RGB(255,255,255));
  pDC->FillRect(rc,&b1);
  //eje central color rojo
  CPen p1(PS_SOLID,0,RGB(192,0,0));
  pDC->SelectObject(&p1);
  int h = rc.bottom;
  int w = rc.right;
  int yc = h/2; //el origen del eje y
  pDC->MoveTo(0,yc); pDC->LineTo(rc.right,yc);
  //calculos
  UpdateData(true);
  //cambiar el color a azul
  CPen p2(PS_SOLID,0,RGB(0,0,192));
  pDC->SelectObject(&p2);
  int xt = m_numPuntos * m_numCiclos; //# de puntos a dibujar
  pDC->MoveTo(0,yc); //pto. origen
  for (int i=1;i<=xt;i++) {
  //calculo de fx
  double fx = m_amplitud * sin(2*3.14159*i/m_numPuntos);
  int y = yc - fx * yc /m_amplitud ; //conver. escala
  pDC->LineTo(i*w/xt,y);
}
}


void CSenoIIDlg::OnBnClickedbnexit()
{
  CDialog::OnOK();
}
