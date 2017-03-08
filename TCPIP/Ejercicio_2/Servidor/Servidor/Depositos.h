#pragma once


// CDepositos

class CDepositos : public CWnd
{
	DECLARE_DYNAMIC(CDepositos)

public:
	CDepositos();
	virtual ~CDepositos();
	int m_nivel;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


