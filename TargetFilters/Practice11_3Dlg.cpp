
// Practice11_3Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Practice11_3.h"
#include "Practice11_3Dlg.h"
#include "afxdialogex.h"

#include "CalculateRoot.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPractice11_3Dlg 대화 상자



CPractice11_3Dlg::CPractice11_3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRACTICE11_3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPractice11_3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPractice11_3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CALC_ROOT, &CPractice11_3Dlg::OnClickedButtonCalcRoot)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CPractice11_3Dlg::OnClickedButtonClear)
END_MESSAGE_MAP()


// CPractice11_3Dlg 메시지 처리기

BOOL CPractice11_3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPractice11_3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPractice11_3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CPractice11_3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPractice11_3Dlg::OnClickedButtonCalcRoot()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strTemp;
	double fA, fB, fC, fDet;
	GetDlgItemText(IDC_EDIT_A, strTemp);
	fA = _wtof(strTemp);
	if (fA == 0)
	{
		AfxMessageBox(_T("첫번째 계수는 0이 될 수 없습니다."));
		SetDlgItemText(IDC_EDIT_A, _T(""));
		SetDlgItemText(IDC_EDIT_B, _T(""));
		SetDlgItemText(IDC_EDIT_C, _T(""));
	}
	else
	{
		GetDlgItemText(IDC_EDIT_B, strTemp);
		fB = _wtof(strTemp);
		GetDlgItemText(IDC_EDIT_C, strTemp);
		fC = _wtof(strTemp);
		int nDet = m_calcRoot.Determinant(fA, fB, fC, &fDet);
		strTemp.Format(_T("%g"), fDet);
		switch (nDet)
		{
		case 0:
			SetDlgItemText(IDC_EDIT_RESULT, _T("근이 없다."));
			SetDlgItemText(IDC_EDIT_DETERMINANT, strTemp);
			SetDlgItemText(IDC_EDIT_ROOT1, _T(""));
			SetDlgItemText(IDC_EDIT_ROOT2, _T(""));
			break;
		case 1:
			SetDlgItemText(IDC_EDIT_RESULT, _T("중근"));
			SetDlgItemText(IDC_EDIT_DETERMINANT, strTemp);
			strTemp.Format(_T("%g"), m_calcRoot.CalcRoot1(fA, fB, fC));
			SetDlgItemText(IDC_EDIT_ROOT1, strTemp);
			strTemp.Format(_T("%g"), m_calcRoot.CalcRoot2(fA, fB, fC));
			SetDlgItemText(IDC_EDIT_ROOT2, strTemp);
			break;
		case 2:
			SetDlgItemText(IDC_EDIT_RESULT, _T("2개의 근이 존재"));
			SetDlgItemText(IDC_EDIT_DETERMINANT, strTemp);
			strTemp.Format(_T("%g"), m_calcRoot.CalcRoot1(fA, fB, fC));
			SetDlgItemText(IDC_EDIT_ROOT1, strTemp);
			strTemp.Format(_T("%g"), m_calcRoot.CalcRoot2(fA, fB, fC));
			SetDlgItemText(IDC_EDIT_ROOT2, strTemp);
			break;
		}
	}
}


void CPractice11_3Dlg::OnClickedButtonClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT_A, _T(""));
	SetDlgItemText(IDC_EDIT_B, _T(""));
	SetDlgItemText(IDC_EDIT_C, _T(""));
	SetDlgItemText(IDC_EDIT_RESULT, _T(""));
	SetDlgItemText(IDC_EDIT_DETERMINANT, _T(""));
	SetDlgItemText(IDC_EDIT_ROOT1, _T(""));
	SetDlgItemText(IDC_EDIT_ROOT2, _T(""));
}
