// CalculatorCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Practice5_04.h"
#include "CalculatorCtrl.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Practice5_04Doc.h"
#include "Practice5_04View.h"


// CCalculatorCtrl ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCalculatorCtrl, CDialogEx)

CCalculatorCtrl::CCalculatorCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CALCULATOR, pParent)
	, m_nNumber(0)
	
{

}

CCalculatorCtrl::~CCalculatorCtrl()
{
}

void CCalculatorCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_edNumber);
	//  DDX_Text(pDX, IDC_EDIT2, m_edNumbert);
	//  DDX_Control(pDX, IDC_EDIT1, m_edNumber);
	//  DDX_Control(pDX, IDC_EDIT2, m_edNumbert);
}


BEGIN_MESSAGE_MAP(CCalculatorCtrl, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorCtrl::OnClickedButton1)
	ON_COMMAND(IDC_RADIO1, &CCalculatorCtrl::OnRadio1)
	ON_COMMAND(IDC_RADIO2, &CCalculatorCtrl::OnRadio2)
END_MESSAGE_MAP()


// CCalculatorCtrl �޽��� ó�����Դϴ�.


void CCalculatorCtrl::OnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame*) AfxGetMainWnd();
	CPractice5_04View* pView = (CPractice5_04View*)pFrame->GetActiveView();
	UpdateData(TRUE);
	int m_edNumber;
	//pView->m_edNumber += (_T(" 1 "));
	//pView->m_nNumber += m_nNumber;


	
}


void CCalculatorCtrl::OnRadio1()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData();

}


void CCalculatorCtrl::OnRadio2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData();
}
