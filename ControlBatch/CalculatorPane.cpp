// CalculatorPane.cpp : 구현 파일입니다.
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



// CCalculatorPane 메시지 처리기입니다.




int CCalculatorPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if (!m_ctrlCalculator.Create(IDD_DIALOG_CALCULATOR, this))
	{
		TRACE0("문자열 출력 윈도우를 만들지 못했습니다.\n");
		return -1;
	}
	m_ctrlCalculator.ShowWindow(SW_SHOW);
	return 0;

}


void CCalculatorPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_ctrlCalculator.GetSafeHwnd())
	{
		m_ctrlCalculator.MoveWindow(0, 0, cx, cy);
		m_ctrlCalculator.SetFocus();
	}
}
