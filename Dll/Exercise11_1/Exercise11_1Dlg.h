
// Exercise11_1Dlg.h : ��� ����
//

#pragma once

#include "CalculateRoot.h"
#include "C:\Users\8306\Documents\Visual Studio 2015\Projects\Exercise11_1\RootDll\CalculateRoot.h"


// CExercise11_1Dlg ��ȭ ����
class CExercise11_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CExercise11_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXERCISE11_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton7();
	CCalculateRoot m_calcRoot;
	afx_msg void OnClickedButton4();
	afx_msg void OnClickedButton16();
	afx_msg void OnRadio1();
};
