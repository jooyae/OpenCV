
// Practice11_1Dlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CPractice11_1Dlg 대화 상자
class CPractice11_1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CPractice11_1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICE11_1_DIALOG };
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
	int m_nYear;
	CSpinButtonCtrl m_spinYear;
	CComboBox m_cbMonth;
	int m_nMonth;
	afx_msg void OnSelchangeComboMonth();
	afx_msg void OnDeltaposSpinYear(NMHDR *pNMHDR, LRESULT *pResult);
};
