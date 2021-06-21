#pragma once
#include "CalculatorCtrl.h"


// CCalculatorPane

class CCalculatorPane : public CDockablePane
{
	DECLARE_DYNAMIC(CCalculatorPane)

public:
	CCalculatorPane();
	virtual ~CCalculatorPane();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CCalculatorCtrl m_ctrlCalculator;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


