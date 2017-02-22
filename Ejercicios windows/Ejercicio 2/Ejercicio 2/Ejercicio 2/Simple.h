class CMiApp :public CWinApp
{
public: //sobrecargar InitInstance
  BOOL InitInstance();
};
class CMiVentana :public CFrameWnd
{
private:
  int m_cont;
  CPoint m_point;
  int m_x1, m_x2, m_y1, m_y2;
public:
  int Amp, w, frec;
  CMiVentana(char *);//constructor
  CButton miBoton, btSetTimer, btKillTimer;
  DECLARE_MESSAGE_MAP()
  void Salir();
  void OnMouseMove(UINT nFlags, CPoint point);
  void OnTimer(UINT_PTR nIDEvent);
  void fnSetTimer();
  void fnKillTimer();
  void OnPaint();
};
