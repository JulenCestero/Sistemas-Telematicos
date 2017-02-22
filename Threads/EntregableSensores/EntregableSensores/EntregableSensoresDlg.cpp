
// EntregableSensoresDlg.cpp: archivo de implementación
//

#include "stdafx.h"
#include "EntregableSensores.h"
#include "EntregableSensoresDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define WM_MSG_HILO WM_USER+100

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


// Cuadro de diálogo de CEntregableSensoresDlg



CEntregableSensoresDlg::CEntregableSensoresDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEntregableSensoresDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEntregableSensoresDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, cbNodes2, m_comboNodes2);
	DDX_Control(pDX, cbNodes, m_comboNodes);
}

BEGIN_MESSAGE_MAP(CEntregableSensoresDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_MESSAGE( WM_MSG_HILO, funcion)
	ON_CBN_SELCHANGE(cbNodes, &CEntregableSensoresDlg::OnSelchangeCbnodes)
	ON_BN_CLICKED(bnSend, &CEntregableSensoresDlg::OnBnClickedbnsend)
END_MESSAGE_MAP()
UINT NodoGeneral(LPVOID p);

// Controladores de mensaje de CEntregableSensoresDlg

BOOL CEntregableSensoresDlg::OnInitDialog()
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
  m_enviado = false;
	m_active = true;
	m_id = 1;
	m_comboNodes.SetCurSel(0);
	CString selection;
	m_comboNodes.GetLBText(0, selection);
	char selection2[10];
	strcpy(selection2, (LPCTSTR)selection );
	for(int ii = 0; ii < selection2[0]-48; ii++){
		CString cs;
		cs.Format("%d", ii + 1);
		m_comboNodes2.AddString(cs);
	}
	m_comboNodes2.SetCurSel(0);
  m_recibido = 0;
	for(int ii = 0; ii < selection2[0]-48; ii++){
		m_threads.push_back(AfxBeginThread(NodoGeneral, this));
	}
	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CEntregableSensoresDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEntregableSensoresDlg::OnPaint()
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
HCURSOR CEntregableSensoresDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

UINT NodoGeneral(LPVOID p)
{
  CEntregableSensoresDlg *pDlg = (CEntregableSensoresDlg*)p;
	int internalID = pDlg->m_id;
	pDlg->m_id++;
  while(pDlg->m_active){
    if(pDlg->m_enviado != 0){
      CString cs1, cs2;
			cs1.Format("Nodo %d", internalID);
      cs2.Format(cs1 + " Recibido de %d!", pDlg->m_enviado);
      pDlg->m_list.AddString(cs2);
      pDlg->PostMessage(WM_MSG_HILO,1);
      while(pDlg->m_enviado != 0);
    }
  }
	return 0;
}

LRESULT CEntregableSensoresDlg::funcion(WPARAM wParam, LPARAM lParam){
  if(wParam == 1){
    m_recibido++;
  }
  if (m_recibido >= m_threads.size() - 1){
    m_recibido = 0;
    m_enviado = 0;
    for(size_t ii = 0; ii < m_threads.size(); ii++){
      m_threads.at(ii)->ResumeThread();
    }
    m_list.AddString("");
  }
  return 0;
}

void CEntregableSensoresDlg::OnSelchangeCbnodes()
{
	m_active = false;
	std::vector<CWinThread*> tmp;
	m_threads = tmp;
	m_id = 1;
	CString selection;
	m_comboNodes.GetLBText(m_comboNodes.GetCurSel(), selection);
	char selection2[10];
	strcpy(selection2, (LPCTSTR)selection );
	m_active = true;
	for(int ii = 0; ii < selection2[0]-48; ii++){
		m_threads.push_back(AfxBeginThread(NodoGeneral, this));
	}
	int a = m_comboNodes2.GetCount();
	for(int ii = m_comboNodes2.GetCount() - 1; ii >= 0; ii--){
		m_comboNodes2.DeleteString(ii);
	}
	for(int ii = 0; ii < selection2[0] - 48; ii++){
		CString cs;
		cs.Format("%d", ii + 1);
		m_comboNodes2.AddString(cs);
	}
	m_comboNodes2.SetCurSel(0);
}


void CEntregableSensoresDlg::OnBnClickedbnsend()
{
	CString selection;
	m_comboNodes2.GetLBText(m_comboNodes2.GetCurSel(), selection);
	char selection2[10];
	strcpy(selection2, (LPCTSTR)selection );
	m_threads.at(selection2[0]-49)->SuspendThread();
	CString cs;
	cs.Format("Nodo %d Enviando.............................", selection2[0] - 48);
	m_list.AddString(cs);
  m_enviado = selection2[0] - 48;
}
