#pragma once


// CLleno

class CLleno : public CWnd
{
	DECLARE_DYNAMIC(CLleno)

public:
	CLleno();
	virtual ~CLleno();

protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnPaint();
  int m_height;
  int m_altura;
};


