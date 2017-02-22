#pragma once


// CCirculo

class CCirculo : public CWnd
{
	DECLARE_DYNAMIC(CCirculo)

public:
	CCirculo();
	virtual ~CCirculo();

protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnPaint();
  CBrush pens[2];
  bool option;
};


