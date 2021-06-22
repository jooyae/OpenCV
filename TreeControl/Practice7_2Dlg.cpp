
// Practice7_2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Practice7_2.h"
#include "Practice7_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CPractice7_2Dlg ��ȭ ����



CPractice7_2Dlg::CPractice7_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRACTICE7_2_DIALOG, pParent)
	, m_strSelectedNode(_T(""))
	, m_strNodeText(_T(""))
	, m_bChecked(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPractice7_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_CONTROL, m_treeControl);
	DDX_Text(pDX, IDC_EDIT_SELECTED_NODE, m_strSelectedNode);
	DDX_Text(pDX, IDC_EDIT_NODE_TEXT, m_strNodeText);
}

BEGIN_MESSAGE_MAP(CPractice7_2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON3, &CPractice7_2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK_EXPAND, &CPractice7_2Dlg::OnBnClickedCheckExpand)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_CONTROL, &CPractice7_2Dlg::OnSelchangedTreeControl)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CPractice7_2Dlg::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CPractice7_2Dlg::OnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CPractice7_2Dlg::OnClickedButtonDelete)
	ON_NOTIFY(BCN_DROPDOWN, IDC_CHECK_EXPAND, &CPractice7_2Dlg::OnDropdownCheckExpand)
END_MESSAGE_MAP()


// CPractice7_2Dlg �޽��� ó����

BOOL CPractice7_2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_hRoot = m_treeControl.InsertItem(_T("��Ʈ ���"), 0, TVI_LAST);
	((CButton*)GetDlgItem(IDC_CHECK_EXPAND))->SetCheck(TRUE);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CPractice7_2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CPractice7_2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CPractice7_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CPractice7_2Dlg::OnBnClickedCheckExpand()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CPractice7_2Dlg::OnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_hSelectedNode = pNMTreeView->itemNew.hItem;

	m_strSelectedNode = m_treeControl.GetItemText(m_hSelectedNode);
	UpdateData(FALSE);
	*pResult = 0;
}


void CPractice7_2Dlg::OnClickedButtonInsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (!m_strNodeText.IsEmpty())
	{
		m_treeControl.InsertItem(m_strNodeText, m_hSelectedNode, TVI_LAST);
		m_treeControl.Expand(m_hSelectedNode, TVE_EXPAND);
	}
	else {
		AfxMessageBox(_T("�Է� ����� �ؽ�Ʈ�� �Է��ϼ���."));
	}

	m_strNodeText.Empty();
	UpdateData(FALSE);
}


void CPractice7_2Dlg::OnClickedButtonModify()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (!m_strNodeText.IsEmpty())
	{
		if (m_hSelectedNode != m_hRoot)
		{
			m_treeControl.SetItemText(m_hSelectedNode, m_strNodeText);
			m_strSelectedNode = m_strNodeText;
		}


		else {
			AfxMessageBox(_T("��Ʈ ���� �����ؼ��� �ȵ˴ϴ�."));
		}
	}
	else {
		AfxMessageBox(_T("���� ����� �ؽ�Ʈ�� �Է��ϼ���."));
	}


	m_strNodeText.Empty();
	UpdateData(FALSE);

}


void CPractice7_2Dlg::OnClickedButtonDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_hSelectedNode != m_hRoot)
	{
		if(MessageBox(_T("���� �����Ͻðڽ��ϱ�?"),_T("���� ���"),MB_YESNO)==IDYES)
		m_treeControl.DeleteItem(m_hSelectedNode);
	}
	else {
		AfxMessageBox(_T("��Ʈ ���� �����ؼ��� �ȵ˴ϴ�."));
	}

}


void CPractice7_2Dlg::OnDropdownCheckExpand(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMBCDROPDOWN pDropDown = reinterpret_cast<LPNMBCDROPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bChecked = !m_bChecked;
	m_treeControl.Expand(m_hRoot, TVE_TOGGLE);
	m_hSelectedNode = m_hRoot;
	m_strSelectedNode = _T("��Ʈ ���");
	UpdateData(FALSE);
	*pResult = 0;
}
