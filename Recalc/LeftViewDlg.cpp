// LeftViewDlg.cpp : 구현 파일입니다.
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


// CLeftViewDlg 진단입니다.

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


// CLeftViewDlg 메시지 처리기입니다.


void CLeftViewDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
}


void CLeftViewDlg::OnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
		AfxMessageBox(_T("입력 노드의 텍스트를 입력하세요."));
	}
	m_strNodeText.Empty();
	UpdateData(FALSE);

}


void CLeftViewDlg::OnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
			AfxMessageBox(_T("루트 노드는 삭제해서는 안됩니다."));
		}
		
	}
	else {
		AfxMessageBox(_T("입력 노드의 텍스트를 입력하세요."));
	}
	m_strNodeText.Empty();
	UpdateData(FALSE);

}


void CLeftViewDlg::OnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CExercise10_1View *pView = (CExercise10_1View*) this->GetNextWindow();

	
		if (pView->m_hSelectedNode != pView->m_hRoot)
		{
			if (AfxMessageBox(_T("정말 삭제하시겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
				pView->GetTreeCtrl().DeleteItem(pView->m_hSelectedNode);
		

	}
	else {
		AfxMessageBox(_T("루트 노드는 삭제해서는 안됩니다."));
	}
}


void CLeftViewDlg::OnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CExercise10_1View *pView = (CExercise10_1View*) this->GetNextWindow();
	m_bChecked = !m_bChecked;
	pView->GetTreeCtrl().Expand(pView->m_hRoot, TVE_TOGGLE);
}
