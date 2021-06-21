// CalculatorPane.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Practice5_04.h"
#include "CalculatorPane.h"


// CCalculatorPane

IMPLEMENT_DYNAMIC(CCalculatorPane, CDockablePane)

CCalculatorPane::CCalculatorPane()
{

}

CCalculatorPane::~CCalculatorPane()
{
}


BEGIN_MESSAGE_MAP(CCalculatorPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CCalculatorPane �޽��� ó�����Դϴ�.




int CCalculatorPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if (!m_ctrlCalculator.Create(IDD_DIALOG_CALCULATOR, this))
	{
		TRACE0("���ڿ� ��� �����츦 ������ ���߽��ϴ�.\n");
		return -1;
	}
	m_ctrlCalculator.ShowWindow(SW_SHOW);
	return 0;

}


void CCalculatorPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlCalculator.GetSafeHwnd())
	{
		m_ctrlCalculator.MoveWindow(0, 0, cx, cy);
		m_ctrlCalculator.SetFocus();
	}
}
