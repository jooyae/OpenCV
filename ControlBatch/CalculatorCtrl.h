#pragma once
#include "afxwin.h"


// CCalculatorCtrl ��ȭ �����Դϴ�.

class CCalculatorCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CCalculatorCtrl)

public:
	CCalculatorCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCalculatorCtrl();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CALCULATOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
