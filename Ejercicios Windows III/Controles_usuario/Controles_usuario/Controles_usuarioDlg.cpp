
// Controles_usuarioDlg.cpp: archivo de implementación
//

#include "stdafx.h"
#include "Controles_usuario.h"
#include "Controles_usuarioDlg.h"
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


// Cuadro de diálogo de CControles_usuarioDlg



CControles_usuarioDlg::CControles_usuarioDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CControles_usuarioDlg::IDD, pParent)
  , m_slider(0)
  , m_datos(_T(""))
  , m_fondo(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CControles_usuarioDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Slider(pDX, slLleno, m_slider);
  //  DDX_Text(pDX, txbxLleno, m_datos);
  DDX_Text(pDX, txbxLleno, m_datos);
  DDX_Radio(pDX, rdFondo1, m_fondo);
}

BEGIN_MESSAGE_MAP(CControles_usuarioDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_NOTIFY(NM_CUSTOMDRAW, slLleno, &CControles_usuarioDlg::OnNMCustomdrawsllleno)
  ON_BN_CLICKED(rdFondo1, &CControles_usuarioDlg::OnBnClickedrdfondo1)
  ON_BN_CLICKED(rdFondo2, &CControles_usuarioDlg::OnBnClickedrdfondo2)
END_MESSAGE_MAP()


// Controladores de mensaje de CControles_usuarioDlg

BOOL CControles_usuarioDlg::OnInitDialog()
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
  m_circulo.SubclassDlgItem(imCirculo, this);
  m_lleno.SubclassDlgItem(imTanque, this);
	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CControles_usuarioDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CControles_usuarioDlg::OnPaint()
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
HCURSOR CControles_usuarioDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CControles_usuarioDlg::OnNMCustomdrawsllleno(NMHDR *pNMHDR, LRESULT *pResult)
{
  LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
  // TODO: Agregue aquí su código de controlador de notificación de control
  *pResult = 0;
  UpdateData(1);
  m_lleno.m_height = m_slider;
  m_lleno.Invalidate(true);
  m_datos.Format("%d", m_lleno.m_altura);
  UpdateData(0);
  Invalidate(false);
}

void CControles_usuarioDlg::CambiaFondo()
{
  switch (m_fondo){
    case 0:
      m_circulo.option = 0;
      break;
    case 1:
      m_circulo.option = 1;
      break;
    default:
      break;
  }
  m_circulo.Invalidate(true);

}
void CControles_usuarioDlg::OnBnClickedrdfondo1()
{
  UpdateData(1);
  CambiaFondo();
}


void CControles_usuarioDlg::OnBnClickedrdfondo2()
{
  UpdateData(1);
  CambiaFondo();
}
