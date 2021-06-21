#pragma once
#include "afxwin.h"


// CCalculatorCtrl 대화 상자입니다.

class CCalculatorCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CCalculatorCtrl)

public:
	CCalculatorCtrl(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCalculatorCtrl();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CALCULATOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nNumber;
	afx_msg void OnClickedButton1();
//	int m_edNumber;
//	int m_edNumbert;
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
//	CEdit m_edNumber;
//	CEdit m_edNumbert;
};
