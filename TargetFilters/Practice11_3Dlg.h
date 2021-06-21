
// Practice11_3Dlg.h : 헤더 파일
//

#pragma once
//#include "C:\Users\8306\Documents\Visual Studio 2015\Projects\RootDll\CalculateRoot.h"

#include "CalculateRoot.h"

// CPractice11_3Dlg 대화 상자
class CPractice11_3Dlg : public CDialogEx
{
// 생성입니다.
public:
	CPractice11_3Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICE11_3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CCalculateRoot m_calcRoot;
	afx_msg void OnClickedButtonCalcRoot();
	afx_msg void OnClickedButtonClear();
};
