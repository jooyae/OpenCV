// LeftViewDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Exercise10_1.h"
#include "LeftViewDlg.h"
#include "Exercise10_1Doc.h"
#include "Exercise10_1View.h"


// CLeftViewDlg

IMPLEMENT_DYNCREATE(CLeftViewDlg, CFormView)

CLeftViewDlg::CLeftViewDlg()
	: CFormView(IDD_FORMVIEW)
	, m_strNodeText(_T(""))
	, m_strSelectedNode(_T(""))
	, m_bChecked(false)
{

}

CLeftViewDlg::~CLeftViewDlg()
{
}

void CLeftViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NODETEXT, m_strNodeText);
	DDX_Text(pDX, IDC_EDIT_SELECTEDNODE, m_strSelectedNode);
}

BEGIN_MESSAGE_MAP(CLeftViewDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CLeftViewDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLeftViewDlg::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CLeftViewDlg::OnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK1, &CLeftViewDlg::OnClickedCheck1)
END_MESSAGE_MAP()


// CLeftViewDlg �����Դϴ�.

#ifdef _DEBUG
void CLeftViewDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftViewDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftViewDlg �޽��� ó�����Դϴ�.


void CLeftViewDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	
}


void CLeftViewDlg::OnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CExercise10_1View *pView = (CExercise10_1View*) this->GetNextWindow();
	TV_INSERTSTRUCT tvStruct;
	UpdateData(TRUE);
	
	if (!m_strNodeText.IsEmpty())
	{
		tvStruct.hParent = pView->m_hSelectedNode;
		tvStruct.hInsertAfter = TVI_LAST;
		tvStruct.item.mask = TVIF_TEXT;
		tvStruct.item.pszText = (LPWSTR)(LPCTSTR)m_strNodeText;

		pView->GetTreeCtrl().InsertItem(&tvStruct);
		pView->GetTreeCtrl().Expand(pView->m_hSelectedNode, TVE_EXPAND);
	}
	else {
		AfxMessageBox(_T("�Է� ����� �ؽ�Ʈ�� �Է��ϼ���."));
	}
	m_strNodeText.Empty();
	UpdateData(FALSE);

}


void CLeftViewDlg::OnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CExercise10_1View *pView = (CExercise10_1View*) this->GetNextWindow();
	
	UpdateData(TRUE);

	if (!m_strNodeText.IsEmpty())
	{
		if (pView->m_hSelectedNode != pView->m_hRoot)
		{
			pView->GetTreeCtrl().SetItemText(pView->m_hSelectedNode, m_strNodeText);
			m_strSelectedNode = m_strNodeText;
		}
		else {
			AfxMessageBox(_T("��Ʈ ���� �����ؼ��� �ȵ˴ϴ�."));
		}
		
	}
	else {
		AfxMessageBox(_T("�Է� ����� �ؽ�Ʈ�� �Է��ϼ���."));
	}
	m_strNodeText.Empty();
	UpdateData(FALSE);

}


void CLeftViewDlg::OnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CExercise10_1View *pView = (CExercise10_1View*) this->GetNextWindow();

	
		if (pView->m_hSelectedNode != pView->m_hRoot)
		{
			if (AfxMessageBox(_T("���� �����Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
				pView->GetTreeCtrl().DeleteItem(pView->m_hSelectedNode);
		

	}
	else {
		AfxMessageBox(_T("��Ʈ ���� �����ؼ��� �ȵ˴ϴ�."));
	}
}


void CLeftViewDlg::OnClickedCheck1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CExercise10_1View *pView = (CExercise10_1View*) this->GetNextWindow();
	m_bChecked = !m_bChecked;
	pView->GetTreeCtrl().Expand(pView->m_hRoot, TVE_TOGGLE);
}
