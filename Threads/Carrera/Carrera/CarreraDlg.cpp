
// CarreraDlg.cpp: archivo de implementación
//

#include "stdafx.h"
#include "Carrera.h"
#include "CarreraDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define WM_FIN_HILO WM_USER+100

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


// Cuadro de diálogo de CCarreraDlg



CCarreraDlg::CCarreraDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCarreraDlg::IDD, pParent)
  , m_vueltas(0)
  , m_longitud(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCarreraDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Text(pDX, txbxVueltas, m_vueltas);
  DDX_Text(pDX, txbxLongitud, m_longitud);
  DDX_Control(pDX, prgRenault, m_renault);
  DDX_Control(pDX, prgFerrari, m_ferrari);
}

BEGIN_MESSAGE_MAP(CCarreraDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(bnSalir, &CCarreraDlg::OnBnClickedbnsalir)
  ON_BN_CLICKED(bnPlay, &CCarreraDlg::OnBnClickedbnplay)
  ON_BN_CLICKED(bnPausa, &CCarreraDlg::OnBnClickedbnpausa)
  ON_BN_CLICKED(bnStop, &CCarreraDlg::OnBnClickedbnstop)
  ON_MESSAGE (WM_FIN_HILO, OnFinHilo)
END_MESSAGE_MAP()


// Controladores de mensaje de CCarreraDlg

BOOL CCarreraDlg::OnInitDialog()
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

void CCarreraDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCarreraDlg::OnPaint()
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
HCURSOR CCarreraDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CCarreraDlg::OnFinHilo(WPARAM wParam, LPARAM lParam) //Mensajes
{
  if (wParam == 1)
  MessageBox("Ferrari llegó a la meta...");
  else if (wParam==2)
  MessageBox("Renault llegó a la meta...");
  return 0;
}

void CCarreraDlg::OnBnClickedbnsalir()
{
  CDialog::OnOK();
}

UINT RenaultThread(LPVOID pParam){
  srand(time(NULL)); //Cambiar la semilla de inicio
  int t=rand()%25;
  CCarreraDlg *pDlg = (CCarreraDlg*)pParam;
  int len = pDlg->m_longitud * pDlg->m_vueltas;
  for (int i=0;i<len;i++){
  pDlg->m_renault.SetPos(i*100.0/len);
  Sleep(t);
  if (pDlg->m_fin) break;
  }
  if (!pDlg->m_fin) pDlg->PostMessage(WM_FIN_HILO,2); //Mensaje de Renault(2)
  return 0;
}

UINT FerrariThread(LPVOID pParam){
   //Cambiar la semilla de inicio
  int t=rand()%25;
  CCarreraDlg *pDlg = (CCarreraDlg*)pParam;
  int len = pDlg->m_longitud * pDlg->m_vueltas;
  for (int i=0;i<len;i++){
  pDlg->m_ferrari.SetPos(i*100.0/len);
  Sleep(t);
  if (pDlg->m_fin) break;
  }
  if (!pDlg->m_fin) pDlg->PostMessage(WM_FIN_HILO,1); //Mensaje de Ferrari(1)
  return 0;
}

void CCarreraDlg::OnBnClickedbnplay()
{
  if(m_susp == true){
    for(size_t ii = 0; ii < m_threads.size(); ii++){
      m_threads[ii]->ResumeThread();
    }
    m_susp = false;
  }
  else{
    UpdateData();
    m_fin = false;
    m_threads.push_back(AfxBeginThread(RenaultThread, this));
    m_threads.push_back(AfxBeginThread(FerrariThread, this));
  }
}


void CCarreraDlg::OnBnClickedbnpausa()
{
  m_susp = true;
  for(size_t ii = 0; ii < m_threads.size(); ii++){
    m_threads.at(ii)->SuspendThread();
  }
}


void CCarreraDlg::OnBnClickedbnstop()
{
  m_fin = true;
}
